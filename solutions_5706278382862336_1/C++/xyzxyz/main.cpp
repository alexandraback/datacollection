#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:116777216")
#define MAXN 100100

using namespace std;

long long a,b,g;

long long gcd(long long l,long long r){
    if(r==0)
        return l;
    return gcd(r,l%r);
    }

int t;

long double x[45],sol,sag;

long long iki[45];


int main(int argc, char *argv[])
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d",&t);
    
    x[0]=1;
    iki[0]=1;
     
    for(int i=1;i<=40;i++)
        x[i]=x[i-1]/((long double)2.0),iki[i]=iki[i-1]*((long long)2);
    
    bool f=0,z;
    
    
    for(int o=1;o<=t;o++){
        
        cout<<"Case #"<<o<<": ";
        
        scanf("%lld/%lld",&a,&b);
        ///cout<<a<<" "<<b<<endl;
        f=z=0;
        g=gcd(a,b);
        a=a/g;
        b=b/g;
        
        
        
        sol=(long double)a;
        sag=(long double)b;
        
        sol=sol/sag;
        
        for(int i=0;i<=40;i++)
            if(iki[i]==b){
                f=1;
                break;
                }
        
        if(f==0){
            cout<<"impossible"<<endl;
            continue;
            }
        
        for(int i=0;i<=40;i++)
            if(sol>=x[i])
                {
                    cout<<i<<endl;
                    break;
                }
        
        }    
    
    
    
    
   // system("pause");
    return 0;
}
