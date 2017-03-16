#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int flip(char s[] , int end , char target)
{
	int ok = 1;
	for (int i = 0; i <= end; i ++)
		if (s[i] == target) {ok = 0; break;}
	if (ok == 1)
	{
		for (int i = 0; i <= end; i ++) s[i] = target;
		return 1;
	}
	while (end >= 0 && s[end] == target) end --;
	if (end < 0) return 0;
	return 1 + flip(s , end , target == '+'? '-': '+');
}
int main()
{
	freopen("B-small-attempt0.in" , "r" , stdin);
	freopen("B-small-attempt0.out" , "w" , stdout);
	//freopen("B-large.in" , "r" , stdin);
	//freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
		char s[200];
		scanf("%s" , s);
		int L = strlen(s);
		int res = 0;
		res = flip(s , L-1 , '+');
		printf("%d\n" , res);
    }
    return 0;
}