#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <strings.h>
#include <stdlib.h>
#include <limits.h>
#include <set>

using namespace std;

long long R, N, M, K;

void solve(vector<int> &products){
	vector<int> solution;
	for (int i = 0; i < N; i++){
		bool printed = false;
		for (int j = M; j >= 2; j--){
			int multiplos = 0;
			for (int k = 0; k < products.size(); k++){
				if ((products[i] % j) == 0){
					multiplos++;
					if (multiplos == 2){
						break;
					}
				}
			}
			if (multiplos == 2){
				for (int k = 0; k < products.size(); k++){
					if ((products[i] % j) == 0){
						products[i] /= j;
					}
				}
				printed = true;
				cout << j;
				break;
			}
		}
		if (!printed){
			cout << "1";
		}
	}
	cout << endl;
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		cout << "Case #" << (i + 1) << ": " << endl; 
		cin >> R >> N >> M >> K;
		for (int j = 0; j < R; j++){
			vector<int> products;
			for (int k = 0; k < K; k++){
				int product;
				cin >> product;
				products.push_back(product);
			}
			solve(products);
		}
	}
}
