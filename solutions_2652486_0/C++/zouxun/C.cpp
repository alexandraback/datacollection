#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int a[55];
int main()
{
	int cases;
	cin >> cases;
	printf("Case #1:\n");
	int R, N, M, K;
	cin >> R >> N >> M >> K;
	for (int t = 0; t < R; ++t) {
		bool p[150];
		memset(p, 0, sizeof(p));
		for (int j = 0; j < K; ++j) {
			cin >> a[j];			
			for (int i = 2; i < 150; ++i)
				if (a[j] % i == 0) p[i] = true;
		}

		vector<int> v;
		v.clear();
		if (p[27]) v.push_back(3);
		if (p[3]) v.push_back(3);		
		if (p[9]) v.push_back(3);
		if (p[125]) v.push_back(5);
		if (p[25]) v.push_back(5);
		if (p[5]) v.push_back(5);
		if (p[64]) {
			v.push_back(4);	
			v.push_back(4);	
			v.push_back(4);	
		} else
		if (p[16]) {
			v.push_back(4);
			if (v.size() == 1) v.push_back(4);
		} else if (p[8]){
			if (v.size() <= 2) v.push_back(4);
		} if (p[4]) {
			if (v.size() == 2) v.push_back(4);
		}

		int l = v.size();
		for (int t = 0; t < 3 - (int)l; t++)
			v.push_back(2);
		for (int t = 0; t < v.size(); ++t)
			cout << v[t];
		cout << endl;
	}
	return 0;
}
