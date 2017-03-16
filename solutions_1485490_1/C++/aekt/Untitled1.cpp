#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int tc, n, m, A[101], B[101];
long long a[101], b[101], c;

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &tc);
	for(int ct = 1; ct <= tc; ct++){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++){
			a[i] = A[i] = a[i+1] = A[i+1] = 0;
			scanf("%I64d%d", &a[i], &A[i]);
			if (i && A[i] == A[i-1]){
				i--; n--;
				a[i] += a[i+1];
			}
		}
		for(int j = 0; j < m; j++){
			b[j] = B[j] = b[j+1] = B[j+1] = 0;
			scanf("%I64d%d", &b[j], &B[j]);
			if (j && B[j] == B[j-1]){
				j--; m--;
				b[j] += b[j+1];
			}
		}
		c = 0;
		for(int i = 0, j = 0; i < n && j < m; ){
			if (A[i] == B[j]){
				if (a[i] < b[j]){
					b[j] -= a[i];
					c += a[i++];
				}else if (a[i] > b[j]){
					a[i] -= b[j];
					c += b[j++];
				}else{
					c += a[i++];
					j++;
					
				}
			}else{
				if (min(a[i], b[j+1]) > min(b[j], a[i+1])){
					j++;
				}else{
					i++;
				}
			}
		}
		printf("Case #%d: %I64d\n", ct, c);
	}
	return 0;
}
