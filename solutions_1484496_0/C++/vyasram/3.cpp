#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

using namespace std;
int main()
{int i;
int **fact;
fact=(int**)malloc(sizeof(int*)*2000001);
for(i=0;i<2000001;i++){
fact[i]=(int*)malloc(sizeof(int)*20);

}


bool broken[2000001];
bool yes[2000001];
bool yes1[2000001];
int tests,testno;
cin>>tests;
for(testno=1;testno<=tests;testno++)
{

int n;
long long int input[500];
cin>>n;

for(i=0;i<n;i++)
cin>>input[i];


for(i=0;i<2000001;i++)
broken[i]=yes[i]=0;

yes[1000000]=1;
int j;



for(i=0;i<2000001;i++)
for(j=0;j<n;j++)
fact[i][j]=0;




for(i=0;i<n;i++)
{
for(j=0;j<2000001;j++)
yes1[j]=0;

for(j=0;j<2000001;j++)
if(yes[j]==1)
{
if(j+input[i]<=2000000 && j+input[i]>=0)
{

yes1[j+input[i]]=1;
int k;
for(k=0;k<i;k++)
fact[j+input[i]][k]=fact[j][k];
fact[j+input[i]][i]=1;
broken[j+input[i]]=1;
if(j+input[i]==1000000)
goto tee;
}

if(j-input[i]<=2000000 && j-input[i]>=0)
{

yes1[j-input[i]]=1;
int k;
for(k=0;k<i;k++)
fact[j-input[i]][k]=fact[j][k];
fact[j-input[i]][i]=-1;
broken[j-input[i]]=1;
if(j-input[i]==1000000)
goto tee;
}
}

for(j=0;j<2000001;j++)
yes[j]=yes1[j];
}

tee:
printf("Case #%d:\n",testno);
if(!broken[1000000])
cout<<"Impossible"<<endl;
else
{
int t;
for(t=0;t<n;t++)
if(fact[1000000][t]==1)
cout<<input[t]<<" ";
cout<<endl;
for(t=0;t<n;t++)
if(fact[1000000][t]==-1)
cout<<input[t]<<" ";
cout<<endl;
}


}

return 0;
}
