#include<bits/stdc++.h>
using namespace std;
int n;
void fuck()
{
	int i,j,t;
	int a[2510]={0};
	scanf("%d",&n);
	for(i=1;i<2*n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&t);
			a[t]++;
		}
	}
	for(i=1;i<=2500;i++)
		if(a[i]&1) printf(" %d",i);
	printf("\n");
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
   int i,t;
   scanf("%d",&t);
   for(i=1;i<=t;i++){
	   printf("Case #%d:",i);
	   fuck();
   }
 return 0;
}
