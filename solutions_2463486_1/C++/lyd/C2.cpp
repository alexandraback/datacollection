#include <stdio.h>
#include <string.h>
#include <math.h>

int sn = 48;
static char* s[]={
	"1",
	"4",
	"9",
	"121",
	"484",
	"10201",
	"12321",
	"14641",
	"40804",
	"44944",
	"1002001",
	"1234321",
	"4008004",
	"100020001",
	"102030201",
	"104060401",
	"121242121",
	"123454321",
	"125686521",
	"400080004",
	"404090404",
	"10000200001",
	"10221412201",
	"12102420121",
	"12345654321",
	"40000800004",
	"1000002000001",
	"1002003002001",
	"1004006004001",
	"1020304030201",
	"1022325232201",
	"1024348434201",
	"1210024200121",
	"1212225222121",
	"1214428244121",
	"1232346432321",
	"1234567654321",
	"4000008000004",
	"4004009004004",
	"100000020000001",
	"100220141022001",
	"102012040210201",
	"102234363432201",
	"121000242000121",
	"121242363242121",
	"123212464212321",
	"123456787654321",
	"400000080000004"
};

long long A,B;

bool isRe(int n)
{
	static char s[20];
	snprintf(s,sizeof(s),"%d",n);
	int len = strlen(s);
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i]) return false;
	}
	return true;
}

bool isR(int n)
{
	int sqrN = (int)(sqrt(n+0.0) + 1e-7);
	if( sqrN * sqrN != n ) return false;
	return isRe(sqrN) && isRe(n);
}

int cal(long long n)
{
	static char str[20];
	snprintf(str,sizeof(str),"%lld",n);
	int len = strlen(str);
	int cnt = 0;
	for(int i=0;i<sn;i++)
	{
		int len_i = strlen(s[i]);
		if( len_i < len || len_i == len && strcmp(str,s[i]) >= 0 )
			cnt++;
		else
			break;
	}
	return cnt;
}

int main()
{
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&A,&B);
		int ans = cal(B) - cal(A-1);
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}

