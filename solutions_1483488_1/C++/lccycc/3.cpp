#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int A,B;
bool vali(int a,int b)
{
	return  (b>a && b>=A && b<=B);
}
int tot;
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("out.out","w",stdout);
	int cas=0,cass;
	for (scanf("%d",&cass);cass--;)
	{
		scanf("%d%d",&A,&B);
		printf("Case #%d: ",++cas);
		int i,j,k;
		tot=0;
		for (i=A;i<=B;i++)
		{
			int len=1;
			k=i/10;
			while (k)
			{
				len*=10;
				k/=10;
			}
			k=i/10 + (i%10 * len);
			while (k!=i)
			{
				if (k/len !=0)
					if (vali(i,k))
						tot++;
				k=k/10 + (k%10 * len);
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}

