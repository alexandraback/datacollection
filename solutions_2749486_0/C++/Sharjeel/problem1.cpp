#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

int main()
{
    ifstream alpha("B-small-attempt0.in");
    ofstream beta("output.txt");
    
    int T;
    alpha>>T;
    int i;
    int X,Y;
    char s[500]="";
    
    for(i=1;i<=T;i++)
    {
                     alpha>>X>>Y;
                     int x=0;
                     int y=0;
                     int j=1;
                     while(x!=X || y!=Y)
                     {
                                if(X-x==j)
                                {
                                          x+=j;
                                          s[j]=s[j-1];
                                          s[j-1]='E';
                                          }
                                else if(x-X==j)
                                {
                                          x-=j;
                                          s[j]=s[j-1];
                                          s[j-1]='W';
                                          }
                                else if(Y-y==j)
                                {
                                          y+=j;
                                          s[j]=s[j-1];
                                          s[j-1]='N';
                                          }
                                else if(y-Y==j)
                                {
                                          y-=j;
                                          s[j]=s[j-1];
                                          s[j-1]='S';
                                          }
                                else if(X-x>j)
                                {         
                                          x+=j;
                                          s[j]=s[j-1];
                                          s[j-1]='E';
                                          }
                                else if(x-X>j)
                                {
                                          x-=j;
                                          s[j]=s[j-1];
                                          s[j-1]='W';
                                          }
                                else if(Y-y>j)
                                {
                                          y+=j;
                                          s[j]=s[j-1];
                                          s[j-1]='N';
                                          }
                                else if(y-Y>j)
                                {
                                          y-=j;
                                          s[j]=s[j-1];
                                          s[j-1]='S';
                                          }
                                else if(abs(X-x)<abs(Y-y))
                                {
                                     if(Y-y>0)
                                     {
                                              y-=j;
                                              s[j]=s[j-1];
                                              s[j-1]='S';
                                              j++;
                                              y+=j;
                                              s[j]=s[j-1];
                                              s[j-1]='N';
                                              }
                                     else
                                     {
                                              y+=j;
                                              s[j]=s[j-1];
                                              s[j-1]='N';
                                              j++;
                                              y-=j;
                                              s[j]=s[j-1];
                                              s[j-1]='S';
                                              }
                                     }
                                else
                                {
                                     if(X-x>0)
                                     {
                                              x-=j;
                                              s[j]=s[j-1];
                                              s[j-1]='W';
                                              j++;
                                              x+=j;
                                              s[j]=s[j-1];
                                              s[j-1]='E';
                                              }
                                     else
                                     {
                                              x+=j;
                                              s[j]=s[j-1];
                                              s[j-1]='E';
                                              j++;
                                              x-=j;
                                              s[j]=s[j-1];
                                              s[j-1]='W';
                                              }
                                     }
                                j++;
                                }
                     s[j-1]=0;
                     beta<<"Case #"<<i<<": "<<s<<endl;;
                     }
    
    cin>>i;
    return 0;
    }
