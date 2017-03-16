#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<bitset>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;

int T,ans,n,cnt,c1,c2,ask1[3000],ask2[3000];
string s1,s2;
map<string,int> mp;

struct point{
    int x,y;
}a[3000];

int main(){
//freopen("C.in","r",stdin);
//freopen("C.out","w",stdout);
    cin>>T;
    rep(ca,1,T){
        mp.clear();
        cnt=ans=0;
        cin>>n;
        rep(i,1,n){
            cin>>s1>>s2;
            if (mp.find(s1)==mp.end()) mp[s1]=++cnt;
            if (mp.find(s2)==mp.end()) mp[s2]=++cnt;
            a[i].x=mp[s1]; a[i].y=mp[s2];
        }
        /*sort(a+1,a+n+1);
        nn=1;
        rep(i,2,n) if (a[nn]!=a[i]) a[++nn]=a[i];*/

        rep(i,1,n){
            c1=c2=0;
            rep(j,1,n){
                if (a[i].x==a[j].x) c1++;
                if (a[i].y==a[j].y) c2++;
            }
            if (c1==1 || c2==1){
                ask1[a[i].x]=ask2[a[i].y]=1;
                ans++;
            }
        }

        rep(i,1,n) if (!ask1[a[i].x] && !ask2[a[i].y]){
            ask1[a[i].x]=ask2[a[i].y]=1;
            ans++;
        }

        rep(i,1,n) if (!ask1[a[i].x] || !ask2[a[i].y]){
            ask1[a[i].x]=ask2[a[i].y]=1;
            ans++;
        }
        rep(i,1,cnt) ask1[i]=ask2[i]=0;

        cout<<"Case #"<<ca<<": "<<n-ans<<endl;
    }
}