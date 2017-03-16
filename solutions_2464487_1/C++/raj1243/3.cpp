#include<iostream>
#include<stdio.h>
# define s(n) scanf("%d",&n)

using namespace std;

unsigned long long int BSearch(unsigned long long int n,unsigned long long int t,unsigned long long int r)
{
        unsigned long long int low=1,high=n, mid;
        while(low <= high)
        {
                mid = (low + high)/2;
                if( (2*mid*mid+(2*r-1)*mid) <= t && (2*(mid+1)*(mid+1)+(2*r-1)*(mid+1))>t)
                {
                        return mid;
                }
                else if( (2*mid*mid+(2*r-1)*mid) < t && (2*(mid+1)*(mid+1)+(2*r-1)*(mid+1))<t)
                {
					low=mid+1;
				}
				else if( (2*mid*mid+(2*r-1)*mid) < t && (2*(mid+1)*(mid+1)+(2*r-1)*(mid+1))==t)
				{
					return mid+1;
				}
                else if((2*mid*mid+(2*r-1)*mid) > t)
                {
                        high = mid-1;
                }

        }
}

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		unsigned long long int r,t,ans,x=1000000100;
		cin>>r>>t;
		if(t/r>1000000100)
		ans=BSearch(x,t,r);
		else
		ans=BSearch(t/r,t,r);


		printf("Case #%d: %llu\n",i+1,ans);

	}
}
