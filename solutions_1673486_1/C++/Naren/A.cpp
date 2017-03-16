#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,n-1,0)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define INF (int)1<<30
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define mkp make_pair
#define ll unsigned long long int
#define uli unsigned long int
#define MAX (int)1e6

using namespace std;

//ifstream fin ("A.in");
//#ofstream fout ("A.out");
//#define cin fin
//#define cout fout

double p[100001], success[100001];

int main() {
    int t;
    cin>>t;
    REP(T,t) {
        int A,B;
        cin>>A>>B;
        success[0] = 1.0;
        REP(i,A) {
            cin>>p[i+1];
            success[i+1] = success[i] * p[i+1];
        }
        double ans = B+2;
        
        REP(i, A+1) {
            double k = success[A - i] * (B - A + 1 + 2*i) + (1.0 - success[A - i]) * (B - A + 1 + B + 1 + 2*i); 
            ans = k < ans ? k : ans;
        }
        
        printf("Case #%d: %.6lf\n",T+1,ans); 
    }
    return 0;
}
