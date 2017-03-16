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

#define N 18

int len, ans;
char c[N + 10], a[N + 10], ansc[N+10], ansa[N+10], bc[N+10], ba[N+10];

void dfsa(int i)
{
	if (i == len)
	{
		int cc = 0, aa = 0;
		for (i = 0; i < len; i++)
		{
			cc = cc * 10 + c[i] - '0';
			aa = aa * 10 + a[i] - '0';
		}
		if (abs(cc - aa) < ans)
		{
			ans = abs(cc - aa);
			strcpy(ansc, c);
			strcpy(ansa, a);
		}
		return;
	}
	if (ba[i] != '?')
	{
		dfsa(i + 1);
	}
	else
	{
		for (int j = 0; j < 10; j++)
		{
			a[i] = j + '0';
			dfsa(i + 1);
		}
	}
}

void dfsc(int i)
{
	if (i == len)
	{
		dfsa(0);
		return;
	}
	if (bc[i] != '?')
	{
		dfsc(i + 1);
	}
	else
	{
		for (int j = 0; j < 10; j++)
		{
			c[i] = j + '0';
			dfsc(i + 1);
		}
	}
}

void process(int testNum)
{
	ss(c);
	ss(a);
	strcpy(bc, c); strcpy(ba, a);
	len = strlen(c);
	ans = 9999999;
	dfsc(0);

	printf("Case #%d: ", testNum);
	for (int i = 0; i < len; i++)
		printf("%c", ansc[i]);
	printf(" ");
	for (int i = 0; i < len; i++)
		printf("%c", ansa[i]);
	printf("\n");
}

int main()
{
	int c;
	s(c);
	for (int i = 1; i <= c; i++)
		process(i);
}