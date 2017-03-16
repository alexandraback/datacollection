#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
typedef long long int int64;
int64 tbl[301][10001],n,m,tm;
int64 lcs(int i,int j,int64 a[],int64 b[])
{
int64 val,ii,jj;
//cout<<i<<" "<<j<<" called ";
if(i>2*n||j>2*m)return 0;
if(tbl[i][j]==-1)
  {
  if(a[i]==b[j])
      {val = min(a[i-1],b[j-1]);
       a[i-1]-=val;b[j-1]-=val;
      // cout<<a[i-1]<<" at "<<i<<" "<<b[j-1]<<" at "<<j<<endl;
       if(a[i-1]==0){ii = i+2;}
       else ii = i;
       if(b[j-1]==0){jj = j+2;}
       else jj = j;
	   tbl[i][j] =  val + lcs(ii,jj,a,b);
	   }
  else {
  		//cout<<i+2<<" "<<j<<" and "<<i<<" "<<j+2<<endl;
  		tbl[i][j] = max(lcs(i+2,j,a,b),lcs(i,j+2,a,b));}
  }
//else cout<<" and found"<<endl;
//cout<<i<<"-"<<j<<" "<<tbl[i][j]<<endl;
return tbl[i][j];
}
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,k,t,ai,ni,k2,cnt=1,a[100],b[201];
cin>>t;
while(t--)
{
scanf("%lld %lld",&n,&m);
memset(tbl,-1,sizeof(tbl[0][0])*301*10001);
for(i=0;i<2*n;i+=2){scanf("%lld %lld",&a[i],&a[i+1]);}
//for(i=0;i<2*n;i++)cout<<a[i]<<" ";cout<<endl;
for(i=0;i<2*m;i++){scanf("%lld",&b[i]);}
//for(i=0;i<2*m;i++)cout<<b[i];cout<<endl;
printf("Case #%lld: %lld\n",cnt,lcs(1,1,a,b));
cnt++;
}
return 0;
}

