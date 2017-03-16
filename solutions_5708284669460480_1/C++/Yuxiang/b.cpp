#include<bits/stdc++.h>
#include <fstream>

using namespace std;
char key[110],word[110],type[110];
int T,K,L,S,noBana,E;
double one;

int NoBana(int l1,int l2){
	int s = 0;
	for(int i = 0; i < l2-l1+1; i++){
		int j = 0;
		while(type[i+j] == word[j] && j < l1){
			j++;
		}
		if (j==l1)
			s++;
	}
	return s;
}
int overlap(){
	int i = 1,j = 0;
	while(word[i+j] == word[j] && i+j < L){
		j++;
	}
	while(i+j != L){
		i++;
		j = 0;
		while(word[i+j] == word[j] && i+j < L){
			j++;
		}
	}
	return i;
}

void cal(int i){
	if (i == S ){
		int b = NoBana(L,S);
		if (b > noBana){
			noBana = b;
		}
		E = E + b;
	}else{
		for(int j = 0; j < K; j++){
			type[i] = key[j];
			cal(i+1);
		}
	}
}

double count(int l1, int l2){
	int k;
	double s = 1.0;
	for(int i = 0; i < l2; i++){
		k = 0;
		for(int j = 0; j < l1; j++){
			if (key[j] == word[i])
				k++;
		}
		s = (double)s * k / l1;
	}
	return s;
}
bool possible(){
	for(int i = 0; i < L; i++){
		int j = 0;
		while(key[j]!=word[i] && j < K){
			j++;
		}
		if (j==K)
			return false;
	}
	return true;
}

int main() {
	ifstream in("B-small.in");
	FILE *out;
	out = fopen("output","w");
	in >> T;
	for(int i = 0; i < T; i++){
		in >> K >> L >> S;
		in >> key;
		in >> word;
		if (possible()){
			int o = overlap();
			noBana = (S - L)/o + 1;
			one = (double)(S - L + 1) * count(K, L);
			fprintf(out,"Case #%d: %.7f\n", i+1, (double)noBana - one);}
		else{
			fprintf(out,"Case #%d: 0.0\n",i+1);
		}

	}
	in.close();
	fclose(out);
	return 0;
}
