#define DEBUG 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-10;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif
//Utility function to reverse a number
//If input = 57293, Output = 39275
//If input = 127200, Output = 2721
long long reverse_number(long long num)
{
    long long rev = 0;
    while(true) {
        rev = (rev*10) + (num%10);
        num = num/10;
        if (num == 0) { break;}    
    }
    return rev;
}
//Utility function to convert a number into a bit array
// Param: bit_array --> pointer to an empty vector where result is stored and returned.

// If input is (num = 3, num_bits = 4) ---> output in vectory array = {0,0,1,1}
void convert_num_to_bits(long long num, int num_bits, vector<int> *bit_array)
{
    vector<int> temp;
    int i;
    while(true) {
        temp.push_back(num%2);                                                       
        num = num/2; 
        if (num == 0) { break;}                                                          
    }
    assert(temp.size() <= num_bits);
    Fox(i, num_bits-temp.size()) { bit_array->push_back(0);}
    Fox(i, temp.size()) {bit_array->push_back(temp[temp.size()-1-i]);}
}


void solve(int casenum)
{
    string line;
    int i, j, k, l;
    int R, C, W;
    cin >> R >> C >> W;
    int num_turns = 0;
    if (W == C) {
        cout << "Case #" << casenum << ": " <<C<< endl;
        return;
    }
    /*for (i = 1; i <= C; i = i+W) {
        num_turns++;
        if (i + W > C) { break;} 
    }
    if (C-1-W > i-W) { num_turns++;}
    num_turns = num_turns + W-1;
    */
    while(true) {
    if (W <= C/2) {num_turns++; C = C-W;}
    if (W == C) { num_turns+= W;break;}
    if (W > C/2) {
            num_turns+=W+1; break;
        } 
    }
    cout << "Case #" << casenum << ": " << num_turns << endl;    
}

int main()
{
    int num_cases;
    string line;
    getline(cin,line);
    stringstream ss;
    ss << line;
    ss >> num_cases;
    for (int i = 0; i < num_cases; i++) {
        solve(i+1);
    }   
	return(0);
}
