#include<iostream>
#include<cmath>
using namespace std;

using namespace std;
int main()
{
    	int t;
        long long r,x,p;
        scanf("%d",&t);
        for(int i=0;i<t;i++)
        {
                
                scanf("%lld%lld",&r,&p);
                x=((-1*(2*r-1))+ (long long)sqrt((2*r-1)*(2*r-1)+8*p));
                x=x/4;
                printf("Case #%d: %lld\n",i+1,x);
        }
        return 0;
}

