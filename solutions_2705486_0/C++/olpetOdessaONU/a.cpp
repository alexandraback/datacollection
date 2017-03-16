#pragma comment(linker, "/STACK:50000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vi::iterator vit;
typedef vector<pii> vpi;

#define sq(x) (x)*(x)
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
#define LL "%I64d"
#define RLL(x) scanf(LL,&(x))

vector<string> v;
char str[4005];
int dyn[4055];
int inf = 1e9;

void test(int t)
{
	cl(str);
	cl(dyn);
	scanf("%s",str+1);
	int n = strlen(str+1);
	dyn[0]=0;
	for(int i=1; i<=n; ++i)
		dyn[i]=inf;
	for(int i=0; i<n; ++i)
		if(dyn[i]<inf)
		for(int j=0; j<v.size(); ++j)
		{
			if(v[j].length()+i<=n)
			{
				int last = -5;
				int was = 0;
				bool b=true;
				for(int k=0; k<v[j].length(); ++k)
					if(v[j][k]!=str[i+k+1])
					{
						if(k-last>4)
						{
							last=k;
							++was;
						}
						else
						{
							b=false;
							break;
						}
					}
				if(b)
					dyn[i+v[j].length()] = min(dyn[i+v[j].length()],dyn[i]+was);
			}
		}
	printf("Case #%d: %d\n",t,dyn[n]);
}


int main()
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	FILE* f = fopen("a.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%s",str);
		//if(feof(f))
			//break;
		v.push_back(string(str));
	}
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
		test(i);
	return 0;
}