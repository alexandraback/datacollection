#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream fin;
	fin.open("B-small-attempt1.in");
	//ofstream fout;
	//fout.open("B-small-attempt0.out");
	FILE* fout;
	fout = fopen("B-small-attempt1.out", "w");
	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int k, l, s;
		fin >> k >> l >> s;
		string a, b;
		fin >> a >> b;

		int maxlen = -1;
		for (int i = 1; i < l; i++){
			int flag = 1;
			for (int j = 0; j < l - i; j++){
				if (b[j] != b[i+j]){
					flag = 0;
					break;
				}
			}
			if (flag){
				if (maxlen < l - i){
					maxlen = l - i;
				}
			}
		}


		int ready;
		if (maxlen != -1){
			ready = (s - maxlen) / (l - maxlen);
		}
		else{
			ready = s / l;
		}

		float give = 1;

		int alpha[26] = { 0, };
		for (int i = 0; i < k; i++){
			alpha[a[i]-'A']++;
		}

		for (int i = 0; i < l; i++){
			give *= (float)alpha[b[i] - 'A'] / k;
		}
		give *= ready;
		if (give != 0){
			give = ready - give;
		}

		fprintf(fout, "Case #%d: %.8f\n", T, give);
		/*
		fout << "Case #" << T << ": ";
		fprintf(fout, )
		fout.precision(8);
		fout << give;
		fout << endl;
		*/
	}

}