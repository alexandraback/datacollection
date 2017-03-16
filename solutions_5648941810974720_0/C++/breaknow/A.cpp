#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <string>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sl(n)						scanf("%I64d", &n)
#define sc(n)                       scanf("%c",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define INF 2147483647
#define UINF 0xffffffff

#define N 2000

char alp[11] = "ZWUXGOTFVN", number[11][10] = { "ZERO", "TWO", "FOUR", "SIX", "EIGHT", "ONE", "THREE", "FIVE", "SEVEN", "NINE" };
int ans[20], ansLen;
int num[10] = { 0,2,4,6,8,1,3,5,7,9 };

void rem(char *data, int a)
{
	int n = strlen(data);
	int m = strlen(number[a]);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (data[j] == number[a][i])
			{
				data[j] = ' ';
				break;
			}
		}
	}
	ans[ansLen++] = num[a];
}

void process(int c)
{
	ansLen = 0;
	char data[N+10];
	scanf("%s", &data);
	int len = strlen(data);
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (data[j] == alp[i])
			{
				rem(data, i);
			}
		}
	}
	sort(ans, ans + ansLen);
	printf("Case #%d: ", c);
	for (int i = 0; i < ansLen; i++)
		printf("%d", ans[i]);
	printf("\n");
}

int main()
{
	int c;
	s(c);
	for (int i = 1; i <= c; i++)
		process(i);
}