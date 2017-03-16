#include<iostream>
#include<math.h>
#define REP(i,n) for(i=0;i<n;i++)

using namespace std;


int main()
{
	int T=0;
	cin>>T;
	int c,i;
	int N;
	int max_a,max_b,maxb;
	int* a;
	int* b;
	int* completion;
	int stars;
	int attempts;
	REP(c,T)
	{
		cin>>N;
		completion=new int[N];
		a=new int[N];
		b=new int[N];
		stars=0;
		attempts=0;
		REP(i,N)
		{
			cin>>a[i]>>b[i];
			completion[i]=0;
		}
		while(stars<=2*N)
		{
			maxb=0;
			max_b=-1;
			max_a=-1;
			REP(i,N)
				if(b[i]<=stars&&completion[i]==0) 
				{
						max_b=i;
						//cout<<i<<" "<<b[i]<<endl;
						break;
				}
			if(max_b==-1)
			{
				REP(i,N)
					if(b[i]<=stars&&completion[i]==1)
					{
							max_b=i;
							break;
					}
				if(max_b==-1)
				{
					REP(i,N)
						if(a[i]<=stars&&completion[i]==0&&b[i]>=maxb)
						{
								max_a=i;
								maxb=b[i];
						}
					if(max_a==-1)
					{
						if(stars<2*N) attempts=-1;
						break;
					}
					else
					{
						completion[max_a]=1;
						stars++;
						attempts++;
					}
				}
				else
				{
					completion[max_b]=2;
					stars++;
					attempts++;
				}
			}
			else
			{
				completion[max_b]=2;
				stars+=2;
				attempts++;
			}
			//cout<<stars;
		}
		if(attempts==-1) printf("Case #%d: Too Bad\n",c+1);
		else printf("Case #%d: %d\n",c+1,attempts);
	}
	return 0;
}