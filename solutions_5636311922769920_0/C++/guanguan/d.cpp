#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

long long pau(long long a,long long b){ //power of a to b
	long long ans = 1;
	for (long long i = 0; i < b; i++){
		ans *= a;
	}
	return ans;
} 

int main(){
	ifstream fin("d.txt");
	FILE * fout = fopen("d_out.txt","w");
	int t;
	fin >> t;
	for (int i=0; i<t; i++){
		long long k,c,s;
		fin >> k >> c >> s;
		fprintf(fout,"Case #%d: ",i+1);
		long long tmp = pau(k,c-1);
		long long tmp2 = 1;
		for (int j = 0; j < k; j++){
			if (j != k - 1){
				fprintf(fout,"%lld ",tmp2);
			}
			else{
				fprintf(fout,"%lld\n",tmp2);
			}
			tmp2 += tmp;
		}
	}
	fin.close();
	fclose(fout);
}
