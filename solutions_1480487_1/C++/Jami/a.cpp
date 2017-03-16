#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<iterator>
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
#define eps 1e-11
#define i64 __int64
#define MX 209

typedef pair<int,int> pii;

int s[MX],x,n;
double pr[MX];

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,t=1,i,j,nn,xx;
	double avg;
	cin>>cs;
	while(cs--){
		cin>>n;
		for(i=0,x=0;i<n;i++){
			cin>>s[i];
			x+=s[i];
		}
		avg=(2*x)/(double)n;
		nn=n;
		xx=x;
		for(i=0;i<n;i++){
			if(s[i]>avg+eps){
				nn--;
				xx-=s[i];
			}
		}
		for(i=0;i<n;i++){
			if(s[i]<avg || fabs(s[i]-avg)<eps)pr[i]=(((xx+x)/(double)nn)-s[i])/(double)x;
			else pr[i]=0;
		}
		printf("Case #%d:",t++);
		for(i=0;i<n;i++)printf(" %.10lf",pr[i]*100);
		puts("");
	}
	return 0;
}


