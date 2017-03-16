#define I (2)
#define J (3)
#define K (4)

#include<iostream>
#include<cstdio>
using namespace std;

char s[10001];
int leftRes[10001], rightRes[10001], a[10001];

int t, l, x, n;
const int map[5][5] = {
		{0,0,0,0,0},
		{0,1,I,J,K},
		{0,I,-1,K,-J},
		{0,J,-K,-1,I},
		{0,K,J,-I,-1}
};

int mul(int p, int q){
	if(p < 0) return -mul(-p, q);
	if(q < 0) return -mul(p, -q);
	return map[p][q];
}

void init(){
	leftRes[0] = a[0];
	for(int i = 1; i < n; i++)
		leftRes[i] = mul(leftRes[i-1], a[i]);
	rightRes[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--)
		rightRes[i] = mul(a[i], rightRes[i+1]);
}

int solve(){
	for(int i = 0; i <= n-3; i++)
		if(leftRes[i] == I){
			int res = 1;
			for(int j = i+1; j<=n-2; j++){
				res = mul(res, a[j]);
				if(res == J && rightRes[j+1] == K)
					return 1;
			}
		}
	return 0;
}

int main(){
	freopen("t3.in","r",stdin);
	freopen("t3.out", "w",stdout);
	scanf("%d\n", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d\n", &l, &x);
		n = l * x;
		for(int j = 0; j< l; j++)
			scanf("%c", &s[j]);
		for(int j = 0; j < n; j++){
			if(s[j%l]=='i') a[j] = I;
			else if(s[j%l]=='j') a[j] = J;
			else a[j] = K;
		}
		init();
		printf("Case #%d: ", i);
		if(solve()) printf("YES\n");
				else printf("NO\n");

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
