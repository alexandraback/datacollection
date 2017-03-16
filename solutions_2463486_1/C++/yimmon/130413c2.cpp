/*========================================================================
#   FileName: 130413c2.cpp
#     Author: YIMMON
#      Email: yimmon.zhuang@gmail.com
#   HomePage: http://qr.ae/8DMzu
# LastChange: 2013-04-13 12:13:46
========================================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
#define X 10000007LL

int T, cnt = 40, ans;
LL a, b;
LL num[40] = {1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,44944LL,1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL,100000020000001LL};

/* 
inline int judge(LL x)
{
	char str[20];
	sprintf(str, "%lld", x);
	int len = strlen(str);
	for(int i = 0; i < len/2; ++i)
		if(str[i] != str[len-1-i])
			return 0;
	return 1;
}

inline void init()
{
	cnt = 0;
	for(LL i = 1; i < X; ++i)
		if(judge(i) && judge(i*i))
			num[cnt++] = i*i;
}
*/

int main(int argc, char **argv)
{
	//init();
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		scanf("%lld%lld", &a, &b);
		ans = 0;
		for(int i = 0; i < cnt; ++i)
			if(num[i] >= a && num[i] <= b)
				ans++;
		printf("Case #%d: %d\n", cas, ans);
	}

	return 0;
}
