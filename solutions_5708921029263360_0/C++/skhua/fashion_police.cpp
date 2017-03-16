#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int J, P, S, K;
vector<int> ans;
vector<int> now;
int JP[10][10], JS[10][10], PS[10][10];
bool used[10][10][10];
int maxi = 0;

void doit(vector<int> &now) {
	if (now.size() > maxi) {
		ans = now;
		maxi = now.size();
	}
	for (int i = 0; i < J; i++)
		for (int j = i; j < P; j++)
			for (int k = j; k < S; k++) {
				if (!used[i][j][k])
					if (JP[i][j] < K && JS[i][k] < K && PS[j][k] < K) {
						now.push_back(i*100+j*10+k);
						used[i][j][k] = true;
						JP[i][j]++;
						JS[i][k]++;
						PS[j][k]++;
						doit(now);
						now.pop_back();
						used[i][j][k] = false;
						JP[i][j]--;
						JS[i][k]--;
						PS[j][k]--;
					}
			}
}

void run_case(int tc) {
    cin >> J >> P >> S >> K;
	ans.clear();
	now.clear();
	maxi = 0;
	memset(JP, 0, sizeof(JP));
	memset(JS, 0, sizeof(JS));
	memset(PS, 0, sizeof(PS));
	memset(used, false, sizeof(used));
	doit(now);
	cout << "Case #" << tc << ": " << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << (ans[i]/100)+1 << " " << ((ans[i]%100)/10)+1 << " " << (ans[i] % 10)+1 << endl;
	}
}

int main() {
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		run_case(i);
	}
	return 0;
}