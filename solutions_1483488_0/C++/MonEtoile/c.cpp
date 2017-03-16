#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

#define _INFILE		"C-small-attempt0.in"
#define _OUTFILE	"C-small0.out"
//#define _INFILE		"C.in"
//#define _OUTFILE	"C.out"
//#define _INFILE		"C-large.in"
//#define _OUTFILE	"C-large.out"

typedef long long ll;

int solve()
{
	int a, b;
	char buf[20];
	scanf("%d%d",&a,&b);
	sprintf(buf,"%d",a);
	int len = strlen(buf);

	int result = 0;
	for(; a<=b; a++)
	{
		char s1[20];
		sprintf(s1,"%d",a);
		char s2[20];
		set<int> S;
		for(int i=1; i<len; i++)
		{
			for(int j=0; j<len; j++)
			{
				s2[j] = s1[(i + j) % len];
			}
			s2[len] = '\0';
			int m = atoi(s2);
			if (a < m && m <= b && S.find(m) == S.end()) {
				S.insert(m);
				result++;
			}
		}
	}

	return result;
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);
	scanf("%d",&T);
	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}

