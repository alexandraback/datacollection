#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int T, n;
int a[N];

int rd()
{
	int c;
	while(c=getchar(), c<=' ');
	return c-'0';
}

int work()
{
	scanf("%d", &n);
	for(int i=0; i<=n; i++) a[i] = rd();
	
	int tot = a[0], nd(0);
	for(int i=1; i<=n; i++) if(tot<=i && a[i]) nd+=i-tot, tot=i+a[i]; else tot+=a[i];
	return nd;
}

int main()
{
	freopen("ovation.in", "r", stdin);
	freopen("ovation.out", "w", stdout);
	
	scanf("%d", &T);
	for(int i=1; i<=T; i++) printf("Case #%d: %d\n", i, work());
	
	return 0;
}

