#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

char slo[N];

void test()
{
	int n, suma = 0, wyn = 0;
	scanf("%d",&n);
	scanf("%s",slo);
	for (int i=0;i<=n;i++)
	{
		if ( suma < i )
		{
			suma ++;
			wyn ++;
		}
		suma += slo[i] - '0';
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
