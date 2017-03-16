#include <cstdio>
#include <algorithm>
using namespace std;


#define MAX_LEN 1005

typedef struct
{
	int a;
	int b;
	int s;	
}Item;

Item buf[MAX_LEN];

Item * bufa[MAX_LEN];
Item * bufb[MAX_LEN];

void print(Item **x, int n) {
	for (int i=0; i<n; i++) {
		printf("%d:%d %d->%d\n", i, x[i]->a, x[i]->b, x[i]->s);
	}
}

bool comparea(const Item * x, const Item * y){
	return x->a < y->a;
}

bool compareb(const Item * x, const Item * y){
	return x->b < y->b;
}


int main(int argc, char const *argv[])
{
	freopen("x.in", "r", stdin);
	int t, ti, n, ni;
	scanf("%d", &t);
	ti = 0;
	while (ti++ < t) {
		scanf("%d", &n);
		for (ni=0; ni<n; ni++) {
			scanf("%d %d", &(buf[ni].a), &(buf[ni].b));	
			buf[ni].s = 0;
			bufa[ni] = &buf[ni];
			bufb[ni] = &buf[ni];
		}

		sort(bufa, bufa+n, comparea);
		sort(bufb, bufb+n, compareb);

		//print(bufa, n);
		//print(bufb, n);

		int sum = 0;
		int star = 0;
		int i = 0;
		int j = 0;
		int x = 0;

		for (i=0; i<n; i++) {
			//printf("i=%d: %d %d\n", i, bufb[i]->b,  star);
			if (bufb[i]->b <= star) {
				++sum;
				++star;
				if (bufb[i]->s==0) {
					++star;
				}
				bufb[i]->s = -1;
				//printf("pass: %d %d\n",  sum,  star);
			} else {
				for (x=0; x<n; x++) {
					if (bufa[x]->s == 0) {
						if (bufa[x]->a <= star)	{
							//printf("x=%d: %d %d\n", x, bufa[x]->a,  star);
							++sum;
							++star;
							bufa[x]->s = 1;	
							break;
						}
					}
				}
				--i;	
				if (x == n) {
					break;
				}	
			}
		}


		if (i !=n) {
			printf("Case #%d: Too Bad\n", ti);
		}else {
			printf("Case #%d: %d\n", ti, sum);
		}
	}

	return 0;
}