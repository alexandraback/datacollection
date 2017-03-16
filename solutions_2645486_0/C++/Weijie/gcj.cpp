#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

FILE *fin;
FILE *fout;

int n,e,r;
int a[20];

int f[20][20];

int solve(){
	memset(f,0,sizeof(f));
	for(int i = 0;i < n;++i)
		for(int j = 0;j <= e;++j){
			for(int k = 0;k <= j;++k){
				int nextEnergy = j - k + r;
				nextEnergy = min(nextEnergy,e);
				f[i + 1][nextEnergy] = max(f[i + 1][nextEnergy],
						f[i][j] + k * a[i + 1]);
			}
		}
/*	for(int i = 0;i <= n;++i,puts(""))
		for(int j = 0;j <= e;++j)
			printf("%d ",f[i][j]);*/
	int tmp = min(r,e);
	return f[n][tmp];
}

int main() {
	fin = fopen("B-small-attempt0.in","r");
	fout = fopen("gcjout.txt","w");
	int T;
	fscanf(fin,"%d",&T);
	for(int caseT = 1;caseT <= T;++caseT){
		fscanf(fin,"%d%d%d",&e,&r,&n);
		for(int i = 1;i <= n;++i)
			fscanf(fin,"%d",&a[i]);
		fprintf(fout,"Case #%d: %d\n",caseT,solve());
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

