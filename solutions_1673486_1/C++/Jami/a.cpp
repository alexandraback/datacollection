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
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define xx first
#define yy second
#define eps 1e-11
#define i64 long long
#define MX 100002

typedef pair<int,int> pii;

int a,b;
double px[MX],pr[MX];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,t=1,i;
	double res,x,y,z,pz;
	cin>>cs;
	while(cs--){
		cin>>a>>b;
		for(i=0;i<a;i++){
			cin>>pr[i];
			px[i]=pr[i];
			if(i)px[i]*=px[i-1];
		}
		x=px[a-1]*(b+1-a)+(1-px[a-1])*(b+1+b+1-a);
		res=x;
		y=2+b;
		if(res>y+eps)res=y;
		for(i=a-1;i>0;i--){
			pz=px[i-1];
			z=pz*(2*(a-i)+b-a+1)+(1-pz)*(2*(a-i)+b-a+1+b+1);
			if(res>z+eps)res=z;
		}
		printf("Case #%d: %.10lf\n",t++,res);
	}
	return 0;
}


