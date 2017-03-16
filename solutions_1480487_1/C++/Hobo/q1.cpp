#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    ifstream fin("A-large.in");
    ofstream fout("output.txt");

               int min,t,n,ar[10000],v,min1,i,p=1,c;
               double d,sum,tar,k;
               fin>>t;
               while(t--)
               {
                         min1=1000;
                         sum=0.0;
                         min=1000;
                         fin>>n;
                         for(i=0;i<n;i++)
                         {
                              fin>>ar[i];
                              if(ar[i]<=min)
                              {min=ar[i];
                              v=i;
                              }
                              sum=sum+ar[i];           
                         }
                         tar=(2*sum)/(n);
                         k=2*sum;
                         c=0;
                         for(i=0;i<n;i++)
                         {
                                         if(ar[i]>=tar)
                                         {k=k-ar[i];
                                         c++;                                         
                                         }                                        
                                        }
                                         
                                         tar=k/(n-c);
                         fout<<"Case #"<<p<<": ";
                                         //cout<<sum<<min<<min1<<endl;
                               for(i=0;i<n;i++)
                               {
                                               
                                                       d=(tar-ar[i])/(sum);
                                                       if(d>=0)
                                                       fout<<setprecision(6)<<fixed<<d*100<<" ";
                                                       else
                                                       fout<<"0.000000 ";                                                       
                                                       
                                                       
                                               }                         
                                               fout<<endl;
                                               p++;
}
return 0;
}
