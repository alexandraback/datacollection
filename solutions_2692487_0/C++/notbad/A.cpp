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
	if (n == 0) {
		return 0;
	}
	if (w == 1) {
		return 150;
	}
	int i = 0;
	int add = 0;
	while (i < n) {
		if (w > arr[i]) {
			w += arr[i];
			++i;
		} else {
			++add;
			w += w - 1;
		}
	}
	return add;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	//cout << T <<endl;
	for (int t = 0; t < T; ++t) {
		int w, n;
		vector<int> data;
		cin >> w >> n;
		data.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		sort(data.begin(), data.end());
		int re = n + 1;
		for (int i = 0; i <= n; i++) {
			int temp = get_ops(w, data, i);
			if (re > temp + n - i) {
				re = temp + n - i;
			}
		}
		cout << "Case #" << t+1 << ": " << re << endl;
	}
	
}
