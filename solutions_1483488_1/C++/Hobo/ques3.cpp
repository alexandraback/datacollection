#include<fstream>
#include<cmath>
using namespace std;
int count(long long n)
{
    int c=0;
    while(n>0)
    {
              c++;
              n=n/10;
              }
              return c;
}
long long power (int l)
{
     long long k=1;
     for(int i=1;i<=l;i++)
     k=k*10;
     return k;
 }

int main()
{
    ifstream fin("C-large.in");
    ofstream fout("output2.txt");
    long long t,flag,a,b,i,loop,j,p,d,f,k,v=1,ar[10],flag1=0,e,g;
    fin>>t;
    while(t--)
    {
              flag=0;
              fin>>a>>b;
              for(i=a;i<=b;i++)
              {
                               g=0;
                               loop=count(i)-1;
                               j=i;
                               flag1=0;
                               for(p=0;p<loop;p++)
                               {
                                                  d=j%10;
                                                  f=(j-d)/10;
                                                  k=power(loop)*d+f;
                                                  j=k;
                                                  
                                                    if((k>i)&&(k<=b))
                                                  {  
                                                   for(e=0;e<g;e++)
                                                   {
                                                                   if(ar[e]==k)
                                                                   flag1=1;
                                                                   }
                                                   if(flag1!=1)
                                                   { 
                                                   flag++;
                                                   ar[g]=k;
                                                   g++;
                                                   flag1=0;
                                       //            fout<<i<<" "<<k<<endl;
                                                   }}
                                                  
                                                  }
                                                  }
                                                  //fout<<"---------------------------"<<endl;
                                                  fout<<"Case #"<<v<<": ";
                                                  fout<<flag<<endl;
                                                  v++;
                                                  }
                                                  return 0;
                                                  }
                                                  
                                              
                                                  
              
