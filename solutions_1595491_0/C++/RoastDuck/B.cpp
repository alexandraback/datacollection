#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct data
{
	int a,b;
};
bool operator<(data x,data y)
{
	return (x.a<y.a || (x.a==y.a && x.b<y.b));
}
int T,t,N,S,P,x;
data a[105];

int main()
{
	freopen("BIn.txt","r",stdin);
	freopen("BOut.txt","w",stdout);
	scanf("%d",&T);
	for (;T>0;T--)
	{
		int ans(0);
		scanf("%d%d%d",&N,&S,&P);
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&x);
			switch(x%3)
			{
				case 0: a[i].a=x/3; if (x/3>0 && x/3<10) a[i].b=x/3+1; else a[i].b=x/3; break;
				case 1: a[i].a=x/3+1; a[i].b=x/3+1; break;
				case 2: a[i].a=x/3+1; if (x/3<=8) a[i].b=x/3+2; else a[i].b=x/3+1; break;
			}
		}
		sort(a+1,a+N+1);
		for (data *i=a+N;i>a;i--)
			if (i->a>=P) ans++; else
			if (S>0 && i->b>=P) {ans++; S--;}
			else break;
		printf("Case #%d: %d\n",++t,ans); 
	}
	return 0;
}
