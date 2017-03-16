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
#define eps 1e-9
#define i64 long long
#define MX 1000002

typedef pair<int,int> pii;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,t=1,n,s,p,x,res,a,b,c;
	cin>>cs;
	while(cs--){
		cin>>n>>s>>p;
		res=0;
		while(n--){
			cin>>x;
			a=p;
			b=p-1;
			if(b<0)b=0;
			c=p-1;
			if(c<0)c=0;
			if(x>=a+b+c){
				res++;
				continue;
			}
			a=p;
			b=p-2;
			if(b<0)b=0;
			c=p-2;
			if(c<0)c=0;
			if(s && x>=a+b+c){
				res++;
				s--;
			}
		}
		cout<<"Case #"<<t++<<": "<<res<<endl;
	}
	return 0;
}


