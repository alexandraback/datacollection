#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("asmall.txt","w",stdout);
    int t;
    cin>>t;
    int z=1;
    while(t--)
    {
              string s;
              int n;
              cin>>s>>n;
              int t,count=0,count2,j,k,i;
              for(i=0;i<s.length();i++)
              {
                     
                     for(j=1;j<=s.length()-i;j++)
                     {
                                 string x=s.substr(i,j);
                                 count2=0;
                                // cout<<x<<" ";
                                 for(k=0;k<x.length();k++)
                                 {
                                          if(x[k]!='a'&&x[k]!='e'&&x[k]!='i'&&x[k]!='o'&&x[k]!='u')
                                          count2++;
                                          else 
                                          count2=0;
                                          if(count2==n)
                                          {
                                                       count++;
                                                       break;
                                          }
                                 }
                     }
              }
              printf("Case #%d: %d\n",z++,count);
    }
    return 0;
}      
                                               
