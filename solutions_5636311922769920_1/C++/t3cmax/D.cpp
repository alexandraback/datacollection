#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


int t;

int k,c,s;

int main()
{
    int i,j,times;
    
    freopen("D-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>k>>c>>s;
        
        if(c==1)
        {
            if(s<k)
            {
                cout<<"Case #"<<times<<": IMPOSSIBLE"<<endl;
            }
            else
            {
                cout<<"Case #"<<times<<":";
                for(i=1;i<=k;i++)
                {
                    cout<<' '<<i;
                }
                cout<<endl;
            }
            continue;
        }
        
        if(k==1)
        {
            cout<<"Case #"<<times<<": 1"<<endl;
            continue;
        }
        
        if(s<k-1)
        {
            cout<<"Case #"<<times<<": IMPOSSIBLE"<<endl;
            continue;
        }
        
        cout<<"Case #"<<times<<":";
        for(i=2;i<=k;i++)
        {
            cout<<' '<<i;
        }
        cout<<endl;
        
        
    }
    
    
    
    return 0;
}
