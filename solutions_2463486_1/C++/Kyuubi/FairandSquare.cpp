#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <climits>
#include <map>


#define MAXA 72500000
#define MOD 1000000007
#define SIZ  101

using namespace std;


char arr[MAXA],*ptr;
long long t,ret;
long long palins[] = {1, 4, 9 ,121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 10000000200000001, 10002000300020001, 10004000600040001};
int tpCount;

inline long long get_int()
{
	ret =0;
	while ( !(*ptr >= '0' && *ptr <= '9'))
		ptr++;
	while (*ptr >= '0' && *ptr<= '9') {
		ret = ret*10 + (*ptr - '0');
		ptr++;
	}
	return ret;
}

int main()
{
	fread(arr,sizeof(char),MAXA,stdin);
	ptr = arr;
	t = get_int();
	long long a,b;
	int count1,count2;
	for(int tt = 1; tt<= t;tt++)
	{
		count1 = 0;
		count2 = 0;
		a = get_int();
		b = get_int();
		for(count1 = 0;palins[count1] < a;count1++);
		for(count2 = 0;palins[count2] <= b;count2++);
		cout << "Case #"<< tt << ": " << count2-count1 << endl;
	}
	return 0;
}