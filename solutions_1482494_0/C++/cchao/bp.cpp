#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
#define PCS cout << "Case #" << i << ": "
typedef long long ll;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;
}
int main(){
    int tt;
    cin >> tt;
    FORE(i,1,tt){
        vector<pair<int,int> > g(1010);
        int vis[1010][2]={{0}};
        int star=0,com=0;
        int n;
        cin >> n;
        for(int k=0;k<n;k++){
            cin >> g[k].first >> g[k].second;
        }
        int cnt=0,ans=1,d=0;
        sort(g.begin(),g.end(),cmp);
        while(com<n){
            //cout << cnt << ' ' << star << ' ' << com << endl;
            cnt++;
            int loop=1;
            for(int k=0;k<n;k++){
                if(star>=g[k].second && vis[k][1]==0){
                    vis[k][1]=1;
                    if(vis[k][0]==1) star++;
                    else star+=2;
                    loop=0;
                    d++;
                    com++;
                    break;
                }
            }
            if(loop==0) continue;
            for(int k=0;k<n;k++){
                if(star>=g[k].first && vis[k][0]==0 && vis[k][1]==0){
                    vis[k][0]=1;
                    star++;
                    d++;
                    break;
                }
            }
            if(cnt > 2*n+2){
                ans=0;
                break;
            }
        }
        PCS;
        if(ans==0) cout << "Too Bad" << endl;
        else cout << d << endl;
    }
    return 0;
}
