#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <string.h>
#include <bitset>
#include <functional>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <iomanip>
#define mp(a, b) make_pair(a, b)
typedef long long ll;
using namespace std;



int main(){
	int T;
	int N;
	int rows[2501][3];
	int heights[2501];
	vector<int> ret;
	cin >> T;
	for (int i = 0; i < T; i++){
		for (int j = 1; j <= 2500; j++){
			heights[j] = 0;
		}
		ret.clear();
		cin >> N;

		for (int j = 0; j < N*2-1; j++){
			for (int k = 0; k < N; k++){
				cin >> rows[j][k];
				heights[rows[j][k]]++;
			}
		}

		for (int j = 1; j <= 2500; j++){
			if (heights[j] % 2 == 1){
				ret.push_back(j);
				//cerr << j;
			}
		}
		
		sort(ret.begin(), ret.end());
		cout << "Case #" << i + 1 << ":";
		for (int j = 0; j < ret.size(); j++){
			cout << " " << ret.at(j);
		}
		cout << endl;
	}


	return 0;
}