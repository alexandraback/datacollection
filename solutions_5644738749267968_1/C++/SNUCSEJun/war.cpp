#include<stdio.h>
#include<algorithm>
#define delta 0.0000001
using namespace std;

double naomi[1000];
double ken[1000];
int N;


void getData(){
	int i;
	scanf_s("%d", &N);
	for (i = 0; i < N; i++){
		scanf_s("%lf", &naomi[i]);
	}
	for (i = 0; i < N; i++){
		scanf_s("%lf", &ken[i]);
	}
	sort(naomi, naomi + N);
	sort(ken, ken + N);
}



int kenPlay(double target, bool used[]){
	int i;
	int j;
	for (i = N - 1; i >= 0; i--){
		if (used[i])
			continue;
		if (ken[i] > target){
			int j = i;
			while (ken[i] > target && i>=0){
				if (!used[i])
					j = i;
				i--;
			}
			used[j] = true;
			return 1;
		}
		else if (target > ken[i]){
			for (j = 0; j <= i; j++){
				if (used[j])
					continue;
				used[j] = true;
				return 0;
			}
		}
		else{
			printf("error : ken now knows that naomi is puppy!\n");
			return -1;
		}
	}
	return -1;
}

int imax(bool used[]){
	int i;
	for (i = N - 1; i >= 0; i--){
		if (used[i])
			continue;
		return i;
	}
	return i;
}
int imin(bool used[]){
	int i;
	for (i = 0; i < N; i++){
		if (used[i])
			continue;
		return i;
	}
	return i;
}

int Dnaomi(){
	bool kUsed[1000] = { 0, };
	bool nUsed[1000] = { 0, };
	int i,ik, nmin =0;
	double cnt = delta;
	int score = 0;
	for (i = N - 1; i >= nmin; i--){
		if (nUsed[i])
			continue;

		if (naomi[i] < ken[ik = imax(kUsed)] ){
			
			while (nUsed[nmin])
				nmin++;

			nUsed[nmin++] = true;
			//kUsed[ik] = true;
			kenPlay(ken[ik] - cnt, kUsed);
			cnt += delta;
			i++;				
		}
		else{
			int nminGrtrkmin;
			
			for (nminGrtrkmin = nmin; nminGrtrkmin <= i; nminGrtrkmin++){
				if (nUsed[nminGrtrkmin])
					continue;
				if (naomi[nminGrtrkmin] > ken[imin(kUsed)])
					break;
			}

			nUsed[nminGrtrkmin] = true;
			kenPlay(ken[ik] + cnt, kUsed);
			cnt += delta;
			score++;
			i++;
		}
	}
	return score;
}

int Nnaomi(){
	bool kUsed[1000] = { 0, };
	double cnt = delta;
	int score = 0;
	int i;
	for (i = N - 1; i >= 0; i--){
		if (0 == kenPlay(naomi[i], kUsed)){
			score++;
		}
	}
	return score;
}

int main(){
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		getData();
		printf("Case #%d: %d %d\n", i, Dnaomi(), Nnaomi());
	}
}