#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[7]={0};
int main()
{int n,m,i,j,k,l,T,tt=0,js[10]={0};
 long long ans=0;
 freopen("C.in","r",stdin);
 freopen("C.out","w",stdout);
 scanf("%d",&T);
 js[0]=1;
 for(i=1;i<=8;i++)
  js[i]=js[i-1]*10;
 while(T--)
 {tt++;
  scanf("%d%d",&n,&m);
  k=n;
  l=0;
  while(k)
  {k/=10;l++;}
  ans=0;
  for(i=n;i<=m;i++)
  {j=i;
   for(k=1;k<l;k++)
   {j=j/10+(j%10)*js[l-1];
    int z;
    for(z=1;z<k;z++)
     if(a[z]==j)break;
    a[k]=j;
    if(z<k)break;
    if(j>i&&j<=m)ans++;
   }
  }
  cout<<"Case #"<<tt<<": "<<ans<<endl;
 }
 return 0;
}
   
  
