#include <iostream>
using namespace std;

int n,T, s,p,ans;
int a[105]; 

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >>T;
	for (int q=1; q<=T; q++)
	{
		printf("Case #%d: ", q);
		scanf("%d%d%d", &n,&s,&p);
		for (int i=0; i<n; i++)
			scanf("%d",&a[i]);
		ans=0;
		for (int i=0; i<n; i++)
		{
			if (a[i]<p) continue;
			int b=a[i]/3;
			int c=a[i]-b*3;
			if (b>=p) ans++;
			else
			{
				if (b==p-1)
				{
					if (c>0) ans++;
					else
					if (s>0) {ans++; s--;}
				}
				if (b==p-2 && c==2 && s>0) {ans++; s--;}
			}
		}

		printf("%d\n",ans);

	}
	return 0;

}