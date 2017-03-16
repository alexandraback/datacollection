#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	string key[40] = {"1","4","9","121","484","10201","12321","14641","40804","44944","1002001","1234321","4008004",
			"100020001","102030201","104060401","121242121","123454321","125686521","400080004","404090404",
			"10000200001","10221412201","12102420121","12345654321","40000800004","1000002000001","1002003002001",
			"1004006004001","1020304030201","1022325232201","1024348434201","1210024200121","1212225222121",
			"1214428244121","1232346432321","1234567654321","4000008000004","4004009004004","999999999999999"};
	long long int T, k;
	string a, b;
	int start, end, i;
	cin >> T;
	for (k = 1; k <= T; k++)
	{
		cin >> a >> b;
		for (i = 0; i < 40; i++)
			if (a.length() < key[i].length() || (a.length() == key[i].length() && a < key[i]))
				break;
		start = i;
		if (a == key[i-1])
			start--;
		for (; i < 40; i++)
			if (b.length() < key[i].length() || (b.length() == key[i].length() && b < key[i]))
				break;
		end = i-1;
		printf("Case #%lld: %d\n", k, end - start + 1);
	}
	return 0;
}
