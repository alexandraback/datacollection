#include<iostream>
#include<string>
using namespace std;
int main()
{
   freopen("B-small-attempt1.in","r",stdin);
   freopen("bsmall2.txt","w",stdout);
    int t;
    cin>>t;
    int z=1;
    while(t--)
    {
    
              int x,y;
              cin>>x>>y;
              string s;
              int i=1;
              if(x>0)
              {
                     while(x-i>=0)
                     {
                                 s+="E";
                                 x=x-i;
                                 i++;
                                 
                     }
                    // cout<<s;
                     while(x!=0)
                     {
                                  s+="WE";
                                  x--;
                                  i=i+2;
                     }
              }
              else
              {
                  while(x+i<=0)
                  {
                              s+='W';
                              x=x+i;
                              i++;
                              
                  }
                  while(x!=0)
                  {
                             s+="EW";
                             x++;
                             i=i+2;
                  }
              }
              if(y>0)
              {
                     while(y-i>=0)
                     {
                                 s+='N';
                                 y=y-i;
                                 i++;
                                 
                     }
                     while(y!=0)
                     {
                                  s+="SN";
                                  y--;
                                  i=i+2;
                     }
              }
              else
              {
                  while(y+i<=0)
                  {
                              s=s+'S';
                              
                              y=y+i;
                              i++;
                  }
                  while(y!=0)
                  {
                             s+="NS";
                             y++;
                             i=i+2;
                  }
              }
              cout<<"Case #"<<z++<<": "<<s<<endl;
    }
    return 0;
}
                                  
                                  
                                  
                                  
                                  
                                  
              
