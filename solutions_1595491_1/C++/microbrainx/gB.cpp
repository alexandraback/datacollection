#include <stdio.h>
#include <algorithm>

using namespace std;

int cut,ntc,n,s,p,r,t[110];

int main(){
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++){
		scanf("%d %d %d",&n,&s,&p);
		for (int i=0;i<n;i++)
			scanf("%d",&t[i]);
		sort(t,t+n);
		r=0;
		cut=-1;
		for (int i=n-1;i>=0;i--)
			if (t[i]>=3*p-2)
				r++;
			else
				{cut=i; break;}
		for (int i=cut;(i>=0)&&(t[i]>1)&&(t[i]>=3*p-4)&&(s>0);i--)
			{r++; s--;}
		printf("Case #%d: %d\n",tc,r);
	}
	return 0;
}