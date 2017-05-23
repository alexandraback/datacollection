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
#define inf (1<<20)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define xx first
#define yy second
#define eps 1e-11
#define i64 long long
#define MX 1102

typedef pair<int,int> pii;

struct node{
	int ca,cb;
	node(){}
	node(int x,int y){
		ca=x;
		cb=y;
	}
	bool operator <(const node &a)const{
		return cb<a.cb || (cb==a.cb && ca>a.ca);
	}
}x[MX];

int dp[MX][MX],n;

int func(int a,int b){
	if(b==(1<<n)-1)return 0;
	int &ret=dp[a][b],i,tmp,star;
	if(ret!=-1)return ret;
	ret=inf;
	star=0;
	for(i=0;i<n;i++){
		if(b&(1<<i))star+=2;
		else if(a&(1<<i))star++;
	}
	for(i=0;i<n;i++){
		if(x[i].ca<=star && !(a&(1<<i)) && !(b&(1<<i))){
			tmp=1+func(a|(1<<i),b);
			ret=min(ret,tmp);
		}
		if(x[i].cb<=star && !(b&(1<<i))){
			tmp=1+func(a,b|(1<<i));
			ret=min(ret,tmp);
		}
	}
	return ret;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,t=1,i,res;
	cin>>cs;
	while(cs--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>x[i].ca>>x[i].cb;
		}
		SET(dp);
		res=func(0,0);
		if(res==inf)printf("Case #%d: Too Bad\n",t++);
		else printf("Case #%d: %d\n",t++,res);
	}
	return 0;
}


