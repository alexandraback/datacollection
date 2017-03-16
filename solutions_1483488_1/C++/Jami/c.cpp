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
#define i64 __int64
#define MX 1000002

typedef pair<int,int> pii;

bool vi[3000][3000];

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,l,w,cs,t=1,a,b,c,x;
	set<int> st;
	int res;
	cin>>cs;
	while(cs--){
		cin>>a>>b;
		w=1;
		l=1;
		while(w*10<=b){
			w*=10;
			l++;
		}
		res=0;
		for(i=a;i<=b;i++){
			c=i;
			st.clear();
			for(j=1;j<l;j++){
				x=c%10;
				c/=10;
				c=w*x+c;
				if(c>i && c>=a && c<=b){
					if(st.find(c)==st.end())res++;
					st.insert(c);
				}
			}
		}
		cout<<"Case #"<<t++<<": "<<res<<endl;
	}
	return 0;
}


