#include<stdio.h>
#include<string.h>
#include<memory.h>

FILE *in = fopen("A-small-attempt1.in", "r");
FILE *out = fopen("output.txt", "w");

char a[700000];
int d[700000], nu[700000], whe[700000];
__int64 ans;

int isv(char tmp)
{
	if(tmp == 'a' || tmp == 'e' || tmp == 'u' || tmp == 'i' || tmp == 'o')
		return 1;
	return 0;
}

int main(){
	
	int i, j, cn, T, n, len, cnt;
	fscanf(in, "%d", &T);
	for(cn = 1; cn <= T; cn++){
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		memset(nu, 0, sizeof(nu));
		memset(whe, 0, sizeof(whe));
		ans = 0;
		cnt = 0;
		fscanf(in, "%s", a);
		len = strlen(a);
		fscanf(in, "%d\n", &n);
		if(isv(a[0]) == 1){
			d[0] = 0;
		}
		else{
			nu[0] = 1;
			if(n == 1){
				d[0] = 1;
				cnt = 1;
				ans = 1;
			}
		}
		for(i = 1; i < len; i++){
			whe[i] = whe[i-1];
			if(isv(a[i]) == 0){
				nu[i] = nu[i-1] + 1;
				d[i] = cnt;
				if(nu[i] >= n){
					cnt++;
					d[i] = cnt;
					whe[i] = i;
				}
			}
			else{
				nu[i] = 0;
				d[i] = cnt;
			}
			if(d[i] >= 1){
				ans += (whe[i] - n + 2);
			}
		}
		fprintf(out, "Case #%d: %I64d\n", cn, ans);
	}
	return 0;

}