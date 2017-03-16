#include <iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<math.h>
using namespace std;
int main()
{
int t,N,A,i,j,k;
float tt,a[10],d,ti[2],x[2],l,m,time;
        freopen( "B-small-attempt0.in", "r", stdin );
        freopen( "ou.out", "w", stdout );
cin>>t;
cin.ignore();
for(i=1;i<=t;i++)
{
cin>>d>>N>>A;
for(j=0;j<N;j++)
cin>>ti[j]>>x[j];
for(k=0;k<A;k++)
cin>>a[k];
if(N==2)
{l=x[1]-x[0];
m=ti[1]-ti[0];
time=(m*(d-x[0]))/l;}
else
time=ti[0];
printf("Case #%d:\n",i);
for(k=0;k<A;k++)
{
tt=sqrt(2*d/a[k]);
if(tt>time)
printf("%f\n",tt);
else
printf("%f\n",time);
}
}
return 0;
}
