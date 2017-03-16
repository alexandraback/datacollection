#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

bool vowels(char ch)
{
	bool ret = false;
	switch(ch)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			ret = true;
	}
	return ret;
}

char s[1000010];

int main()
{
	//init();
	
	//printf("Input File Name ?");
	//char FileName[128];
	//scanf("%s", FileName);
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		int L, n, rec = -1;
		scanf("%s%d", s, &n);
		L = strlen(s);
		
		int i, ans = 0, cur = -1;
		for(i = 0; i < L; i ++)
		{
			if(vowels(s[i]))
			{
				rec = i;
			}
			if(i - rec >= n)cur = i;
			if(cur-n+2>0)
			{
				ans += (cur-n+2);
			}
		}
		//printf("%d\n", cur);
		printf("Case #%d: %d\n", Case, ans);
	}
	
	return 0;
}
