#include <cstdio>
#include <cmath>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
          long s[1001],i,j,N,X,T,P,d;
          double t[1001],Y,sub;
          
          freopen("A-large.in","r",stdin);
          //freopen("safetyout.cpp","w",stdout);
          freopen("out.txt","w",stdout);
          cin>>T;
          for (i=1; i<=T; i++)
          {
                    sub=0; d=0;
                    cout<<"Case #"<<i<<": ";
                    X=0;
                    cin>>N;
                    for (j=1; j<=N;j++)
                    {
                              cin>>s[j];
                              X=X+s[j];
                    }
                    P=X;
                    for (j=1; j<=N; j++)
                    {
                              if (s[j]>(2*X/N)) {d++;}
                              else {P=P+s[j];}
                    }
                    /*if (i==21) {cout<<"P="<<P<<endl;
                    cout<<N-d<<endl;
                    Y=double(P)/(N-d);
                    cout<<"Y="<<Y<<endl;
                    }*/
                    Y=double(P)/(N-d);
                    for (j=1; j<=N; j++)
                    {
                              t[j]=max(0.000,100*double( double(Y) - s[j])/X);
                              printf("%0.6f ",t[j]);
                    }
                    cout<<endl;
          }
          //system("pause");
          return 0;
}
                    
                    
          
          
