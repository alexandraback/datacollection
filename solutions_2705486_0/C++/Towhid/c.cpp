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

string dict[521200];
char str[100];

vector<string> mat[55];
int memo[55][6];

int len;

void getmat(string s)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		int lst = -5;
		int l2 = s.length() - 1;
		for(j = 0; j < l2; j++)
		{
			if(i + j >= len)
				break;
			if(str[i + j] != s[j])
			{
				if((j - lst) < 5)
					break;
				else
					lst = j;
			}
		}
		if(j == l2)
		{
			mat[i].push_back(s);
		}
	}
}

int go(int st, int fp)
{
	if(st == len)
	{
		return 0; 
	}
	int ret = memo[st][fp];

	if(ret != -1)
		return ret;

	int i, j;
	int tmp = len + 1;
	int tmp2;
	int tt = mat[st].size();
	for(i = 0; i < tt; i++)
	{
		string s = mat[st][i]; 
		int ll = s.length() - 1;
		int ffp = -1;
		int llp = -1;
		int cnt = 0;
		for(j = 0; j < ll; j++)
		{
			if(str[st + j] != s[j])
			{
				if(ffp == -1)
					ffp = j;
				llp = j;
				cnt++;
			}
		}
		if(ffp == -1)
		{
			int nfp = fp - ll;
			if(nfp < 0)
				nfp = 0;
			tmp2 = cnt + go(st + ll, nfp);
		}
		else
		{
			if(ffp >= fp)
			{
				int nfp = ll - llp;
				nfp = 5 - nfp;
				if(nfp < 0)
					nfp = 0;
				tmp2 = cnt + go(st + ll, nfp);
			}
			else
			{
				continue;
			}
		}
		if(tmp2 < tmp)
			tmp = tmp2;
	}
	ret = tmp;
	memo[st][fp] = ret;
	return ret;
}


int main()
{
	freopen("C-small-attempt1.in", "rt", stdin);
	freopen("C-small1.out", "wt", stdout);

	//freopen("C-large-1.in", "rt", stdin);
	//freopen("C-large-1.out", "wt", stdout);

	int i, j, k, kase, inp;
	
	FILE *fp = fopen("garbled_email_dictionary.txt", "rt");
	i = 0;
	while(fgets(str, 100, fp))
	{
		dict[i] = str;
		i++;
	}
	
	scanf("%d", &inp);
	int tot = 521196;
	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%s", str);
		len = strlen(str);
		for(i = 0; i < len; i++)
			mat[i].clear();
		for(i = 0; i < tot; i++)
		{
			getmat(dict[i]);
		}
		memset(memo, -1, sizeof(memo));
		int res = go(0, 0);
		printf("Case #%d: %d\n", kase, res);
	}

	return 0;
}
