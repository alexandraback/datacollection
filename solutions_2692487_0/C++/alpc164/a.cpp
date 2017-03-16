#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cctype>
#include<ctime>

#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<set>
#include<bitset>
#include<map>

#define VI vector<int>
#define VD vector<double>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VII vector<PII >
#define VDD vector<PDD >
#define STI stack<int>
#define STD stack<double>
#define STII stack<PII >
#define STDD stack<PDD >

#define pb push_back
#define pf push_front
#define clr clear
#define res resize
#define ass assign
#define fir first
#define sec second

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Dor(i,a,b) for(int i=a;i>=b;i--)
#define Fill(a,b) memset(a,b,sizeof(a))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

const int N=10010;
const int M=100010;
const int inf=1061109567;
const double eps=1e-10;
const double dinf=1e10;
const double Pi=3.14159265358;

typedef long long LL;

using namespace std;

int s[110];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,cas=1;
	cin>>T;
	while (cas<=T)
	{
		int b,n;
		int ans=0,lans=inf;
		printf("Case #%d: ",cas);
		cin>>b>>n;
		For(i,1,n) scanf("%d",s+i);
		cas++;
		if (b==1)
		{
			printf("%d\n",n);
			continue;
		}
		sort(s+1,s+n+1);
		int tmp=b;
		For(j,0,n)
		{
			b=tmp;
			int cnt=n-j;
			ans=j;
			For(i,1,cnt)
			if (b>s[i]) b+=s[i];
			else
			{
				while (b<=s[i])
				{
					b+=b-1;
					ans++;
				}
				b+=s[i];
			}
			if (ans<lans) lans=ans;
		}
		printf("%d\n",lans);
	}
	return 0;
}
