#include <stdio.h>
#include <string.h>

#define N 1001

void swap(int *a, int i, int j) {
	int temp;
	temp = a[i]; a[i] = a[j]; a[j] = temp;
}

int main(int argc, char const *argv[])
{
	FILE *fin,*fout;
	int t,count,n,a[N],b[N],i,j,curScore,sum,found;
	int v[N],ia[N],ib[N];

	fin = fopen("GJC.in","r");
	fscanf(fin,"%d", &t);

	fout = fopen("GJC.out","w");
	for (count = 1;count<=t;count++) {
		fscanf(fin,"%d",&n);
		for (i=0;i<n;i++) {
			fscanf(fin,"%d%d",&a[i],&b[i]);
			ia[i] = ib[i] = i;
			v[i] = 0;
		}
		for (i=0;i<n;i++) 
			for (j=i+1;j<n;j++) {
				if (b[i]>b[j]) {
					swap(b,i,j);
					swap(ib,i,j);
				}
				if (a[i]>a[j]) {
					swap(a,i,j);
					swap(ia,i,j);
				}
			}

		curScore = 0;
		i = 0; j = 0; sum = 0; found = 0;
		while (1) {
			while (v[ib[j]]==2) {
				j++;
				if (j>=n) {
					found = 1;
					break;
				}
			}
			if (found) break;
			if (v[ib[j]]<2 && curScore>=b[j]) {
				sum++;
				if (v[ib[j]]==0) curScore += 2;
				else curScore += 1;
				v[ib[j]] = 2;
			} else {
				while (v[ia[i]]>=1) {
					i++;
					if (i>=n) break;
					}
				if (v[ia[i]]==0 && curScore>=a[i]) {
					sum++;
					curScore += 1;
					v[ia[i]] = 1;
				} else {
					found = 0;
					break;
				}
			}
		}

		if (found) fprintf(fout,"Case #%d: %d\n", count, sum);
		else fprintf(fout,"Case #%d: Too Bad\n", count);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}