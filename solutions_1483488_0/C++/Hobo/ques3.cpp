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
    ifstream fin("C-small-attempt0.in");
    ofstream fout("output2.txt");
    int t,flag,a,b,i,loop,j,p,d,f,k,v=1;
    fin>>t;
    while(t--)
    {
              flag=0;
              fin>>a>>b;
              for(i=a;i<=b;i++)
              {
                               loop=count(i)-1;
                               j=i;
                               for(p=0;p<loop;p++)
                               {
                                                  d=j%10;
                                                  f=(j-d)/10;
                                                  k=power(loop)*d+f;
                                                  j=k;
                                                  
                                                    if((k>i)&&(k<=b))
                                                  {  
                                                   flag++;
                                                   //fout<<i<<" "<<k<<endl;
                                                   }
                                                  
                                                  }
                                                  }
                                                  //fout<<"---------------------------"<<endl;
                                                  fout<<"Case #"<<v<<": ";
                                                  fout<<flag<<endl;
                                                  v++;
                                                  }
                                                  return 0;
                                                  }
                                                  
                                              
                                                  
              
