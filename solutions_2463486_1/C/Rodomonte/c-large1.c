// Qualification Round
// Problem C-large 1

#include <stdio.h>

#define LL long long
/* USED TO GENERATE PALINDROMES
#define MAX 10000000
char palin(LL n0){
	LL r = 0, n = n0;
	while(n){
		r = r*10 + n%10;
		n /= 10;
	}
	return r==n0 ? 1 : 0;
}*/
LL a[39] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944,
		1002001, 1234321, 4008004, 100020001, 102030201, 104060401,
		121242121, 123454321, 125686521, 400080004, 404090404, 10000200001,
		10221412201, 12102420121, 12345654321, 40000800004, 1000002000001,
		1002003002001, 1004006004001, 1020304030201, 1022325232201,
		1024348434201, 1210024200121, 1212225222121, 1214428244121,
		1232346432321, 1234567654321, 4000008000004, 4004009004004};
int main(){
	int T,t, i, r;
	LL A,B;
	FILE *fi = fopen("../Google/cl1.in","r"),
		*fo = fopen("../Google/cl1.out","w");
	fscanf(fi,"%d\n",&T);
	for(t = 1; t <= T; t++){
		fprintf(fo,"Case #%d: ",t);
		fscanf(fi,"%lld %lld\n",&A,&B);
		r = 0;
		for(i = 0; i < 39; i++)
			if(a[i] >= A && a[i] <= B)
				r++;
		fprintf(fo,"%d\n",r);
	}
	fclose(fi); fclose(fo);
	return 0;
}
