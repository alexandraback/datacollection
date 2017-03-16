#include <cstdio>
#include <algorithm>
#define oo -2147483647

using namespace std;

int f[201][201],Case,a,b,c,x,tmp,tt,T;

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &Case);
	while (Case--){
		scanf("%d%d%d",&a,&b,&c);
		for (int i=0;i<=a;i++)
			for (int j=0;j<=b;j++)
				f[i][j]=oo;
		f[0][0]=0;
		for (int i=1;i<=a;i++){
			scanf("%d",&x);
			for (int j=0;j<=b;j++)
				if (f[i-1][j]!=oo){
					if (j!=b && x>1){
						tt=x%3;
						if (tt==0) tmp=(x-3)/3+2;else
						if (tt==1) tmp=(x-4)/3+2;else tmp=(x-2)/3+2;
						f[i][j+1]=max(f[i][j+1],f[i-1][j]+(tmp>=c));
					}
					tmp=x/3;
					if (x%3) ++tmp;
					f[i][j]=max(f[i][j],f[i-1][j]+(tmp>=c));
				}
		}
		printf("Case #%d: %d\n",++T,f[a][b]);
	}
}
