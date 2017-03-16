#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


int t;
long long n;
bool p[11];
int m;
int main()
{
    int i,j,k,times;
    long long xx;
    long long dat;
    int yy;
    char d[21];
    int len;
    freopen("A-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>n;
        if(n==0)
        {
            cout<<"Case #"<<times<<": INSOMNIA"<<endl;
            continue;
        }
        
        memset(p,0,sizeof(p));
        m=0;
        dat=n;
        n=0;
        do
        {
            n+=dat;
            
            sprintf(d,"%d",n);
            len=strlen(d);
            for(i=0;i<len;i++)
            {
                if(p[d[i]-'0']==0)
                {
                    m++;
                    p[d[i]-'0']=1;
                }
            }
            
        }while(m<10);
        
        cout<<"Case #"<<times<<": "<<n<<endl;
    }
    return 0;
}
