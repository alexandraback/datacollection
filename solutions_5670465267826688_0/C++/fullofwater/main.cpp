#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <functional>

using namespace std;

typedef long long llong;

// 0:'1', 1:'i', 2:'j', 3:'k', 4:'-1', 5:'-i', 6:'-j', 7:'-k'
int calc[8][8] = {
//   1  i  j  k -1 -i -j -k
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 4, 3, 6, 5, 0, 7, 2},
	{2, 7, 4, 1, 6, 3, 0, 5},
	{3, 2, 5, 4, 7, 6, 1, 0},
	{4, 5, 6, 7, 0, 1, 2, 3},
	{5, 0, 7, 2, 1, 4, 3, 6},
	{6, 3, 0, 5, 2, 7, 4, 1},
	{7, 6, 1, 0, 3, 2, 5, 4},
}, rep['z'];

int main() {
	int T, len, cnt, it;
	llong l, x;
	static char str[10010], mux[80080];
	rep['i']=1, rep['j']=2, rep['k']=3;
	scanf("%d", &T);
	for (int c=1;c<=T;c++) {
		scanf("%lld%lld%s", &l, &x, str);
		printf("Case #%d: ", c);
		int ans=0, tot=0;
		for (int i=0;i<l;i++)
			ans=calc[ans][rep[str[i]]];
		for (int i=(x&3);i;i--)
			tot=calc[tot][ans];
		//printf("[%d %d]\n", tot, ans);
		if (tot!=4)
			puts("NO");
		else {
			cnt=(int)min(8ll, x);
			len=l*cnt, *mux=0;
			for (int i=0;i<cnt;i++)
				strcat(mux+i*l, str);
			int acc=0;
			for (it=0;it<len;) {
				acc=calc[acc][rep[mux[it++]]];
				if (acc==1)
					break;
			}
			if (acc!=1)
				puts("NO");
			else {
				//printf("{%d}", it);
				for (acc=0;it<len;) {
					acc=calc[acc][rep[mux[it++]]];
					if (acc==2)
						break;
				}
				if (acc!=2)
					puts("NO");
				else {
					//printf("{%d}", it);
					puts("YES");
				}
			}
		}
	}
	return 0;
}

