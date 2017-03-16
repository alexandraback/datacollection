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

int dfs(vector<vector<int>> &abff, int w, vector<bool> &visited){
    visited[w] = true;
    int score = 0;
    for(int v: abff[w]){
        if(!visited[v]){
            score = max(score,dfs(abff, v, visited));
        }
    }
    return 1 + score;
}

#undef int
int main() {
#define int long long
    int t;
    cin>>t;
    REP(q,t){
        int n;
        cin>>n;
        vector<int> bff(n);
        vector<vector<int>> abff(n);
        REP(i, n){
            cin>>bff[i];
            bff[i]--;
            abff[bff[i]].PB(i);
        }
        set<int>s;
        int result = 0;
        int proste = 0;
        REP(i, n){
            set<int> used;
            int person = i;
            while(!used.count(person)){
                used.insert(person);
                person = bff[person];
            }
            if(person == i){
                result = max(result, (int)used.size());
            }
        }
        vector<bool> visited(n);

        REP(i, n){
            if(!visited[i] && bff[bff[i]] == i){
                visited[i] = true;
                visited[bff[i]] = true;
                int a = dfs(abff, i, visited);
                int b = dfs(abff, bff[i], visited);
                proste += a;
                proste += b;

            }
        }
        cout<<"Case #"<<q + 1<<": "<<max(result, proste)<<endl;
    }

    return 0;
}
