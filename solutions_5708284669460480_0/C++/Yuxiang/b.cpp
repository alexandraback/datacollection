#include<bits/stdc++.h>
#include <fstream>

using namespace std;
char key[10],word[10],type[10];
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

int main() {
	ifstream in("B-small.in");
	FILE *out;
	out = fopen("output","w");
	in >> T;
	for(int i = 0; i < T; i++){
		in >> K >> L >> S;
		in >> key;
		in >> word;
		one = 1;
		for(int j = 0; j < S; j++){
			one = one/K;
		}
		noBana = 0;
		E = 0;
		cal(0);
		cout << noBana<<' '<<one<<' '<<E<<endl;
		fprintf (out,"Case #%d: %.7f\n",i+1,noBana - (double)E*one);
	}
	in.close();
	fclose(out);
	return 0;
}
