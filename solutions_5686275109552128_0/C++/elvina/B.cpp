#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

int tab[N];

void test()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",tab+i);
	int wyn = N;
	for (int x=1;x<N;x++)
	{
		int tem = 0;
		for (int i=0;i<n;i++)
			tem += (tab[i]-1)/x;
		wyn = min( wyn, tem + x );
	}
	printf("%d\n",wyn);
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		test();
	}
}
