#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char input[1000005];
long long int diff[1000005];
long long int pass[1000005];
long long int left[1000005];

int main () {
	//freopen("A-large.in", "r", stdin);
    //freopen("A-large.txt", "w", stdout);
	long long int i, j, k, l;
	long long int T, nm;
	scanf("%lld", &T);
	for (nm=1;nm<=T;nm++) {
		long long int ans= 0;
		long long int N;
		scanf("%s %lld", input, &N);
		//prlong long intf("input= %s, N= %lld\n", input, N);
		long long int len= strlen(input);
		//prlong long intf("len= %lld\n", len);
		long long int temp= 0;
		j= 0;
		for (i=0;i<len;i++) {
			if (input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u') {
				diff[i]= 0;
				if (temp>=N) {
					pass[j]= i-1;
					left[j]= temp;
					j++;
				}
				temp= 0;
			}
			else {
				diff[i]= 1;
				temp++;
			}
		}
		if (temp>=N) {
			pass[j]= i-1;
			left[j]= temp;
			j++;
		}
		long long int n= j;
		/*
		prlong long intf("n= %lld\n", n);
		prlong long intf("diff[ ");
		for (i=0;i<len;i++) {
			prlong long intf("%lld ", diff[i]);
		}
		prlong long intf("]\n");
		prlong long intf("pass[ ");
		for (i=0;i<n;i++) {
			prlong long intf("%lld ", pass[i]);
		}
		prlong long intf("]\n");
		prlong long intf("left[ ");
		for (i=0;i<n;i++) {
			prlong long intf("%lld ", left[i]);
		}
		prlong long intf("]\n");
		*/
		for (i=0;i<n;i++) {
			for (j=pass[i];j>=pass[i]-left[i]+N;j--) {
				ans+= j-N+2;
				//prlong long intf("ans= %lld\n", ans);
			}
		}
		if (n!=0) {
			for (i=1;i<n;i++) {
				ans+= ((N-1)+(pass[i]-left[i]-pass[i-1]))*(pass[i-1]-N+2);
				//prlong long intf("ans= %lld\n", ans);
			}
			ans+= (len-pass[n-1]-1)*(pass[n-1]-N+2);
			//prlong long intf("ans= %lld\n", ans);
		}
		printf("Case #%lld: %lld\n", nm, ans);
	}
	return 0;
}
