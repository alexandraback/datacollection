# include<iostream>
# include<cstdio>
# include<fstream>
# include<cmath>
# include<sstream>
using namespace std;
int main()
{
    int t,a,b,i,sx,sy,f=0,x,y;
    freopen("B-small-attempt0.in","r",stdin);
    cin>>t;
    ofstream m;
    m.open("l.txt");
    while(t--)
    {
              cin>>x>>y;
              sx=0;
              sy=0;
              i=1;
              m<<"Case #"<<++f<<": ";
              //cout<<"Case #"<<++f<<": ";
              a=0;
              b=0;
              while(sx!=x || sy!=y)
              {
                          if(sx!=x)
                          {
                                   if(x>0)
                                   {
                                          if(sx+i<=x)
                                          {
                                                     sx+=i;
                                                     m<<"E";
                                                     //cout<<"E";
                                          }
                                          else
                                          {
                                              sx-=i;
                                              m<<"W";
                                              //cout<<"W";
                                          }
                                   }
                                   else
                                   {
                                       if(sx-i>=x)
                                       {
                                                  sx-=i;
                                                  m<<"W";
                                                  //cout<<"W";
                                       }
                                       else
                                       {
                                           sx+=i;
                                           m<<"E";
                                           //cout<<"E";
                                       }
                                   }
                          }
                          else
                          {
                              if(y>0)
                              {
                                     if(sy+i<=y)
                                     {
                                                sy+=i;
                                                m<<"N";
                                                //cout<<"N";
                                     }
                                     else
                                     {
                                         sy-=i;
                                         m<<"S";
                                         //cout<<"S";
                                     }
                              }
                              else
                              {
                                  if(sy-i>=y)
                                  {
                                             sy-=i;
                                             m<<"S";
                                             //cout<<"S";
                                  }
                                  else
                                  {
                                      sy+=i;
                                      m<<"N";
                                      //cout<<"N";
                                  }
                          }
              } 
                          ++i;
              }
              m<<endl;
              //cout<<endl;
    }
    m.close();
    cin>>t;
    return 0;
}
