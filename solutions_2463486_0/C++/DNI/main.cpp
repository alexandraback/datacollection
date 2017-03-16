
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;


#define MAX_N (long long)1000  * 1000  * 10 + 10

//int ar[MAX_N] = {0};

string str;
char buff[100];

bool IsPalindrom(long long n)
{
	sprintf(buff,"%lld", n);
	str.assign(buff);
	for(int i = 0; i < str.size()/2; i++)
		if(str[i] != str[str.size() - 1 - i])
			return false;
	return true;
}

vector<long long> ar;

void calc()
{
	ar.reserve(MAX_N);
	for(long long  i = 1; i < MAX_N; i++)
	{
		if(IsPalindrom(i) &&  IsPalindrom(i*i))
		{
			ar.push_back(i*i);
		}
	}
}


//int searchA(long long A)
//{
//	int a = 0, b = ar.size()-1;
//	for(int i = 0; i < 1000; i++)
//	{
//		int c = (a + b) /2;
//		if(ar[c] >= A)
//		{
//			b = c;
//		}
//		else
//		{
//			a = c;
//		}
//	}
//	return a;
//}
//
//int searchB(long long B)
//{
//	int a = 0, b = ar.size()-1;
//	for(int i = 0; i < 1000; i++)
//	{
//		int c = (a + b) /2;
//		if(ar[c] == B)
//			return c;
//
//		if(ar[c] > B)
//		{
//			b = c;
//		}
//		else
//		{
//			a = c;
//		}
//	}
//	return b;
//}

long long get_res(long long A, long long B)
{
	long long res = 0;
	for(int i = 0; i < ar.size(); i++)
		if(ar[i] >= A && ar[i] <= B)
			res++;
	return res;
}

int main()
{
	freopen("output.out", "w", stdout);
	freopen("input.in", "r", stdin);

	calc();

	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		long long A, B, r;
		scanf("%lld%lld", &A, &B);
		r = get_res(A, B);
		printf("Case #%d: %lld", tt+1, r);

		if(tt != t-1)
			printf("\n");
	}
	return 0;
}