#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

int main()
{
    ifstream alpha("A-small-attempt0.in");
    ofstream beta("output.txt");
    
    int T;
    alpha>>T;
    int i;
    string s;
    int n;
    int k,l;
    int n_value;
    
    for(i=1;i<=T;i++)
    {
                     n_value=0;
                     alpha>>s>>n;
                     for(k=0;k<=s.length()-n;k++)
                     {
                                                for(l=k+n;l<=s.length();l++)
                                                { 
                                                                         string ss=s.substr(k,l-k);
                                                                         int u=0;
                                                                         int v=0;
                                                                         
                                                                         for(u=0;u<ss.length();u++)
                                                                         {
                                                                                                   if(v==n)
                                                                                                   break;
                                                                                                   if(ss[u]!='a' && ss[u]!='e' && ss[u]!='i' && ss[u]!='o' && ss[u]!='u')
                                                                                                   v++;
                                                                                                   else
                                                                                                   v=0;
                                                                                                   }
                                                                         if(v==n)
                                                                         n_value++;
                                                                         
                                                                         
                                                                         }
                                                }
                     beta<<"Case #"<<i<<": "<<n_value<<endl;
                     
                     }
    
    
    return 0;
    }
