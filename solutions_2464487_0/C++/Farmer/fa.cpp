/*
 *Author:       Zhaofa Fang
 *Created time: 2013-04-27-08.54
 *Language:     C++
 */
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)

int r,t;
bool check(double m){
    //DEBUG(m);DEBUG(2*m*m+(2*r-1)*m);DEBUG(t);
    if(2*m*m+(2*r-1)*m-t<=0)return true;
    else return false;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;
	cin>>T;
	FOR(cas,1,T){
        cin>>r>>t;
        int ans = 0;
        int le = 0,ri = (int)sqrt((t+10.0)/2.0);
        while(le <= ri){
            int m = (le +ri)/2;
            if(check(m))le = m + 1,ans = m;
            else ri = m - 1;
            //DEBUG(ans);
        }
        printf("Case #%d: ",cas);
        cout<<ans<<endl;
	}
	return 0;
}
