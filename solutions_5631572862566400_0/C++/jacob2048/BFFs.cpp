#include <stdio.h>

int BFF[1050];
int visit[1050];
int max = 0;
int temp = 0;

void DFS(int start, int before, int now, int depth, int N);

int main(){
	FILE *Fin;
	FILE *Fout;
	int TestLoof = 0;
	int TestCount = 0;
	int i = 0, j = 0, k = 0;
	int num;
	int N;

	//Fin = fopen("input.txt", "r");
	Fin = fopen("C-small-attempt4.in", "r");
	Fout = fopen("output.txt", "w");

	fscanf(Fin, "%d", &TestCount);

	for (TestLoof = 1; TestLoof <= TestCount; TestLoof++){
		max = 0;
		fscanf(Fin, "%d", &N);
		for (i = 1; i <= N; i++){
			fscanf(Fin, "%d", &BFF[i]);
		}

		for (i = 1; i <= N; i++){
			visit[BFF[i]] = 1;
			temp = 0;
			DFS(i,i,BFF[i], 2, N);
			visit[BFF[i]] = 0;
		}

		fprintf(Fout, "Case #%d: ", TestLoof);

		fprintf(Fout, "%d\n", max);
	}
	fclose(Fout);
	fclose(Fin);

	return 0;
}
void  DFS(int start, int before, int now, int depth, int N){
	int flag = 0;
	int i = 0, j = 0;

	if (visit[BFF[now]] == 0 && BFF[now]!=start){
		flag = 1;
		visit[BFF[now]] = 1;
		DFS(start, now, BFF[now], depth + 1, N);
		visit[BFF[now]] = 0;
	}
	if (flag == 0 && before == BFF[now]){
		for (i = 1; i <= N; i++){
			if (i != start && visit[i] == 0){
				visit[i] = 1;
				temp = depth;
				DFS(start, now, i, depth + 1, N);
				visit[i] = 0;
				flag = 1;
			}
		}
	}
	if (flag == 0){
		if (start==BFF[now] || before ==BFF[now]){
			if (depth > max){
				max = depth;
			}
		}
		else{
			if (temp > max){
				max = temp;
			}
		}
	}
}