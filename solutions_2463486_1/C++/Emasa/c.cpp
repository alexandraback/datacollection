// C++ libraries
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <typeinfo> // for badcast

// C libraries
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>

using namespace std;

// TYPES
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ld;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii; 

// CONSTANTS
const double PI=acos(-1.0);
const double EPS=1e-11;
#define INF 2000000000

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); k++)
#define REP(k,a) for(unsigned int k=0; k < (a); ++k)
#define all(c) (c).begin(), (c).end()  
#define pb push_back 
#define mp make_pair 
#define pbp(x, y) pb(mp(x,y))
#define sz(a) int((a).size()) 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)  //iterate a container
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define pow2(X) (1<<(X))
#define pow2L(X) (((int64)(1))<<(X))

// for debug
#define WATCH(x) {cout<<__FILE__<<":"<<__LINE__<<":WATCHING:"<<#x<<": ";tr(x, it){cout<<*it<<", ";}cout<<endl;}
#define PEEK(x) {cout<<#x<<"="<<x;}

#define READCases int cases, cs; cin >> cases; REP(cs, cases)
#define PRINTSolution(res) cout << "Case #" << cs+1 << ": " << (res) << endl;

// Maths
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
  
//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase

// funcion para convertir de un tipo In a otro Out
template<typename Out, typename In> Out lexical_cast(In input) {
    stringstream ss; ss << input;
    Out r;
    if ((ss >> r).fail() || !(ss >> std::ws).eof()) throw std::bad_cast();
    return r;
}

bool isPalindromic(int64 n) {
    string str_n = lexical_cast<string>(n);        
    string::size_type i = 0, j = str_n.size() - 1; 
    while (i < j) {
        if (str_n[i] != str_n[j]) return false;
        i++; j--;
    }
    return true;
}

vector<int64> square_and_palindromic(int64 limit)
{
    set<int64> res = {1};
    if (4 <= limit) res.insert(4);
    if (9 <= limit) res.insert(9);
    
    for (int64 i=1; /* no condition */ ; ++i) {
        string fst_half = lexical_cast<string>(i);
        string snd_half(fst_half);
        reverse(all(snd_half));
        
        int64 candidate = sqr( lexical_cast<int64>(fst_half + snd_half) );
        if (candidate <= limit) {
            if (isPalindromic(candidate)) res.insert(candidate);
        } else return vector<int64>(all(res));
         
        for (char c = '0'; c <= '9'; ++c) {
            candidate = sqr( lexical_cast<int64>(fst_half + c + snd_half) );
            if (candidate <= limit && isPalindromic(candidate)) res.insert(candidate);
        }
    }
    return vector<int64>(all(res));
}

int main()
{   
    int64 limit = 1e+14;
    vector<int64> numbers = square_and_palindromic(limit);
    
    READCases {
        int64 A, B;
        cin >> A >> B;
        PRINTSolution(upper_bound(all(numbers), B) - lower_bound(all(numbers), A));
    }
    
    return 0;
}
