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


int memo[50][50];


int summemo[50];
int nmemo[50];
int main(){
	int B;
	long long M;
	long long count;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> B >> M;
		
		long long sum = 0;
		for (int i = 0; i < B-2; i++){
			summemo[B - i - 2] = sum+1;
			sum += sum + 1;
			
			
		}
		summemo[B - 1] = 1;
		for (int i = 0; i<B; i++){
			//cerr << summemo[i] << endl;
			nmemo[i] = -1;
		}
		sum += 1;
		cerr << "Case #" << t + 1 << ": " << sum << endl;
		count = sum;
		cout << "Case #" << t+1 << ": ";
		if (M>sum){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < B; i++){
				for (int j = 0; j < B; j++){
					if (i>=j){
						cout << "0";
					}
					else if (i!=0 && nmemo[i] == i-1){
						cout << "0";
					}
					else if (count- summemo[j]>=M){
						count -= summemo[j];
						cout << "0";
						if (nmemo[j] == i - 1){
							nmemo[j] = i;
						}
					}
					else{
						cout << "1";
					}
				}
				cout << endl;
			}
			cerr << count << endl;
		}
	}


	return 0;
}