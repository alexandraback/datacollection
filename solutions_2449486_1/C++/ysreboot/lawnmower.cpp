#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>

#define ulli unsigned long long int
#define MOD 1000000007

using namespace std;

int main()
{
    /* uncomment the following two lines to fectch input from input.txt and write to output.txt (after you have completed rest of your code) */
    
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    
    int T;
    cin>>T;
    int t=1;
    
    while(T--)
    {
              int n,m;
              cin>>n>>m;
              
              int a[101][101]={0};
              int b[101][101]={0};
              
              for(int i=0;i<n;i++)
              {
                      for(int j=0;j<m;j++)
                      {
                              cin>>a[i][j];
                              b[i][j]=100;
                      }
              }
              
              
              for(int i=0;i<n;i++)
              {
                      int high=a[i][0];
                      for(int j=1;j<m;j++)
                      {
                              if(a[i][j]>high)
                                              high=a[i][j];
                      }
                      
                      for(int j=0;j<m;j++)
                      {
                              if(b[i][j]>high)
                                              b[i][j]=high;
                      }
              }
              
              for(int i=0;i<m;i++)
              {
                      int high=a[0][i];
                      for(int j=1;j<n;j++)
                      {
                              if(a[j][i]>high)
                                              high=a[j][i];
                      }
                      
                      for(int j=0;j<n;j++)
                      {
                              if(b[j][i]>high)
                                              b[j][i]=high;
                      }
              }
              
              int f=1;
              for(int i=0;i<n;i++)
              {
                      for(int j=0;j<m;j++)
                      {
                              if(a[i][j]==b[i][j]) continue;
                              f=0;
                              break;
                      }
                      if(f==0) break;
              }
              
              if(f)
                   cout<<"Case #"<<t++<<": "<<"YES"<<endl;
              else
                   cout<<"Case #"<<t++<<": "<<"NO"<<endl;
    }
    
    return 0;
}
