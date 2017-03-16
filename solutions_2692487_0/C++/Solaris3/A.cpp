#include<cstdio>
#include<algorithm>
using namespace std;
int n,a;
int tab[1000006];


int solve()
{
  scanf("%d%d",&a,&n);
  for(int i=0;i<n;i++)scanf("%d",&tab[i]);
  sort(tab,tab+n);
  if(a==1)return n;
  int i=0;
  int wyn=n,temp=0;
   //printf("a::%d\n",a);
  // for(int i=0;i<n;i++)printf("%d ",tab[i]);printf("\n");
  while(i<n)
  {
    while(i<n && tab[i]<a){a=min(a+tab[i],1000006);i++;}
    // printf("skonczyle, %d, temp %d, na poz %d\n",a,i,temp);
    wyn=min(wyn,temp+n-i);
    while(a<=tab[i]){temp++;a+=a-1;}
  }
  // printf("skonczyle, %d, temp %d, na poz %d\n",a,i,temp);
  wyn=min(wyn,temp);
  return wyn;
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++)printf("Case #%d: %d\n",i+1,solve());
  return 0;
}