#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

bool test()
{
	int x,a,b;
	scanf("%d%d%d",&x,&a,&b);
	if ( a > b ) swap(a,b);
	if ( x >= 7 ) return 1;
	if ( x >= 2*a+1 ) return 1;
	if ( x >= b+1 ) return 1;
	if ( a*b % x != 0 ) return 1;
	if ( a == 2 && x >= 4 ) return 1;
	if ( a == 3 && x >= 5 ) return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		printf("%s\n",test()?"RICHARD":"GABRIEL");
	}
}
