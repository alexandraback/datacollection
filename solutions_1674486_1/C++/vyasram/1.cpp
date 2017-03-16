#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;




int m[1000];
int a[1000][10];
int n;

bool reached[1000];
bool broken[1000];
bool reachedtemp[1000];
bool checkdiamondinheritence(int t)
{
int i,j;
for(i=0;i<n;i++)
reached[i]=0;

reached[t]=1;

for(i=0;i<n;i++)
broken[i]=0;
broken[t]=1;

for(i=0;i<n+1;i++)
{


for(j=0;j<n;j++)
reachedtemp[j]=0;
int k;


for(j=0;j<n;j++)
if(reached[j])
for(k=0;k<m[j];k++)
{
int val=a[j][k];
if(broken[val])
{
return true;
}
broken[val]=1;
reachedtemp[val]=1;
}



for(j=0;j<n;j++)
reached[j]=reachedtemp[j];

}

return false;
}
int main()
{

int tests,testno;
int i,j;
cin>>tests;
for(testno=1;testno<=tests;testno++)
{
cout<<"Case #"<<testno<<":";
cin>>n;


for(i=0;i<n;i++)
{
cin>>m[i];
for(j=0;j<m[i];j++)
{cin>>a[i][j];
a[i][j]--;
}
}

//input gathered

for(i=0;i<n;i++)
if(checkdiamondinheritence(i))
goto end1;



cout<<" No"<<endl;
continue;
end1:
cout<<" Yes"<<endl;
continue;


}

return 0;
}
