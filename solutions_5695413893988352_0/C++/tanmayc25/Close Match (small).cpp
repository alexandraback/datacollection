//by Tanmay Chaudhari
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//#pragma comment(linker, "/STACK:66777216")
#include <bits/stdc++.h>
using namespace std;

#define si(a)				scanf("%d",&a)
#define sl(a)				scanf("%lld",&a)
#define pi(a)				printf("%d\n",a)
#define pl(a)				printf("%lld\n",a)

typedef long long			ll;
typedef vector<int>			vi;
typedef pair<int, int>		ii;
typedef vector<vi>			vvi;
typedef vector<ii>			vii;

#define fast_io				ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SET(a,b)			memset(a,b,sizeof(a))	
#define forall(i,a,b)		for(int i=a; i<b; i++)
#define forrev(i,a,b)		for(int i=a; i>=b; i--)
#define forr(it,container)  for(auto it=container.begin(); it!=container.end(); it++)
#define w(t)				int t;si(t);while(t--)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1 << " | ";__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
ll a, b;
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	si(t);
	for (int tt = 1;tt <= t;tt++)
	{
		a = 1000000000;
		b = 100;
		string C, J;
		cin >> C >> J;
		if (C.size() == 1)
		{
			for (int i = 0;i <= 9;i++)
			{
				for (int j = 0;j <= 9;j++)
				{
					if (C[0] != '?' && C[0] - '0' != i % 10)
						continue;
					if (J[0] != '?' && J[0] - '0' != j % 10)
						continue;
					if (abs(j - i) < abs(a - b))
					{
						a = i;
						b = j;
					}
					if (abs(i - j) == abs(a - b))
					{
						if ((i < a))
						{
							a = i;
							b = j;
						}
						if (j < b)
						{
							a = i;
							b = j;
						}
					}
				}
			}
		}
		if (C.size() == 2)
		{
			for (int i = 0;i <= 99;i++)
			{
				for (int j = 0;j <= 99;j++)
				{
					if (C[1] != '?' && C[1] - '0' != i % 10)
						continue;
					if (C[0] != '?' && C[0] - '0' != (i / 10) % 10)
						continue;
					if (J[1] != '?' && J[1] - '0' != j % 10)
						continue;
					if (J[0] != '?' && J[0] - '0' != (j / 10) % 10)
						continue;
					if (abs(j - i) < abs(a - b))
					{
						a = i;
						b = j;
					}
					if (abs(i - j) == abs(a - b))
					{
						if ((i < a))
						{
							a = i;
							b = j;
						}
						if (j < b)
						{
							a = i;
							b = j;
						}
					}
				}
			}
		}
		if (C.size() == 3)
		{
			for (int i = 0;i <= 999;i++)
			{
				for (int j = 0;j <= 999;j++)
				{
					if (C[2] != '?' && C[2] - '0' != i % 10)
						continue;
					if (C[1] != '?' && C[1] - '0' != (i / 10) % 10)
						continue;
					if (C[0] != '?' && C[0] - '0' != (i / 100) % 10)
						continue;
					if (J[2] != '?' && J[2] - '0' != j % 10)
						continue;
					if (J[1] != '?' && J[1] - '0' != (j / 10) % 10)
						continue;
					if (J[0] != '?' && J[0] - '0' != (j / 100) % 10)
						continue;
					if (abs(j - i) < abs(a - b))
					{
						a = i;
						b = j;
					}
					if (abs(i - j) == abs(a - b))
					{
						if ((i < a))
						{
							a = i;
							b = j;
						}
						if (j < b)
						{
							a = i;
							b = j;
						}
					}
				}
			}
		}

		int temp1, temp2;
		temp1 = temp2 = 0;
		if (a / 10 != 0)
		{
			temp1++;
			if (a / 100 != 0)
				temp1++;
		}
		if (b / 10 != 0)
		{
			temp2++;
			if (b / 100 != 0)
				temp2++;
		}
		printf("Case #%d: ", tt);

		forall(i, 0, C.size() - temp1 - 1)
			printf("0");
		printf("%lld ", a);
		forall(i, 0, C.size() - temp2 - 1)
			printf("0");
		printf("%lld\n", b);
	}
	return 0;
}