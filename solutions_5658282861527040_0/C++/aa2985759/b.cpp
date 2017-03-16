#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
    int a,b,i,j,k,t;
    int ii=0;

    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
	scanf("%d%d%d",&a,&b,&k);
	int ans=0;

	for(i=0;i<a;i++)
		for(j=0;j<b;j++)if((i&j)<k)
		    ans++;
	printf("Case #%d: %d\n",++ii,ans);
    }
}
