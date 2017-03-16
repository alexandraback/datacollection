#include <stdio.h>
#include <iostream>
using namespace std;

int g[30];
void spi(int a)
{
	int i; g[0]=0;
	while (a>0)
	{
		g[++g[0]]=a%10;
		a/=10;
	}
	for (i=1; i<=g[0]/2; i++){int t=g[i]; g[i]=g[g[0]+1-i]; g[g[0]+1-i]=t;}
}

bool v[2000010];
int main()
{
	int i, j, a, b, T, t, ans;
	
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> T;
	for (t=1; t<=T; t++)
	{
		ans=0;
		memset(v,0,sizeof(v));
		cin >> a >> b;
		for (i=a; i<=b; i++)
			if (!v[i]){
				spi(i);
				v[i]=1;
				int tt=1;
				for (j=1; j<g[0]; j++){
					int t=0;
					for (int k=1; k<=g[0]; k++)
						t = t*10 + g[(k+j+g[0]-1)%g[0]+1];
					if (!v[t]&&(t>=a&&t<=b))
					{v[t]=1; tt++; }
				}
				ans += tt*(tt-1)/2;
			}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}