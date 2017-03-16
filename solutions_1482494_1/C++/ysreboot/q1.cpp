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

int getmin(int* x,int len)
{
    int min=0;
    for(int i=1;i<len;i++)
    {
            min=x[i]<x[min]?i:min;
    }
    return min;
}  
            
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    
    int T;
    
    cin>>T;
    
    int t=1;
    
    while(t<=T)
    {
            int n;
            int y=0;
            cin>>n;
            
            int a[1000];
            int b[1000];
            
            for(int i=0;i<n;i++)
            {
                    cin>>a[i]>>b[i];
            }
            
            int flag=1;
            
            int stars=0;
            
            for(int i=0;i<n;i++)
            {
                    int x=getmin(b,n);
                                  
                    while(stars<b[x])
                    {
                        int z=-1;
                        
                        for(int k=0;k<n;k++)
                        {
                                if(a[k]<=stars)
                                {
                                               if(z<0)
                                                        z=k;
                                               else if(b[k]>b[z])
                                                            z=k;
                                }
                        }
                        
                        if(a[z]==2222)
                        {
                            flag=0;
                            break;
                        }
                        if(a[z]<=stars)
                        {
                                   stars++;
                                   a[z]=2222;
                                   y++;
                        }
                        else
                        {
                            flag=0;
                            break;
                        }
                        
                    }
                    
                    if(!flag)
                             break;
                    
                   if(a[x]==2222)
                       stars+=1;
                   else
                   {
                       stars+=2;
                       a[x]=2222;
                   }
                   
                   b[x]=2222;
                   y++;
            }
             
                     
               
               
               
               
            if(flag)
                    cout<<"Case #"<<t<<": "<<y;  
            else
                    cout<<"Case #"<<t<<": Too Bad";  
            if(t!=T)
            cout<<endl;
    t++;           
    }
               
               
               //system("pause");
    return 0;
    
}
