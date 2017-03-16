#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<utility>
#include<cstdlib>
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",&x)
using namespace std;

int a[1010][1010]={{0}};


int main()
{
   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);




int n,m,i,j,k,temp,t,tt=1;

cin>>t;

while(t--)
{

cin>>n;

for(i=0;i<=n;i++)
for(j=0;j<=n;j++)
a[i][j]=0;

for(i=1;i<=n;i++)
{
                cin>>m;
                while(m--)
                {
                          cin>>j;
                          a[i][j]++;
                }
}                

   


for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(a[i][k] && a[k][j])a[i][j]++;

k=0;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(i!=j && a[i][j]>=2){k=1;break;}

printf("Case #%d: ",tt++);
if(k)cout<<"Yes";
else cout<<"No";
cout<<endl;
}


return 0;
}
