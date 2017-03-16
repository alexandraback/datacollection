#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

const int MAX = 105;
const int MAXL = 27;
char markName[MAX][MAXL];
int len[MAX];
int n;
bool exist[MAXL];
bool shouldAdj[MAX][MAX];
int repeatNum[MAX];
int num;
int singleName[MAXL];
bool mid[MAXL];
bool head[MAXL];
bool tail[MAXL];
bool haveFather[MAX];
bool visited[MAX];
long long p[MAX];

long long Dfs(int v)
{
	int i;
	visited[v] = true;
	for (i = 0; i < num; ++ i)
	{
		if (!visited[i] && shouldAdj[v][i])
		{
			return Dfs(i)*p[repeatNum[v]]%1000000007;
		}
	}
	return p[repeatNum[v]];
}

int main()
{
	//freopen("B-small-attempt2.in", "r", stdin);
	//freopen("B-small-attempt2.out", "w", stdout);


	int nCase;
	int t;
	int i, j, k;
	char cur;
	bool cando;
	bool isRepeat;
	int length;
	char name[MAXL];
	int iSingle;
	long long ans;
	int cnt;
	string theName;

	p[0] = 1;
	for (i = 1; i < MAX; ++ i)
	{
		p[i] = i * p[i-1] % 1000000007;
	}

	cin >> nCase;
	//scanf("%d", &nCase);
	for (t = 1; t <= nCase; ++ t)
	{	
		cin >> n;
		//scanf("%d", &n);
		cando = true;
		num = 0;
		for (j = 0; j < MAXL; ++ j)
		{
			singleName[j] = -1;
		}
		for (i = 0; i < n; ++ i)
		{
			for (j = 0; j < MAXL; ++ j)
			{
				exist[j] = false;
			}
			cin >> theName;
			length = 0;
			for (j = 0; j < theName.length(); ++ j)
			{
				if (!cando)
				{
					break;
				}
				cur = theName[j];
				if (length > 0 && name[length-1] == cur)
				{
					continue;
				}
				if (exist[cur-'a'])
				{
					cando = false;
					continue;
				}
				exist[cur-'a'] = true;
				name[length] = cur;
				length++;
			}
			//while (true)
			//{
			//	cin.get(cur);
			//	//scanf(" %c", &cur);
			//	if (cur < 'a' || cur > 'z')
			//	{
			//		break;
			//	}
			//	
			//}
			if (length == 1)
			{
				iSingle = singleName[name[0]-'a'];
				if (iSingle != -1)
				{
					repeatNum[iSingle]++;
				}
				else
				{
					singleName[name[0]-'a'] = num;
					repeatNum[num] = 1;
					markName[num][0] = name[0];
					len[num] = length;
					num++;
				}
			}
			else
			{
				repeatNum[num] = 1;
				for (k = 0; k < length; ++ k)
				{
					markName[num][k] = name[k];
				}
				len[num] = length;
				num++;
			}
		}

		if (cando)
		{	
			for (j = 0; j < MAXL; ++ j)
			{
				mid[j] = false;
				head[j] = false;
				tail[j] = false;
			}
			for (i = 0; i < num; ++ i)
			{
				if (len[i] > 1)
				{
					if (head[markName[i][0]-'a'] || tail[markName[i][len[i]-1]-'a'])
					{
						cando = false;
						break;
					}
					head[markName[i][0]-'a'] = true;
					tail[markName[i][len[i]-1]-'a'] = true;
				}

				if (mid[markName[i][0]-'a'] || mid[markName[i][len[i]-1]-'a'])
				{
					cando = false;
					break;
				}
				for (k = 1; k < len[i]-1; ++k)
				{
					if (mid[markName[i][k]-'a'])
					{
						cando = false;
						break;
					}
					mid[markName[i][k]-'a'] = true;
				}
				if (!cando)
				{
					break;
				}
				for (j = i+1; j < num; ++ j)
				{
					if (len[i] == len[j])
					{
						for (k = 0; k < len[i]; ++k)
						{
							if (markName[i][k] != markName[j][k])
							{
								break;
							}
						}
						if (k >= len[i])//equal
						{
							cando = false;
							break;
						}
					}
				}
				if (!cando)
				{
					break;
				}
			}
			
			if (cando)
			{
				for (i = 0; i < num; ++ i)
				{
					haveFather[i] = false;
					for (j = 0; j < num; ++ j)
					{
						shouldAdj[i][j] = false;
					}
				}

				for (i = 0; i < num; ++ i)
				{
					for (j = i+1; j < num; ++ j)
					{
						if (markName[i][len[i]-1] == markName[j][0])
						{
							shouldAdj[i][j] = true;
							haveFather[j] = true;
						}
						if (markName[i][0] == markName[j][len[j]-1])
						{
							shouldAdj[j][i] = true;
							haveFather[i] = true;
						}
					}
				}
				
				ans = 1;
				cnt = 0;
				for (i = 0; i < num; ++ i)
				{
					if (!haveFather[i])
					{
						ans *= Dfs(i) % 1000000007;
						ans %= 1000000007;
						cnt++;
					}
				}
				if (cnt == 0)
				{
					ans = 0;
				}
				else
				{
					ans *= p[cnt];
					ans %= 1000000007;
				}
				
			}	
			
		}
		
		if (!cando)
		{
			ans = 0;
		}
		
		printf("Case #%d: %I64d", t, ans);
		
		if (t < nCase)
		{
			printf("\n");
		}
	}

	//system("pause");
	return 0;
}

