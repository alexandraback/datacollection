#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>

using namespace std;


int get_ops(int w,vector<int> arr, int n) {
    int i = 0;
	int op = 0;
	while (i < n) {
		if (w > arr[i]) {
			w += arr[i];
			++i;
		} else {
			++op;
			w += w - 1;
			if (w == 1) {
				return 256;
			}
		}
	}
	return op;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int w, n;
		vector<int> arr;
		cin >> w >> n;
	//	cout << w << " " << n << endl;
		arr.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			//cout << arr[i] << endl;
		}
		sort(arr.begin(), arr.end());
		int res = n + 1;
		for (int i = 0; i <= n; i++) {
			int temp = get_ops(w, arr, i);
			//cout << temp << endl;
			if (res > temp + n - i) {
				res = temp + n - i;
			}
		}
		cout << "Case #" << t << ": " << res << endl;
	}
	//while(1);
	
}
