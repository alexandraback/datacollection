/*
 * =====================================================================================
 *
 *       Filename: C
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016-05-08-16.43.19, Sunday
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:
 *
 *   ________                          ___.
 *  /  _____/_____   __ ______________ \_ |__
 * /   \  ___\__  \ |  |  \_  __ \__  \ | __ \
 * \    \_\  \/ __ \|  |  /|  | \// __ \| \_\ \
 *  \______  (____  /____/ |__|  (____  /___  /
 *         \/     \/                  \/    \/
 *
 *   Organization:  Shahjalal University of Science and Technology
 *
 * =====================================================================================
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<Long, Long> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<DD> VD;
typedef vector<Long> VL;
typedef vector<VL> VVL;

const int INF = 2000000000;
const int MOD = 1000000007;
const Long L_MAX = 9223372036854775807;
const int I_MAX = 2147483647;


#define sf scanf
#define pf printf
#define mem(a,b)          memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b)        for(int i=a; i<=b; ++i)
#define REPI(i,a,b,c)     for(int i=a; i<=b; i+=c)
#define REPR(i,a,b)       for(int i=b; i>=a; --i)
#define REPRD(i,a,b,c)    for(int i=b; i>=a; i-=c)
#define REPB(i,a)         for(int i=a; ;i++)
#define REPRB(i,a)        for(int i=a; ; i--)
#define mp(a,b)   make_pair(a,b)
#define fs        first
#define sc        second
#define SZ(s)     ((int)s.size())
#define PI        3.141592653589793
#define lim       1007
#define tlim      (1<<((int)ceil(log2(lim))+1))
#define unq(vec)  stable_sort(vec.begin(),vec.end());\
				  vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)     a.begin(),a.end()
#define rev(a)    reverse(BE(a))
#define sorta(a)  stable_sort(BE(a))
#define sortc(a, comp)  sort(BE(a),comp)

//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};//4 move
int jj,pp,ss,kk;

vector<pair<pair<int,int>,int> > v,ans;
bool vis[1000006];

map<pair<int,int>,int> jp,ps,js;

void REC(int ii) {
    if(ii==(int)v.size()) {
        int cnt=0;
        for(int i=0; i<(int)v.size(); i++) {
            if(vis[i])cnt++;
        }
        if((int)ans.size()<cnt) {
            ans.clear();
            for(int i=0; i<(int)v.size(); i++) {
                if(vis[i])ans.push_back(v[i]);
            }
        }
        return;
    }
    REC(ii+1);
    int a=v[ii].first.first;
    int b=v[ii].first.second;
    int c=v[ii].second;
    if(jp[ {a,b}]<kk && ps[ {b,c}]<kk && js[ {a,c}]<kk) {
        jp[ {a,b}]++;
        ps[ {b,c}]++;
        js[ {a,c}]++;
        vis[ii]=1;
        REC(ii+1);
        jp[ {a,b}]--;
        ps[ {b,c}]--;
        js[ {a,c}]--;
        vis[ii]=0;
    }
    return;
}

int main(int argc, const char **argv) {
    //ios::sync_with_stdio(false);
    freopen("D:\\Projects\\GitRepo\\CodeRepo\\working\\Round 1C 2016\\C-small-attempt0.in","r",stdin);
    freopen("D:\\Projects\\GitRepo\\CodeRepo\\working\\Round 1C 2016\\C-small-attempt0.out","w",stdout);
    //double st=clock(),en;
    int Test;
    cin>>Test;
    REP(kase,1,Test) {
        cin>>jj>>pp>>ss>>kk;
        memset(vis,0,sizeof(vis));
        jp.clear();
        js.clear();
        ps.clear();
        v.clear();
        ans.clear();
        REP(i,0,(jj-1)) {
            REP(j,0,(pp-1)) {
                REP(k,0,(ss-1)) {
                    v.pb( {{i,j},k});
                }
            }
        }
        if(ss<=kk) {
            ans=v;
            cout<<"Case #"<<kase<<": "<<SZ(ans)<<"\n";
            REP(i,0,(SZ(ans)-1)) {
                cout<<ans[i].first.first+1<<" "<<ans[i].first.second+1<<" "<<ans[i].second+1<<"\n";
            }
            continue;
        }
        REC(0);
        cout<<"Case #"<<kase<<": "<<SZ(ans)<<"\n";
        REP(i,0,(SZ(ans)-1)) {
            cout<<ans[i].first.first+1<<" "<<ans[i].first.second+1<<" "<<ans[i].second+1<<"\n";
        }
    }

    //en=clock();
    //cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}



