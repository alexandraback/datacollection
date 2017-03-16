#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#include <ctime>
#include <cfloat>

using namespace std;
#define SZ 1000005

char str[SZ];
long long cont[SZ];
int rcont[SZ];
long long res[SZ];

bool isvowel(char ch)
{
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}

int chk(int a, int b)
{
	int mx = 0;
	int cnt = 0;
	int i;
	for(i = a; i <= b; i++)
	{
		if(isvowel(str[i]))
			cnt = 0;
		else
			cnt++;
		if(cnt > mx)
			mx = cnt;
	}
	return mx;
}

int main()
{
	//freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("A-small.out", "wt", stdout);


	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);

	int inp, kase, i, j, k, a, n;
	scanf("%d", &inp);
	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%s %d", str, &n);
		int len = strlen(str);
		if(isvowel(str[0]))
			cont[0] = 0;
		else
			cont[0] = 1;
		for(i = 0; i < len; i++)
		{
			if(isvowel(str[i]))
			{
				cont[i] = 0;
			}
			else
			{
				cont[i] = cont[i - 1] + 1;
			}
		}
		if(cont[0] >= n)
		{
			res[0] = 1;
		}
		else
		{
			res[0] = 0;
		}
		long long tot = res[0];
		for(i = 1; i < len; i++)
		{
			if(cont[i] >= n)
			{
				res[i] = (i - n + 2); 
			}
			else
			{
				res[i] = res[i - 1];
			}
			tot += res[i];
		}
		printf("Case #%d: %lld\n", kase, tot);
	}

	return 0;
}

