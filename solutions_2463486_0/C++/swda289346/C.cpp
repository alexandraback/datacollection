#include <stdio.h>
#include <vector>
#define N 10000000
using namespace std;

bool isPalindrome(long long get)
{
	vector<int> tmp;
	while (get)
	{
		tmp.push_back(get%10);
		get /= 10;
	}
	for (int i=0, j=tmp.size()-1;i<j;++i, --j)
		if (tmp[i]!=tmp[j])
			return false;
	return true;
}

int main()
{
	int t;
	int a, b;
	vector<long long> table;
	vector<long long>::iterator pa, pb;
	for (int i=1;i<=N;++i)
		if (isPalindrome(i) && isPalindrome(((long long) i)*i))
			table.push_back(((long long) i)*i);
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		scanf("%d%d", &a, &b);
		pa = lower_bound(table.begin(), table.end(), a);
		pb = lower_bound(table.begin(), table.end(), b+1);
		printf("Case #%d: %d\n", i, pb-pa);
	}
	return 0;
}
