#include <iostream>
#include <cstdio>
using namespace std;
int getDigit(int N){
	int ret = 0;
	while (N)
		N/=10, ret++;
	return ret;	
}
int getPow10(int N){
	int ret = 1;
	while (N)
		N--, ret*=10;
	return ret;	
}
bool buff[2000001];
int main(){
	FILE *fin = fopen("input.txt","r"), *fout = fopen("output.txt","w");
	int T,A,B,c,p10, rec;
	fscanf(fin,"%d",&T);
	int j, tmp, k;
	for (int i = 0; i < T; i++){
		fscanf(fin,"%d %d",&A,&B);
		c = getDigit(A);
		p10 = getPow10(c-1);
		rec = 0;
		//fprintf(fout,"@@@@@@@@@@@@@@%d",i+1);
		for (j = A; j <= B; j++){
			for (k = 1, tmp = j; k < c; k++){
				tmp = (tmp%p10)*10+tmp/p10;
				//fprintf(fout," %d",tmp);
				if (tmp>=A && tmp<=B && buff[tmp]==0 && tmp>j)
					rec++,
					buff[tmp] = 1;
					//cout<<rec<<" "<<j<<" "<<tmp<<endl;
					//fprintf(fout,"[%d]",rec);
			}
			for (k = 1, tmp = j; k < c; k++){
				tmp = (tmp%p10)*10+tmp/p10;
				if (tmp>=A && tmp<=B)
					buff[tmp] = 0;
			}
		}
		fprintf(fout,"Case #%d: %d\n",i+1, rec);
	}
	//system("PAUSE");
	return 0;
}
