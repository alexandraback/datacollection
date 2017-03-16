#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>=y;i--)
#define trv(y,x) for(typeof(x.rbegin())y=x.rbegin();y!=x.rend();y++)
#define pb(f) push_back(f)
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a)
using namespace std;
//#include<windows.h>
FILE *fin = freopen("1.in","r",stdin);
FILE *fout = freopen("1.txt","w",stdout);

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vpii;
int main()
{
	int t;
	sc(t);
	int casse=0;
	while(t--)
	{
		int r,c,w,ans;
		casse++;
		sc(r);sc(c);sc(w);
		if(c%w==0)
		ans=c/w+w-1;
		else ans=c/w+w;
		ans+=(c/w)*(r-1);
		printf("Case #%d: %d\n",casse,ans);
	}
}
