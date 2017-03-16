#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("A-small-attempt0.in");
ofstream fout("output.txt");
int main()
{
    int t,n,i,j,m,ar[100][100],a,k,flag,p=1;
    
    fin>>t;
    while(t--)
    {flag=0;
              fin>>n;
              for(i=1;i<=n;i++)
              {
                              for(j=1;j<=n;j++)
                              {
                                 ar[i][j]=0;
                                 }
                                 }
              for(i=1;i<=n;i++)
              {
                              fin>>m;
                              for(j=0;j<m;j++)
                              {
                                              fin>>a;
                                              ar[i][a]++;
                                              }
                                              }
              for(i=1;i<=n;i++)
              {
                               for(j=1;j<=n;j++)
                               {
                                                if(i!=j)
                                                {
                                                        
                                                        if(ar[j][i]==1)
                                                        {
                                                                    //   cout<<i<<" "<<j<<endl;
                                                                       for(k=1;k<=n;k++)
                                                                       if(ar[i][k]>=1)
                                                                       ar[j][k]++;
                                                                       }
                                                                       
                                                        }
                                                
                                                }
                               }             
            for(i=1;i<=n;i++)
            {
                             for(j=1;j<=n;j++)
                             {
                                           //  cout<<ar[i][j]<<" ";
                                if(ar[i][j]>=2)
                                {flag=1;
                                break;
                                               }              
                             
                                               }
                                            //   cout<<endl;
                                               }
                                               fout<<"Case #"<<p<<": ";
                                               if(flag==1)
                                               fout<<"Yes"<<endl;
                                               else
                                               fout<<"No"<<endl;       
                                               p++; 
                                               }
                                               return 0;
                                               }
