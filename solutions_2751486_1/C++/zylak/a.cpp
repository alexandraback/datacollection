#include <cstdio>
using namespace std;
typedef long long LL;

const int MAX = 1e6;

char s[MAX+1];
int n;
LL r;

bool vow(char c)
{
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main()
{
	int Q; scanf("%d", &Q);
	for (int q=1; q<=Q; ++q) {
		scanf("%s%d", s, &n);
		r = 0;
		
		int f = -1, now = 0;
		for (int i=0; s[i]; ++i) {
			if (vow(s[i])) now = i+1;
			else if (i+1-now >= n) f = i+1-n;
			r += f+1;
		}
		
		printf("Case #%d: %lld\n", q, r);
	}
	
	return 0;
}
