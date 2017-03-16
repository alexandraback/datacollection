#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int findsmallest(int s[200],int n)
{

int i;
int smallest=0;
int small=s[0];
for(i=1;i<n;i++)
{
if(s[i]<small)
{
small=s[i];
smallest=i;
}
}
return smallest;
}

int findsecondsmallest(int s[200],int n,int j)
{
int smallest;int small;
if(j!=0)
{
int i;
smallest=0;
small=s[0];
for(i=1;i<n;i++)
if(s[i]<small && i!=j)
{
small=s[i];
smallest=i;
}
}

else
{
int i;
smallest=1;
small=s[1];
for(i=2;i<n;i++)
if(s[i]<small && i!=j)
{
small=s[i];
smallest=i;
}
}

return smallest;
}

using namespace std;
int main()
{

int tests,testno;
int i,j,n,x;
int s[200];
cin>>tests;
for(testno=1;testno<=tests;testno++)
{
cin>>n;
int x=0;
for(i=0;i<n;i++)
{
cin>>s[i];
x+=s[i];
}

double answers[200];
double total=0;
int x2=2*x;
int n1=n;
for(i=0;i<n;i++)
if(s[i]>2*x/n)
{
answers[i]=0;
x2-=s[i];
n1--;
}
cout<<"Case #"<<testno<<":";
for(i=0;i<n;i++)
{
if(s[i]>2*x/n)
continue;
double answer=1.0*x2/n1-s[i];

answer=answer/x;
if(answer<0)
answer=0;
answers[i]=answer;
total+=answer;
}

for(i=0;i<n;i++)
printf(" %lf",answers[i]*100);
cout<<endl;

}

return 0;
}
