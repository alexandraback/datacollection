#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int ans, len;
typedef struct node
{
	int start, end;
	bool operator < (const node& p) const
	{
		if(start < p.start) return true;
		else if(start == p.start) return end < p.end;
		else return false;
	}
	
}NODE;

map<NODE, bool> check;

void run(int start, int end)
{
	for(int i = end ; i < len ; i++)
	{
		NODE temp;
		temp.start = start;
		temp.end = i;
		check[temp] = true;
		ans++;
	}
	for(int i = start-1 ; i >= 0 ; i--)
	{
		NODE temp;
		temp.start = i;
		for(int j = end ; j < len ; j++)
		{
			temp.end = j;
			bool result = check[temp];
			if(!result) 
			{
				check[temp] = true;
				ans++;
			}
		}
	}
}

int main()
{
	int T, count = 1;
	cin>>T;
	while(T--)
	{
		check.clear();
		char str[1000100];
		int N;

		memset(str, 0, sizeof(str));
		scanf("%s %d", str, &N);
		len = strlen(str);

		int now = 0;
		ans = 0;
		for(int i = 0 ; i <= len-N ; i++)
		{
			char c = str[i];
			if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
			{
				now++;
				if(now == N)
				{
					run(i, i);
					now = 0;
					continue;
				}	
				for(int j = i+1 ; j < len ; j++)
				{
					char c2 = str[j];
					if(c2 != 'a' && c2 != 'e' && c2 != 'i' && c2 != 'o' && c2 != 'u')
					{
						now++;
						if(now == N)
						{
							run(i, j);
							now = 0;
							break;
						}
					}
					else
					{
						i = j;
						now = 0;
						break;
					}
				}
			}
			else now = 0;
		}

		printf("Case #%d: %d\n", count++, ans);
	}
	return 0;
}

