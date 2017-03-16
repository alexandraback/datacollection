#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool f[2000010];
int T;
int A,B;
int st[20];
int sts;

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("b.txt","w",stdout);
	int ans;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d %d",&A,&B);
		ans = 0;
		memset(f,0,sizeof(f));
		for(int j=A;j<=B;j++)
		{
			if(!f[j])
			{
				//cout << j;
				f[j] = true;
				int t= j;
				int cnt = 1;
				sts = 0;
				while(t)
				{
					st[sts++] = t%10;
					t/=10;
				}
				int at = 0;
				for(int k=0;k<sts-1;k++)
				{
					// k--0
					if( st[k] )
					{
						at = 0;
						for(int m=0;m<sts;m++)
						{
							at = at*10 + st[k];
							k = (k-1+sts)%sts;
						}
						if(at<=B&&at>=A&&at!=t&&!f[at]) 
						{
							f[at] = true;
							cnt ++;
						}
					}
				}
				//cout << " " << cnt << endl;
				ans += (cnt*(cnt-1))/2;
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}