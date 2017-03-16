#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <strings.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

vector < long long > products;

map<long long, vector< vector < int > > > possibilities;

int chances[5];

void calculateAllPossibilities(int N, int M){
	if (N <= 1){
		for (int i = 2; i <= M; i++){
			vector<int> solution;
			solution.push_back(i);
			possibilities[i].push_back(solution);
		}
	} 
	if (N <= 2) {
		for (int i = 2; i <= M; i++){
			for (int j = i; j <= M; j++){
				vector<int> solution;
				solution.push_back(i);
				solution.push_back(j);
				possibilities[i*j].push_back(solution);
			}
		}
	} 
	if (N >= 3){
		for (int i = 2; i <= M; i++){
			for (int j = i; j <= M; j++){
				for (int k = j; k <= M; k++){
					vector<int> solution;
					solution.push_back(i);
					solution.push_back(j);
					solution.push_back(k);
					possibilities[i*j*k].push_back(solution);
				}
			}
		}
	}
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		cout << "Case #" << (i + 1) << ": " << endl; 
		products.clear();
		for (int j = 0; j < 5; j++){
			chances[j] = 0;
		}
		long long R, N, M, K;
		cin >> R >> N >> M >> K;

		calculateAllPossibilities(N, M);

		for (long long j = 0; j < R; j++){
			for (long long j2 = 0; j2 < K; j2++){
				long long product;
				cin >> product;
				products.push_back(product);
				if (possibilities[product].size() == 0){
					cout << "EO: " << product << endl;
				}
				for (int k = 0; k < possibilities[product].size(); k++){
					for (int l = 0; l < possibilities[product][k].size(); l++){
						chances[possibilities[product][k][l]]++;
					}
				}
			}
			for (int j = 0; j < products.size(); j++){
				int bestChances = -1;//maximizar
				int bestIndex;
				int product = products[i];
				for (int k = 0; k < possibilities[product].size(); k++){
					int minChance = INT_MAX;
					for (int l = 0; l < possibilities[product][k].size(); l++){
						minChance = min(minChance, chances[possibilities[product][k][l]]);
					}
					if (minChance > bestChances){
						bestIndex = k;
						bestChances = minChance;
					}
				}
				for (int l = 0; l < possibilities[product][bestIndex].size(); l++){
					cout << possibilities[product][bestIndex][l];
				}
				cout << endl;
			}
		}
	}
}
