#include<fstream>
#include<cmath>
#include<stdio.h>
#include<string.h>
using namespace std;

ofstream fout("ans.out");
ifstream fin("B-small-attempt0.in");



int t;
double c,f,x;
double p;
double ans;
int main()
{
    int i,j,k,times;
    bool flag;
    fin>>t;
    for(times=1;times<=t;times++)
    {
         p=2.0;
         ans=0.0;
         
         fin>>c>>f>>x;
         fout<<"Case #"<<times<<": ";
         fout.precision(7);
         fout.setf(ios::fixed);
         if(x<c+1e-8)
         {
              fout<<x/p<<endl;
              continue;
         }
         
         flag=0;
         while(flag==0)
         {
              ans+=c/p;
              if(x/(p+f)<(x-c)/p)
              {
                  p+=f;
              }
              else
              {
                  flag=1;
              }
         }
         
         ans+=(x-c)/p;
         
         fout<<ans<<endl;
    }
    
    system("pause");
    return 0;
}
