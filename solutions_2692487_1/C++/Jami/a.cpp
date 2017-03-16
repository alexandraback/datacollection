#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid,s,e
#define clrgt rgt,mid+1,ed,s,e
#define inf (1<<29)
#define i64 long long
#define MX 3000009

typedef pair<int,int> pii;

int dp[110][MX];
int m[110],n,sum[110],a;

int func(int pos,int ex){
    if(pos==n+1)return 0;
    int &ret=dp[pos][ex],mm,tmp;
    if(ret!=-1)return ret;
    mm=a+sum[pos-1]+ex;
    ret=n-pos+1;
    if(mm>m[pos]){
        tmp=func(pos+1,ex);
        ret=min(ret,tmp);
    }
    else{
        tmp=1+func(pos,ex+mm-1);
        ret=min(tmp,ret);
    }
    return ret;
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,i,t=1;
	cin>>cs;
	while(cs--){
	    cin>>a>>n;
	    for(i=1;i<=n;i++)cin>>m[i];
	    sort(m+1,m+n+1);
	    for(i=1;i<=n;i++)sum[i]=sum[i-1]+m[i];
	    SET(dp);
	    printf("Case #%d: %d\n",t++,func(1,0));
	}
	return 0;
}


