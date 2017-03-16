#include<stdio.h>
#include<memory.h>
#include<math.h>

FILE *in = fopen("C-large-1.in","r");
FILE *out= fopen("output.in","w");

int T, cc, cnt;
char a[100];
__int64 c[5000];

int main()
{
	int j, o, kk;
	__int64 n1, n2, i, k;
	for(i = 1; i <= 10000000; i++){
		k = i;
		for(j = 0;;j++){
			a[j] = (k % 10) + '0';
			k /= 10;
			if(k == 0)break;
		}
		kk = j;
		for(j = 0; j <= kk; j++){
			if(a[j] != a[kk - j])break;
		}
		if(j == kk + 1){
			k = i*i;
			kk = 0;
			for(j = 0;;j++){
				a[j] = (k % 10) + '0';
				k /= 10;
				if(k == 0)break;
			}
			kk = j;
			for(j = 0; j <= kk; j++){
				if(a[j] != a[kk - j])break;
			}
			if(j == kk + 1)
				c[cc++] = i*i;
		}
	}
	
	fscanf(in, "%d", &T);
	for(o = 1; o <= T; o++){
		fscanf(in, "%I64d%I64d",&n1,&n2);
		cnt = 0;
		for(i = 0; i < cc; i++){
			if(c[i] >= n1 && c[i] <= n2) cnt++;
		}
		fprintf(out, "Case #%d: %d\n",o, cnt);
	}
	return 0;
}