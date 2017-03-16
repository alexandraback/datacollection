#include<iostream>
using namespace std;
int main ()
{
    int a,b,x,y,i,j,k,t,br=0,d;
    cin>>t;
    for(k=1;k<=t;k++)
    {
                     cin>>a>>b;br=0;
                     for(i=a;i<=b;i++)
                     {
                                      y=i;
                                      d=0;
                                      while(d!=i)
                                      {
                                          d=0;
                                          if(i>=1000&&i<=9999){d+=y%10;d*=1000;d+=y/10;if(d>=a&&d<=b&&i!=d){br++;}y=d;}
                                          if(i>=100&&i<=999){d+=y%10;d*=100;d+=y/10;if(d>=a&&d<=b&&i!=d){br++;}y=d;}
                                          if(i>=10&&i<=99){d+=y%10;d*=10;d+=y/10;if(d>=a&&d<=b&&i!=d){br++;}y=d;}
                                          if(i<10)break;
                                      }
                     }
                            cout<<"Case #"<<k<<": "<<br/2<<endl;
    }

    return 0;
}
