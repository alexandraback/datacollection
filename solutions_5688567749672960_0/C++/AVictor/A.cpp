#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const int size = 1000000;
int ans[size+1];

int main()
{
	for(int i=0;i<=size;i++) ans[i] = size+1;
	ans[1] = 1;
	for(int i=1;i<=size;i++)
	{
		ans[i+1] = min(ans[i+1], ans[i]+1);
		int a = i;
		int b = 0;
		while (a)
		{
			b = 10*b + a%10;
			a/=10;
		}
		if (b <= size) ans[b] = min(ans[b], ans[i]+1);
	}
	
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		int N;
		scanf("%d", &N);
		printf("Case #%d: %d\n", test_num, ans[N]);	
	}
	
	return 0;
}
