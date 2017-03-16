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


void solve(int casenum)
{
    string line;
    int i, j, k, l, i1;
    int N;
    cin >> N;
    int num_hikers = 0;
    int start_pos[10];
    int time_revol[10];
    Fox (i,N) {
        cin >> j;
        cin >> k;
        cin >> l;
        Fox(i1, k) {
            start_pos[num_hikers + i1] = j;
            time_revol[num_hikers + i1] = l+i1;
        }
        num_hikers += k;
    }
    
    //cout << "Num hikers = " << num_hikers << endl; 
    if (num_hikers == 1) {
        cout << "Case #" << casenum << ": 0" << endl;    
    } else if (num_hikers == 2) {
        if (start_pos[1] < start_pos[0]) {
            int temp;
            temp = start_pos[1];
            start_pos[1] = start_pos[0];
            start_pos[0] = temp;
            temp = time_revol[1];
            time_revol[1] = time_revol[0];
            time_revol[0] = temp;
        } 

        if (time_revol[0] < time_revol[1]) {
            float second_time = ((360.0 - (float)start_pos[1])/360.0)*(float)time_revol[1];
            float first_time = ((360.0 - (float)start_pos[0])/360.0)*(float)time_revol[0]; 
            if (second_time < first_time) {
                cout << "Case #" << casenum << ": 0" << endl;
            } else if (second_time < first_time + time_revol[0])  {
                cout << "Case #" << casenum << ": 0" << endl;
            } else {
                cout << "Case #" << casenum << ": 1" << endl;
            }
        }
        else {
            float second_time = ((360.0 - (float)start_pos[1])/360.0)*(float)time_revol[1];
            float first_time = ((360.0 - (float)start_pos[0])/360.0)*(float)time_revol[0]; 
            if (first_time < second_time + time_revol[1]) {
                cout << "Case #" << casenum << ": 0" << endl;
            }else {
                cout << "Case #" << casenum << ": 1" << endl;
            }
            
        }
    }
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
