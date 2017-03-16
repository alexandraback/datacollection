#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <strings.h>
#include <string.h>
using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		cout << "Case #" << (t+1) << ": ";
		int appearance[2600];
		for (int i = 0; i < 2600; i++){
			appearance[i] = 0;
		}
		int N;
		cin >> N;
		for (int i = 0; i < 2 * N - 1; i++){
			for (int j = 0; j < N; j++){
				int d;
				cin >> d;
				appearance[d]++;
			}
		}
		for (int i = 0; i < 2600; i++){
			if (appearance[i] % 2){
				cout << i << " ";
			}
		}
		cout << endl;
	}
}
