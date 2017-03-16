#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

int power10[10];

void preCalculate()
{
	power10[0] = 1;
	for (int i=1;i<=9;i++)
		power10[i] = power10[i-1]*10;
	return ;
}

vector<int> palindromes;
vector<long long> fairsquare;

int oddLength(int num,int len,int rev)
{
	return num/10*power10[len] + rev;
}
int evenLength(int num,int len,int rev)
{
	return num*power10[len] + rev;
}
bool isPalindrome(long long num)
{
	if (num == 0)return 1;
	if (num%10 == 0)return 0;
	long long rev=0;
	for (long long temp=num;temp;temp/=10)
		rev = rev*10 + temp%10;
	return num == rev;
}

void getPals(int num,int len,int rev)
{
	if (len > 0){
		int v1 = oddLength(num,len,rev);
		int v2 = evenLength(num,len,rev);
		if (v1 < power10[7]){
			palindromes.push_back(v1);
			long long fair = (long long)v1*v1;
			if (isPalindrome(fair))
				fairsquare.push_back(fair);
		}
		if (v2 < power10[7]){
			palindromes.push_back(v2);
			long long fair = (long long)v2*v2;
			if (isPalindrome(fair))
				fairsquare.push_back(fair);
		}
	}
	if (len == 4)return ;
	for (int digit=(len==0);digit<=9;digit++)
		getPals(num*10+digit,len+1,digit*power10[len]+rev);
	return ;
}

int main()
{
	freopen("fairsquare.in","r",stdin);
	freopen("fairsquare.out","w",stdout);
	int c,c2;
	preCalculate();
	getPals(0,0,0);
	sort(palindromes.begin(),palindromes.end());
	sort(fairsquare.begin(),fairsquare.end());
	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++){
		printf("Case #%d: ",test);
		int ret=0;
		long long A,B;
		scanf("%lld%lld",&A,&B);
		for (c=0;c<(int)fairsquare.size();c++)
			if (fairsquare[c]>=A && fairsquare[c]<=B)
				ret++;
		printf("%d\n",ret);
	}
	
	return 0;
}
