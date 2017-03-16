#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include "prettyprint.h"
#include <deque>
#include <fstream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define M_PI 3.14159265358979323846
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define LD long double
#define INF 1000000000
#define int long long
//Begin of the code
bool fits(vector<int> &t, vector<int> &g){
    REP(i, t.size()){
        if(t[i] != g[i]){
            return false;
        }
    }
    return true;
}

#undef int
int main() {
#define int long long
    int t;
    cin>>t;
    REP(q,t){
        int n;
        cin>>n;
        vector<bool> del(2 * n - 1);
        map<int,int> nums;
        REP(i,2*n - 1){
            vector<int> inp(n);
            REP(j,n){
                cin>>inp[j];
                nums[inp[j]]++;
            }
        }
        vector<int> res;
        for(pair<int,int> p: nums){
            if(p.ND & 1){
                res.PB(p.ST);
            }
        }
        cout<<"Case #"<<q + 1<<": ";
        REP(i, res.size()){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
