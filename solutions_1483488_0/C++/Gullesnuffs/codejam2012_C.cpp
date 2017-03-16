#include <stdio.h>
#include <vector>

using namespace std;

int recycles[2000010][10], recycleN[2000010];

int main()
{
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.txt", "w");
	int ten=1, j;
	for(int i=1; i <= 2000005; ++i)
		recycleN[i]=0;
	for(int i=1; i <= 2000003; ++i){
		if(i >= ten*10)
			ten *= 10;
		j=(i/10)+ten*(i%10);
		while(j != i){
			if(j >= ten){
				recycles[i][recycleN[i]++]=j;
			}
			j=(j/10)+ten*(j%10);
		}
	}
	int T, A, B;
	fscanf(fin, "%d", &T);
	for(int i=1; i <= T; ++i){
		int ans=0;
		fscanf(fin, "%d%d", &A, &B);
		for(int j=A; j <= B; ++j){
			for(int k=0; k < recycleN[j]; ++k)
				if(recycles[j][k] <= B && recycles[j][k] >= A)
					++ans;
		}
		fprintf(fout, "Case #%d: %d\n", i, ans/2);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

