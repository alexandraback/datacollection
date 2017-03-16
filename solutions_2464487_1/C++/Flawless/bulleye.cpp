// Shashank Jain
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#define LL long long int
#define LD long double
using namespace std;
LL binary_search(LL t,LL r,LL LIM)
{
    	LL k,mid,first,end;
    	first=0;
	end=LIM;
        while(first<=end)
        {
                mid=(first+end)/2;
                if(mid==first)
                {
                        mid=end;
                        k=2*mid*mid+mid*(r+r-1);
                        if(k<=t)
                        	return end;
                	return first;
                }
                k=2*mid*mid+mid*(r+r-1);
                if(k>t)
                	end=mid-1;
                else
                	first=mid;
                
        }
        return 0;
}
int main()
{
	int tc,ans,i;
	LL r,t,d,first,sum,s,e,mid;
	scanf("%d",&tc);
	i=1;
	while(i<=tc)
	{
		cin>>r>>t;
		LL big=1000000000000000000;
		LL small=1000000000;
		LL m=big/r;
		ans=binary_search(t,r,(m<=small?m:small));
		printf("Case #%d: %d\n",i,ans);
		i++;
	}
	return 0;
}
