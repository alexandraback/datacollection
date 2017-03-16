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
long long r,p,total,ans;

void work()
{
	cin >>r >>p;
	
	ans=1;
	while (true)
	{
		total=ans*2*r;
		total+=ans*ans*2;
		total-=ans;
		
		//cout <<total <<endl;
		
		if (total>p) break;
		else ++ans;
	}
	
	ans--;
	printf("Case #%d: %lld\n",ca,ans);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	cin >>t;
	for (ca=1;ca<=t;++ca) work();
	
	fclose(stdin);
    fclose(stdout);
    return 0;
}
