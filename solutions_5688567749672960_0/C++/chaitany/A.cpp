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

int global_arr[1000001];

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
void solve(int casenum)
{
    string line;
    int i, j, k, l;
    long long num;
    cin >> num;
    long long run_number = 1;
    long long count = 0; 
    /*while (true) {
        if (run_number == num) {count++; break;}
        long long rev = reverse_number(run_number);
        if (rev > run_number + 1) { run_number = rev; count++;}
        else {run_number++; count++;}
    }*/
    cout << "Case #" << casenum << ": " << global_arr[num] << endl;
}

int main()
{
    int num_cases;
    string line;
    getline(cin,line);
    stringstream ss;
    ss << line;
    ss >> num_cases;
    int i;
    Fox1(i,1000000)
    {
        global_arr[i] = i;
    }
    for (i = 1000000; i <=1; i--)
    {
        int rev = reverse_number(i);
        if (i%10 != 0 && global_arr[rev] < global_arr[i]) { global_arr[i] = global_arr[rev] + 1;}
    }
    Fox1(i,1000000)
    {
        int rev = reverse_number(i);
        if (i%10 != 0 && global_arr[rev] < global_arr[i]) { global_arr[i] = global_arr[rev] + 1;}
        if (i!= 1 && global_arr[i-1] < global_arr[i]) { global_arr[i] = global_arr[i-1] + 1;}
    }

    for (int i = 0; i < num_cases; i++) {
        solve(i+1);
    }   
	return(0);
}
