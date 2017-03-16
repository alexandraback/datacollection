#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

#endif
	int t;
	int caseNumber = 0;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> dis(n + 1, INT_MAX/ 2);
		queue <int> que;
		que.push(1);
		dis[1] = 1;
		while (!que.empty()){
			int here = que.front();
			que.pop();
			string str = to_string(here);
			reverse(str.begin(), str.end());
			int there = stoi(str);
			if (here + 1 <= n){
				if (dis[here + 1] > dis[here] + 1){
					dis[here + 1] = dis[here] + 1;
					que.push(here + 1);
				}
			}
			if (there <= n){
				if (dis[there] > dis[here] + 1){
					dis[there] = dis[here] + 1;
					que.push(there);
				}
			}
		}
		printf("Case #%d: %d\n", ++caseNumber, dis[n]);
	}
}