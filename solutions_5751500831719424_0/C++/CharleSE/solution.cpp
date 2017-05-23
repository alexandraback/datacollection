#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

FILE *in = fopen("A-small-attempt0.in", "r");
FILE *out = fopen("output.txt", "w");

typedef struct strings{
	vector<char> parsedChar;
	vector<int> parsedId;
}strings;

int main(){
	int cased, T, N;
	char compare[110];
	fscanf(in, "%d", &T);
	cased = T;
	while (T--){
		strings set[100];
		vector<int> minChar;
		vector<int> maxChar;
		int charSum = 0;
		int tempExecute = 2147483647;
		int execute = 0;
		fscanf(in, "%d", &N);
		int i, j;
		bool flag = false;
		for (i = 0; i < N; i++){
			fscanf(in, "%s", compare);
			int cnt = 0;
			set[i].parsedChar.push_back(compare[0]);
			cnt++;
			for (j = 1; j < strlen(compare); j++){
				if (compare[j] != set[i].parsedChar.back()){
					set[i].parsedId.push_back(cnt);
					cnt = 1;
					set[i].parsedChar.push_back(compare[j]);
				}
				else cnt++;
			}
			set[i].parsedId.push_back(cnt);
			if (i>0){
				if (set[i].parsedChar != set[0].parsedChar) { flag = true;}
			}
		}
		fprintf(out, "Case #%d: ", cased - T);
		if (flag) {
			fprintf(out, "Fegla Won\n"); continue;
		}
		else{
			minChar.resize(set[0].parsedChar.size());
			maxChar.resize(set[0].parsedChar.size());
			for (j = 0; j < minChar.size(); j++){
				charSum = 0;
				tempExecute = 2147483647;
				for (i = 0; i < N; i++){
					if (i>0 && set[i].parsedId[j] >= minChar[j]) ;
					else minChar[j] = set[i].parsedId[j];
					if (i > 0 && set[i].parsedId[j] <= maxChar[j]);
					else maxChar[j] = set[i].parsedId[j];
				}
				for (i = minChar[j]; i <= maxChar[j]; i++){
					charSum = 0;
					for (int k = 0; k < N; k++)
						charSum += abs(set[k].parsedId[j] - i);
					if (charSum < tempExecute) tempExecute = charSum;
				}
				execute += tempExecute;
			}
		}
		fprintf(out, "%d\n", execute);
	}
	fcloseall();
	return 0;
}