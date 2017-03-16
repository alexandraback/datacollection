#include <iostream>
#include <cstdio>

using namespace std;

bool seen[15];
int num_seen = 0;

void reset(){
	for (int i=0; i<=9; i++){
		seen[i] = false;
	}
	num_seen = 0;
}

bool scan_num(long long n){ //If all numbers are seen, return true
	while (n != 0){
		int rem = n % 10;
		if (!seen[rem]){
			seen[rem] = true;
			num_seen += 1;
			if (num_seen == 10){
				return true;
			}
		}
		n /= 10;
	}
	return false;
}


int main(){
	FILE * fin = fopen("a.txt","r");
	FILE * fout = fopen("a_out.txt","w");
	int t;
	fscanf(fin,"%d",&t);
	for (int i=0; i<t; i++){
		long long n;
		fscanf(fin,"%lld",&n);
		if (n == 0ll){
			fprintf(fout,"Case #%d: INSOMNIA\n",i+1);
		}
		else{
			long long j = 0;
			while (true){
				j += n;
				if (scan_num(j)){
					break;
				}
			}
			fprintf(fout,"Case #%d: %lld\n",i+1,j);
		}
		reset();
	}
	fclose(fin);
	fclose(fout);
}
