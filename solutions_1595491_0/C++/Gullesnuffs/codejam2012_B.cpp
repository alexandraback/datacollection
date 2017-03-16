#include <stdio.h>

using namespace std;

int main()
{
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.txt", "w");
	int T, score[105], caseN=1;
	fscanf(fin, "%d", &T);
	while(T--){
		int googlers, surprises, p, answer=0;
		fscanf(fin, "%d%d%d", &googlers, &surprises, &p);
		for(int i=0; i < googlers; ++i){
			fscanf(fin, "%d", score+i);
			if(p >= 2){
				if(score[i] >= 3*p-2)
					++answer;
				else if(score[i] >= 3*p-4 && surprises){
					++answer;
					--surprises;
				}
			}
			else if(p == 1){
				if(score[i] >= 3*p-2)
					++answer;
			}
			else if(p == 0)
				++answer;
		}
		if(p > 10)
			fprintf(fout, "Case #%d: 0\n", caseN);
		else
			fprintf(fout, "Case #%d: %d\n", caseN, answer);
		++caseN;
	}
	return 0;
}

