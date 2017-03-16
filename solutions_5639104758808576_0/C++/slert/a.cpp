#include <cstdio>

int main(int argc, char const *argv[])
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);

	int tc;
	scanf("%d", &tc);
	for(int ti=1; ti<=tc; ti++){
		int n;
		char a[1010];
		scanf("%d%s",&n,a);
		int s = 0, q = 0;
		for(int i = 0; i <= n; i++){
			if(s<i){
				q += i-s;
				s = i;
			}
			s += a[i]-'0';
		}
		printf("Case #%d: %d\n",ti,q);
	}
	return 0;
}