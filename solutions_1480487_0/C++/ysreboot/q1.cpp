#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
            
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small.out","w",stdout);
    
    int T;
    
    cin>>T;
    
    int t=1;
    
    while(t<=T)
    {
            int n;
            cin>>n;
            float s[201];
            float m[201];
            
            float sum=0;
            
            for(int i=0;i<n;i++)
            {
                    cin>>s[i];
                    sum+=s[i];
            }
            
            cout<<"Case #"<<t<<":";
            int flag=0;
            float sumn=0;
            int countn=n;
            for(int i=0;i<n;i++)
            {
                    m[i] = ( (sum*2)/n-s[i] ) * 100 / sum;  
                    if(m[i]<0)
                    {
                              sumn+=m[i];
                              m[i]=0;
                              countn-=1;
                              flag=1;
                    }
            }
            
            if(flag==1)
            {
                       for(int i=0;i<n;i++)
                       {
                               if(m[i]>0)
                               {
                                   m[i]+=sumn/countn;      
                               }
                       }
            }
            for(int i=0;i<n;i++)
            {
             printf(" %6f",m[i]);
            }
            
            cout<<endl;
            
                t++;           
    }
               
               
//    system("pause");
    return 0;
    
}
