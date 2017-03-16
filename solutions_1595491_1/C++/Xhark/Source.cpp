#include <stdio.h>
#define fr4(i, s, e, p) for(int i=(s);i<=(e);i+=(p))
#define fr3(i, n, p) fr4(i, 0, n-1, p)
#define fr2(i, n) fr3(i, n, 1)
#define iint(a) int a;scanf("%d",&a);
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0){
		static int cs = 1;
		iint(n);iint(s);iint(p);
		int a, b;
		a = b = 0;
		fr2(i, n) {
			iint(t);
			int x, y;
			x = t / 3;
			y = t % 3;
			
			if (y == 0);
			if (y == 1) x ++;
			if (y == 2) x ++;

			if (x >= p) a ++;
			else {
				if (y == 0) if (x != 0) x ++;
				if (y == 1);
				if (y == 2) x ++;
				if (x >= p) b++;
			}
		}
		if (b > s) b = s;
		printf("Case #%d: %d\n",cs ++, a + b);
	}
	return 0;
}