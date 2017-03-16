#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long int int64;
int b[5];
int ifp(int d)
{
int i,j,k;
for(i=0;i<3;i++)for(j=i+1;j<3;j++)for(k=j+1;k<3;k++)
  {
  if(b[i]*b[j]*b[k]==d)return 1;
  if(b[i]*b[j]==d)return 1;
  if(b[j]*b[k]==d)return 1;
  if(b[i]*b[k]==d)return 1;
  if(b[i]==d)return 1;
  if(b[j]==d)return 1;
  if(b[k]==d)return 1;
  if(d==1)return 1;
  }
return 0;
}
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,n,k,m,t,cnt=1,r,x,y,z,a[100],fl,fls;
//b[0]=3;b[1]=3;b[2]=4,b[3]=1;
//cout<<ifp(36)<<ifp(9)<<ifp(4)<<ifp(1)<<endl;
cin>>t;
while(t--)
{
cin>>r>>n>>m>>k; 
printf("Case #%lld:\n",cnt);
while(r--){fls=0;
for(i=0;i<k;i++)cin>>a[i];
for(x=2;x<=5;x++)
  {
  for(y=2;y<=5;y++)
  	{
  	for(z=2;z<=5;z++)
  	  {fl=0;
  	  for(j=0;j<k;j++)
  	     {
  	     b[0]=x;b[1]=y;b[2]=z;
  	     if(ifp(a[j])==1)fl++;
  	     }
  	   if(fl==k){fls=1;break;}
  	  }
  	if(fls==1)break;
  	}
  if(fls==1)break;
  } 
cout<<x<<y<<z<<endl; 
}
cnt++;
}
return 0;
}
