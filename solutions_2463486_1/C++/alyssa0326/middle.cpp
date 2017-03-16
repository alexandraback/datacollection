#include<cstdio>
#include <cmath>
#include<cstring>
#include<vector>
using namespace std;
vector<long long > numbers;
char s[20];
int search(long long X)
{
	for (int i = 0 ;i < numbers.size();i++)
		if (numbers[i]>X)
		{
			return i;
		}
	return numbers.size();
}
void run()
{
	long long A,B;
	scanf("%lld %lld\n",&A,&B);
	printf("%d",search(B)-search(A-1));
}
bool reversecheck(long long x)
{
	sprintf(s,"%lld",x);
	int l = strlen(s);
	for(int i=0;i<l/2;i++)
		if(s[i]!=s[l-i-1])
			return false;
	return true;
}
void init()
{
	int M = 10000000;
	for (int i = 0 ;i < M ;i ++)
	if(reversecheck(i))
	{
		long long b = (long long)i*i;
		if (reversecheck(b))
			numbers.push_back(b);
	}
}
int main()
{
	int N;
	scanf("%d\n",&N);
	init();

	for (int Case = 1 ; Case <= N ; Case++)
	{
		printf("Case #%d: ",Case);
		run();
		putchar('\n');
	}
	return 0;
}
