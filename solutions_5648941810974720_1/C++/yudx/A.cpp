#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cplx;

#define sqr(x) ((x)*(x))
#define pb push_back
#define X first
#define Y second
#define sit(a) set<a>::iterator
#define mit(a,b) map<a,b>::iterator

const ll mod=1000000007LL;
const int inf=0x3f3f3f3f;
const int maxn=100005,maxm=1005;
const double eps=1e-10;
const double pi=acos(-1.0);

int T,ca;
char cc[15][maxm]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char c[maxn];
int a[35],r[15];
char tt[15]="ZWXUGFVHIN";
int sx[15]={0,2,6,4,8,5,7,3,9,1};

void solve()
{
	memset(a,0,sizeof(a));
	memset(r,0,sizeof(r));
	int i,j;
	for(i=0;c[i];i++) a[c[i]-'A']++;
	for(i=0;i<10;i++)
	{
		int cx=tt[i]-'A',cy=sx[i];
		r[cy]=a[cx];
		for(j=0;cc[cy][j];j++) a[cc[cy][j]-'A']-=r[cy];
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<r[i];j++) printf("%d",i);
	}
	printf("\n");
}

vector<int> v[30];

int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
	for(int i=0;i<10;i++)
	{
		for(int j=0;cc[i][j];++j) v[cc[i][j]-'A'].pb(i);
	}
	for(int i=0;i<26;i++)
	{
		if(v[i].empty()) continue;
		cerr<<char('A'+i)<<" ";
		for(int j=0;j<v[i].size();j++) cerr<<v[i][j]<<" ";
		cerr<<endl;
	}
	scanf("%d",&T);
	for(ca=1;ca<=T;ca++)
	{
		scanf("%s",c);
		printf("Case #%d: ",ca);
		solve();
	}	
        return 0;
}
