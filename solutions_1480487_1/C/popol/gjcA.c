#include <stdio.h>
#include <math.h>

#define N 205
#define error 0.0000001
#define MAX 999999

int main(int argc, char const *argv[])
{
	freopen("gjc.in","r",stdin);
	freopen("gjc.out","w",stdout);
	int count,t,n,s[N],i,sum,min1,min2,ct;
	double C,x[N];

	scanf("%d", &t);
	for (count = 1;count<=t;count++) {
		printf("Case #%d: ", count);
		scanf("%d", &n);
		sum = 0;
		for (i=0;i<n;i++) {
			scanf("%d", &s[i]);
			x[i] = 0;
			sum+=s[i];
		}
		C = 1;
		while (C>error) {
			min1 = MAX;min2 = MAX;
			for (i=0;i<n;i++) { 
				if (s[i]<min1) {
					min1 = s[i];
				} 
			}
			for (i=0;i<n;i++) {
				if (s[i]>min1 && s[i]<min2) min2 = s[i];
			}
			ct = 0; 
			for (i=0;i<n;i++) {
				if (s[i]==min1) {
					ct++;
				}
			}			
			if (ct*(min2-min1)*1.0/sum>C) {
				for (i=0;i<n;i++) 
					if (s[i]==min1) 
						x[i] += C/ct;
				break;
			} else {
				for (i=0;i<n;i++) {
					if (s[i]==min1) {
						s[i] = min2;
						x[i] += (min2-min1)*1.0/sum;
						C -= (min2-min1)*1.0/sum;
					}
				}
			}
		}
		for (i=0;i<n;i++) printf("%.6lf ", 100*x[i]);
		printf("\n");
	}

	return 0;
}