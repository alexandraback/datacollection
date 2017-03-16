///*
// * test.cpp
// *
// *  Created on: 2013-04-29
// *      Author: fudq
// */
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <ctime>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <set>
//#include <map>
//#include <stack>
//#include <string>
//#include <vector>
//#include <deque>
//#include <list>
//#include <functional>
//#include <numeric>
//#include <cctype>
//using namespace std;
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//    freopen("testin.txt","r",stdin);
////  freopen("testout.txt","w",stdout);
//#endif
//    return 0;
//}


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxl 1000005
char st[maxl];
int len;
int f[maxl];
char vowel[] = "aeiou";
int n;
bool is_cons(char a) {
	for (int i = 0; i < 5; i++)
		if (a == vowel[i])
			return false;
	return true;
}
long long work() {
	len = strlen(st);
	if (n > len)
		return 0;
	int temp = -1;
	if (is_cons(st[0]))
		f[0] = 1;
	else f[0] = 0;
	int i = 1;
	while (i < len && f[i - 1] < n) {
		if (is_cons(st[i]))
			f[i] = f[i - 1] + 1;
		else f[i] = 0;
		i++;
	}
	if (f[i - 1] < n)
		return 0;
	temp = i - n;
	long long ret = temp + 1;
	for (; i < len; i++) {
		if (is_cons(st[i]))
			f[i] = f[i - 1] + 1;
		else f[i] = 0;
		if (f[i] >= n)
			temp = i - n + 1;
		ret += temp + 1;
	}
	return ret;
}
int main() {
//	freopen("testin.txt", "r", stdin);
//	freopen("testout.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%d: ", i + 1);
		scanf("%s", st);
		scanf("%d", &n);
		printf("%lld\n", work());
	}
	return 0;
}
