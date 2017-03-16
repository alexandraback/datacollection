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
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define inf (1<<29)
#define i64 long long
#define MX 1000002

typedef pair<int,int> pii;

string aa,bb,kk;

i64 dp[33][2][2][2];

string conv(i64 n){
    string ret;
    i64 i;
    for(i=0;i<32;i++){
        ret+=n%2+'0';
        n/=2;
    }
    reverse(all(ret));
    return ret;
}

i64 func(int pos,int af,int bf,int kf){
    if(pos==32){
        return kf;
    }
    i64 &ret=dp[pos][af][bf][kf],i,j,k,kt,naf,nbf,nkf;
    if(ret!=-1)return ret;
    ret=0;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(i>aa[pos]-'0' && !af)continue;
            if(j>bb[pos]-'0' && !bf)continue;
            kt=i&j;
            k=kk[pos]-'0';
            if(i<aa[pos]-'0' || af)naf=1;
            else naf=0;
            if(j<bb[pos]-'0' || bf)nbf=1;
            else nbf=0;
            if(kt>k || kf)nkf=1;
            else nkf=0;
			if(kt<k && !kf)continue;
            ret+=func(pos+1,naf,nbf,nkf);
        }
    }
    return ret;
}

int main(){
    freopen("B-large.in","r",stdin);
	//freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	i64 cs,t=1,a,b,k,res=0;
	cin>>cs;
	while(cs--){
	    cin>>a>>b>>k;
		a--;
		b--;
		k--;
	    aa=conv(a);
	    bb=conv(b);
	    kk=conv(k);
	    SET(dp);
	    res=func(0,0,0,0);
	    printf("Case #%lld: %lld\n",t++,(a+1)*(b+1)-res);
	}
	return 0;
}


