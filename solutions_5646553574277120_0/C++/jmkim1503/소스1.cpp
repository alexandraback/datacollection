#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int C, D, V;
bool checker[10000];
bool iscoin[31];
bool all(void){

	for (int i = 1; i <= V; i++){
		if (checker[i] == false)
			return false;
	}
	return true;
}
int findsmall(void){

	for (int i = 1; i <= V; i++)
		if (checker[i] == false)
			return i;
}
int main(){
	FILE *fp1 = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "w");
	
	fscanf(fp1, "%d", &T);

	for (int test = 1; test <= T; test++){

		fscanf(fp1, "%d %d %d", &C, &D, &V);
		for (int i = 1; i <= V; i++){
			iscoin[i] = false;
		}
		vector<int> coin;
		for (int i = 0; i < D; i++){
			int num;
			fscanf(fp1, "%d", &num);
			iscoin[num] = true;
			coin.push_back(num);
		}
		for (int i = 1; i <= V; i++)
			checker[i] = false;
		checker[0] = true;
		sort(coin.begin(), coin.end());
		for (int i = 0; i < coin.size(); i++){
			vector<int> saver;
			for (int j = 1; j <= V; j++){

				if (checker[j] == false && j - coin[i] >= 0 && checker[j - coin[i]] == true){

					saver.push_back(j);
				}
			}
			for (int k = 0; k < saver.size(); k++){
				checker[saver[k]] = true;
			}
		}
		int cnt = 0;
		while (all() == false){

			cnt++;
			vector<int> saver;
			for (int j = 1; j <= V; j++){
				if (checker[j] == false && j - findsmall() >= 0 && checker[j - findsmall()] == true){

					saver.push_back(j);
				}
			}
			for (int k = 0; k < saver.size(); k++){
				checker[saver[k]] = true;
			}
		}
		fprintf(fp2, "Case #%d: %d\n", test, cnt);
	}
	return 0;
}