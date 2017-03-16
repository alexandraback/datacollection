#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <utility>
#include <memory>
#include <malloc.h>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

typedef long long ll;

const int n = 100000000;

long long a[49] = {0L, 1L, 4L, 9L, 121L, 484L, 10201L, 12321L, 14641L, 40804L, 44944L, 1002001L, 1234321L, 4008004L, 100020001L, 102030201L, 104060401L, 121242121L, 123454321L, 125686521L, 400080004L, 404090404L, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L, 100000020000001L, 100220141022001L, 102012040210201L, 102234363432201L, 121000242000121L, 121242363242121L, 123212464212321L, 123456787654321L, 400000080000004L};

//char a[n];

char q[100];

bool ispall(long long w)
{
	q[0] = 0;
	int l = 0;
	while (w != 0)
	{
		q[l] = w % 10;
		w /= 10;
		++l;
	}
	for (int i = 0; i < l; ++i)
		if (q[i] != q[l - 1 - i])
			return false;
	return true;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long long w, b;
		cin >> w >> b;
		int s = 0;
		for (int j = 0; j < 49; ++j)
			if (w <= a[j] && a[j] <= b)
				++s;
		cout << "Case #" << i + 1 << ": " << s << endl;
	}
	/*
	for (int i = 0; i < n; ++i)
		if (ispall(i) && ispall((long long)i * i))
			cout << (long long)i * i << "L, ";
	*/
	return 0;
}