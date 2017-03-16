#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define INFLL 999999999999999999LL
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

char A[20], B[20];
int mini = INF;
int numa[20], numb[20];
int ansa = INF, ansb = INF;
int ansA[20], ansB[20];
int n;

int convierte(int num[20])
{
	int p = 1, ans = 0;
	for (int i = n-1; i >= 0; --i)
		ans += p*num[i], p *= 10;
	return ans;
}

void bt(int i)
{
	if (i == n)
	{
		int a = convierte(numa);
		int b = convierte(numb);

		if (abs(a-b) < mini)
		{
			mini = abs(a-b);
			ansa = a;
			ansb = b;
			For(i, 0, n)
			{
				ansA[i] = numa[i];
				ansB[i] = numb[i]; 
			}
		}
		else if (abs(a-b) == mini)
		{
			if (a < ansa)
			{
				ansa = a;
				ansb = b;
				For(i, 0, n)
				{
					ansA[i] = numa[i];
					ansB[i] = numb[i]; 
				}
			}
			else if (ansa == a and b < ansb)
			{
				ansb = b;
				For(i, 0, n)
				{
					ansA[i] = numa[i];
					ansB[i] = numb[i]; 
				}
			}
		}

		return;
	}

	if (A[i] == '?' and B[i] == '?')
	{
		For(a, 0, 10)
			For(b, 0, 10)
			{
				numa[i] = a;
				numb[i] = b;
				bt(i+1);
			}
	}
	else if (A[i] == '?' and B[i] != '?')
	{
		numb[i] = B[i]-'0';
		For(a, 0, 10)
		{
			numa[i] = a;
			bt(i+1);
		}
	}
	else if (A[i] != '?' and B[i] == '?')
	{
		numa[i] = A[i]-'0';
		For(b, 0, 10)
		{
			numb[i] = b;
			bt(i+1);
		}
	}
	else
	{
		numa[i] = A[i] -'0';
		numb[i] = B[i]-'0';
		bt(i+1);
	}
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		mini = INF;
		ansa = INF;
		ansb = INF;
		scanf("%s %s", A, B);
		n = strlen(A);

		bt(0);

		printf("Case #%d: ", caso++);
		For(i, 0, n)
			printf("%d", ansA[i]);
		printf(" ");
		For(i, 0, n)
			printf("%d", ansB[i]);
		printf("\n");
	}

	return 0;
}