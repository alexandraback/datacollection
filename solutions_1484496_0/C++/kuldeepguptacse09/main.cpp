#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
pair<int,int>ss[1500000];


int main()
{
int t,l=1,n,i,j;
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
scanf("%d",&t);

for(;l<=t;l++){
memset(ss,0,sizeof(ss));
scanf("%d",&n);
int a[300];
for(i=0;i<n;i++){scanf("%d",&a[i]);}
for(i=1;i<=(1<<n);i++){
int sum=0;
for(j=0;j<=n;j++)if(i&(1<<j))sum+=a[j];

ss[i].first=sum;ss[i].second=i;//printf("%d ",ss[i].a);
}
sort(ss,ss+(1<<n));
for(i=2;i<=(1<<n);i++)if(ss[i].first==ss[i-1].first){break;}
printf("Case #%d:\n",l);
if(i<=(1<<n)){int k=ss[i].second;for(j=0;j<n;j++)if(k&(1<<j))printf("%d ",a[j]);printf("\n");k=ss[i-1].second;for(j=0;j<n;j++)if(k&(1<<j))printf("%d ",a[j]);printf("\n");}
else printf("Impossible\n");
}
return 0;
}
