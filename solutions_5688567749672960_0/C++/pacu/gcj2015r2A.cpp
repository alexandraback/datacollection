#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int dig(long long p)
{
	if(p<10) return 1;
	return 1+dig(p/10);
}
long long pw(long long p)
{
	long long k = 1;
	while((10*k)<=p) k*=10;
	return k;
}
int A[20];
long long rev(long long x)
{
	int c = 0;
	while(x>0)
	{
		A[c++] = x%10;
		x /= 10;
	}
	for(int i=0;i<c;i++)
		x = 10*x + A[i];
	return x;
}
int ans[1000001];
int test(long long x)
{
	ans[0] = 0;
	for(int i=1;i<=x;i++)
	{
		ans[i] = 1+ans[i-1];
		int y = rev(i);
		if((y<i)&&(i%10))
			ans[i] = min(ans[i],1+ans[y]);
	}
	return ans[x];
}

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);

	int T;
	long long N;
	cin >> T;
	test(1000000);
	for(int i=0;i<100;i++)
	{
		cin >> N;
		cout << "Case #" << i+1 << ": " << ans[N] << "\n";
	}
}