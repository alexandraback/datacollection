#include<fstream>
using namespace std;
int main()
{
   // int br[11]={-1,0,2,5,8,11,14,17,20,23,26};
   ifstream fin("B-large.in");
    ofstream fout("output1.txt");
    int t,n,s,p,i,ar[40],sum,k,z,x,v=1;
    fin>>t;
    while(t--)
    {
              sum=0;
              fin>>n>>s>>p;
              for(i=0;i<=30;i++)
              ar[i]=0;
              for(i=0;i<n;i++)
              {
                              fin>>k;
                              ar[k]++;
                              }
                              if(p>1)
                              z=(p-1)*3+1;
                              else
                              z=p;
                              fout<<"Case #"<<v<<": ";
              for(i=z;i<=30;i++)
              {
                                      sum=sum+ar[i];
                                      }
                                      if(p>1)  
                                      {
                                      x=ar[z-1]+ar[z-2];
                                      if(x>=s)
                                      sum=sum+s;
                                      else
                                      sum=sum+x;
                                      }
                                      fout<<sum<<endl;
                              v++;
              
              }
              return 0;
              
    
}
