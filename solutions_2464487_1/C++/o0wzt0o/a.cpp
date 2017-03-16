#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
long long r,t;
double pi=acos(-1);
int main()
{
        int i,j,k,tot,ttl;
        cin>>tot;
        for(ttl=1;ttl<=tot;ttl++)
        {
            cin>>r>>t;
            long long low=0,up=min(t/r/2+2,(long long)(sqrt(t/2)+1));
            while(up!=low+1)
            {
                long long mid=(low+up)>>1;
                if((((r+mid)<<1)-1)*mid<=t)
                    low=mid;
                else up=mid;
            }
            cout<<"Case #"<<ttl<<": "<<low<<endl;
        }
        
        return 0;
}
