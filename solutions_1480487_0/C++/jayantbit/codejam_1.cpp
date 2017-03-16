#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#define read(x) scanf("%d",&x)
using namespace std;


/*
0 

((x-y +x)/n-xi)/x
*/

int main()
{
  
  int t,n,i,j,sum,tt=1; 
freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
cin>>t;
double f;
while(t--)
{         
          cin>>n;
          vector <int> v(n);
          vector <double> ans(n);
          
          
          sum=0;
          for(i=0;i<n;i++)
          {
                          cin>>j;
                          v[i]=j;
                          sum+=j;
          }
                          

printf("Case #%d:",tt++);

int y=0,n2=0;

for(i=0;i<n;i++)
if(v[i]*n>2*sum)
{
                y+=v[i];
                ans[i]=v[i]=-1;
                n2++;
}

for(i=0;i<n;i++)
{ if(v[i]==-1)ans[i]=0.0;
  else ans[i]=100.0*((2.0*sum-y)/(n-n2) -v[i])/sum;
printf(" %0.6lf",ans[i]);

}

//(2*x/n -xi)/x
cout<<endl;
}
return 0;
}
