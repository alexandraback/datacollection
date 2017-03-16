#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

typedef __int64 LL;

vector<LL> V, H;

inline int f(LL x)
{
	LL y = sqrt(x), i;
	for(i = y-1; i <= y+1; i++)
		if(i*i == x)
			break;

	if(i>y+1)
		return 0;
	x = i;

	int id = lower_bound(V.begin(), V.end(), x) - V.begin();
	if(id!=V.size() && V[id]==x)
		return 1;
	return 0;
}

void gen()
{
	LL start, end, i, j, now, temp;

	start = 1;
	end = 9;

	for(i = 1; i <= 7; i++)
	{
		for(j = start; j <= end; j++)
		{
			now = j;
			temp = j/10;
			while(temp)
			{
				now = now * 10 + temp % 10;
				temp /= 10;
			}

			V.push_back( now );
			if(f(now))
				H.push_back( now );
		}

		for(j = start; j <= end; j++)
		{
			now = j;
			temp = j;
			while(temp)
			{
				now = now * 10 + temp % 10;
				temp /= 10;
			}

			V.push_back( now );
			if(f(now))
				H.push_back( now );
		}

		start *= 10;
		end = end*10 + 9;
	}
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

//	freopen("C-large1.in", "r", stdin);
//	freopen("C-large1.out", "w", stdout);

	int T, ks, i;
	LL ans, A, B;

	gen();

//	for(i = 0; i < V.size(); i++)
//		printf(">%I64d\n", V[i]);
//	for(i = 0; i < H.size(); i++)
//		printf(">>%I64d\n", H[i]);

	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		scanf("%I64d %I64d", &A, &B);

		ans = upper_bound(H.begin(), H.end(), B) - upper_bound(H.begin(), H.end(), A-1);

		printf("Case #%d: %d\n", ks, ans);
	}

	return 0;
}