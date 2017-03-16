#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct el
{
	int sum;
	vector<int> v;
};

vector<el> V[2000001];
int A[21];
int N;
int wynik;

void go(int left, int place, el X)
{
	if(left == 0)
	{
		V[X.sum].push_back(X);
		if(V[X.sum].size() > 1)
			wynik = X.sum;
		return;
		
	}
	else
	if(place <= 20)
	{
		for(int i=place; i<=20 && wynik == -1; i++)
		{
			X.v.push_back(A[i]);
			X.sum += A[i];
			go(left-1, i+1, X);
			X.v.pop_back();
			X.sum -= A[i];
		}
	}
	return;
}

int main()
{
	int Z;
	scanf("%d", &Z);
	for(int z=1; z<=Z; z++)
	{
		scanf("%d", &N);
		wynik = -1;
		for(int i=1; i<=N; i++)
			scanf("%d", &A[i]);
		for(int l=1; l<=20; l++)
		{
			el x;
			x.sum = 0;
			go(l, 1, x);
		}
		if(wynik == -1)
			printf("Case #%d: Impossible\n", z);
		else
		{
			printf("Case #%d:\n", z);
			for(int i=0; i<V[wynik][0].v.size(); i++)
				printf("%d ", V[wynik][0].v[i]);
			printf("\n");
			for(int i=0; i<V[wynik][1].v.size(); i++)
				printf("%d ", V[wynik][1].v[i]);
			printf("\n");
		}
		for(int i=1; i<=2000001; i++)
			V[i].clear();
	}
	return 0;
}
