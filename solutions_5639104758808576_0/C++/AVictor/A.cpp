#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		int ans = 0;
		int S;
		cin >> S;
		string r;
		cin >> r;
		int cur = 0;
		for(int i=0;i<=S;i++)
		{
			int x = r[i] - '0';
			if (!x) continue;
			if (cur < i)
			{
				ans += i-cur;
				cur = i;
			}
			cur += x;	
		}
		printf("Case #%d: %d\n", test_num, ans);	
	}
	
	return 0;
}
