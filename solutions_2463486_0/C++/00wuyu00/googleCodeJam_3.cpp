#include<iostream>
#include<stdio.h>
#include<math.h>
#include<sstream>
using namespace std;
int check(int a)
{
  stringstream ss;
  string b;
  ss<<a;
  ss>>b;
  for(int i=0;i<b.size()/2;i++)
    if(b[0]==b[b.size()-1-i])
    continue;
  else return 0;
 return 1;
}

int main()
{
   freopen("input.in","r",stdin);
   freopen("output.out","w",stdout);
   int t,a,b;
   scanf("%d",&t);
   for(int j=0;j<t;j++)
   {
    scanf("%d%d",&a,&b);
    int num=0;
    for(int i=sqrt(a)-1;i<=sqrt(b);i++)
    {
     int temp=i*i;
     if(temp<a||temp>b) continue;
     if(check(i)&&check(temp))
        num++;
    }
    printf("Case #%d: %d\n",j+1,num);
   }
   return 0;
}
