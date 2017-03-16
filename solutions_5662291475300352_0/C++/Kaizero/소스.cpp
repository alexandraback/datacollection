#include<stdio.h>
#include<algorithm>
using namespace std;
struct P{
	double v, d;
	bool operator<(const P &p)const{
		return v < p.v;
	}
}w[501000];
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC, TT, nn, n, i, a, b, c, j;
	scanf("%d", &TC);
	for (TT = 1; TT <= TC; TT++){
		printf("Case #%d: ", TT);
		scanf("%d", &nn);
		n = 0;
		for (i = 1; i <= nn; i++){
			scanf("%d%d%d", &a, &b, &c);
			for (j = c; j <= c + b - 1; j++){
				n++;
				w[n].d = a / 360.0;
				w[n].v = j;
			}
		}
		sort(w + 1, w + n + 1);
		for (i = 1; i <= n; i++)w[i].v = 1.0 / w[i].v;
		if (n <= 2){
			if (n == 1){
				printf("0\n");
				continue;
			}
			if ((2.0 - w[1].d) * w[2].v <= (1.0 - w[2].d) * w[1].v){
				printf("1\n");
			}
			else printf("0\n");
			continue;
		}
	}
}