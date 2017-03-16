#include<cstdio>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

int t;
int n;
int data[25];
int table[2000005];

int main(){
    int i,j,ii;
    int ans1, ans2;
    int sum;
    int nn;
    FILE *in= fopen("input.txt","r");
    FILE *out = fopen("ouput.txt","w");
    fscanf(in, "%d", &t);
    for(int tcc = 1; tcc<= t; tcc++){
		memset(table,0,sizeof(table));
		fscanf(in, "%d",&n);
		nn = 1;
		for(i=0;i<n;i++){
			fscanf(in, "%d", &data[i]);
			nn*=2;
		}
		ans1 = ans2 = -1;
		for(i=1;i<nn;i++){
			ii = i;
			sum = 0;
			for(j=0;j<n;j++){
				if (ii%2 == 1){
					sum += data[j];
				}
				ii/=2;
			}
			if (table[sum]!=0){
				ans1 = i;
				ans2 = table[sum];
				break;
			}
			table[sum] = i;
		}
		printf("case: %d\n", tcc);
		fprintf(out, "Case #%d:\n", tcc);
		if (ans1 == ans2){
			fprintf(out, "Impossible\n");
			continue;
		}
		ii = ans1;
		for(j=0;j<n;j++){
			if (ii%2 == 1){
				fprintf(out, "%d ", data[j]);
			}
			ii/=2;
		}
		fprintf(out, "\n");
		ii = ans2;
		for(j=0;j<20;j++){
			if (ii%2 == 1){
				fprintf(out, "%d ", data[j]);
			}
			ii/=2;
		}
		fprintf(out, "\n");
    }
    return 0;
}
