#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int ca,t;
long long ans,low,high,v;
double total,r,p;

void work()
{
	cin >>r >>p;
	
	low=1;high=1000000000;v=1;
	
	while (low<=high)
	{
		ans=(low+high)/2;
		
		//cout <<ans <<endl;
		
		total=ans*2*r;
		total+=ans*ans*2;
		total-=ans;
		
		//cout <<total <<endl;
		
		if (total>p) 
		{
			high=ans-1;
		}
		else 
		{
			v=ans;
			low=ans+1;
		}
	}
	
	printf("Case #%d: %lld\n",ca,v);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	cin >>t;
	for (ca=1;ca<=t;++ca) work();
	
	fclose(stdin);
    fclose(stdout);
    return 0;
}
