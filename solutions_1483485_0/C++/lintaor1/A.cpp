#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <memory.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define ALL(c) (c).begin(), (c).end()
#define RESET(a,b) memset( (a), b, sizeof(a) )
#define ren(a,b,c) for (int a=b; a<c; ++a)
#define red(a,b,c) for (int a=b; a>=c; --a)
#define repi(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

const double eps = 1e-9;
typedef long long ll;
typedef pair <int,int> pii;

//lintaor1's template

char o[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A0.out", "w", stdout);
	
	int T;
	scanf("%d",&T); scanf("\n");
	ren (TT,0,T)
	{
		char i[1024];
		gets(i);
		
		printf("Case #%d: ", TT+1);
		int sz = strlen(i);
		ren (x,0,sz) printf("%c", ((i[x]<'a') || (i[x]>'z'))?i[x]:o[i[x]-'a']); printf("\n");
	}
	return 0;
}
