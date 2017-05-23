#include<fstream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

ofstream fout("ans.out");
ifstream fin("D-large.in");


int t;
int n;
double a[1002],b[1002];
int tail;
int ans1,ans2;

int main()
{
    int i,j,k,times;
    int temp_n;
    fin>>t;
    for(times=1;times<=t;times++)
    {
         fin>>n;
         for(i=1;i<=n;i++)
         {
             fin>>a[i];
         }
         for(j=1;j<=n;j++)
         {
             fin>>b[j];
         }
         
         sort(a+1,a+n+1);
         sort(b+1,b+n+1);
         
         ans2=0;
         tail=1;
         for(i=1;i<=n;i++)
         {
              while(b[tail]<a[i] && tail<=n)
              {
                  tail++;
                  ans2++;
              }
              
              if(tail<=n)
              {
                 tail++;
              }
         }
         
         ans1=0;
         tail=1;
         for(i=1;i<=n;i++)
         {
              while(a[tail]<b[i] && tail<=n)
              {
                  tail++;
                  ans1++;
                  //fout<<tail<<' '<<ans1<<endl;
              }
              
              if(tail<=n)
              {
                 tail++;
              }
              
              
         }
         
         ans1=n-ans1;
         fout<<"Case #"<<times<<": ";
         fout<<ans1<<' '<<ans2<<endl;
    }
    
    system("pause");
    return 0;
}
