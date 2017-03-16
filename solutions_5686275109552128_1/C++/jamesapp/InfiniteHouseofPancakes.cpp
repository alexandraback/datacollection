#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int costb[1001];

int main(){
	cin.sync_with_stdio(false);

	int Tests;
	cin >> Tests;
	int diners;
	int pancakes;
	
	for (int t = 1; t <= Tests; t++){
		int maxpancakes = 1;
		int minpancakes = 1;
		memset(costb, 0, 1001 * sizeof(int));
		cin >> diners;
		map<int,int> m;
		for (int d = 0; d < diners; d++){
			cin >> pancakes;
			if (pancakes > maxpancakes){
				maxpancakes = pancakes;
			}
			m[pancakes]++;
		}
		minpancakes = int(sqrt(maxpancakes));
		for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
			int pan = it->first;
			int users = it->second;
			for (int t2 = minpancakes; t2 <= maxpancakes; t2++){
				costb[t2] += users * (int(ceil(pan/(float)t2))-1);
			}
		}
		int result = 1000;
		int proposal;
		for (int t2 = minpancakes; t2 <= maxpancakes; t2++){
			proposal = t2 + costb[t2];
			if (proposal < result){
				result = proposal;
			}
		}

		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
