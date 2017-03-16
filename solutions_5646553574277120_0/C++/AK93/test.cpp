#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <hash_map>

using namespace std;
typedef long long ll;

void print(int test, int res){
	cout<<"Case #"<<test<<": "<<res<<"\n";
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int count_test;
	cin>>count_test;
	for(int test = 1; test <= count_test; test++){
		int res = 0;
		int c, d, v;
		cin>>c>>d>>v;
		vector<int> arr(v + 1, 0);
		vector<int> check(v + 1, 0);
		vector<int> g;
		for(int i=0; i<d; i++){
			int numb;
			cin>>numb;
			g.push_back(numb);
			check[numb] = 1;
		}
		
		for(int i=0; i<(1<<g.size()); i++){
			int sum = 0;
			for(int j=0; j<g.size(); j++){
				if(i & (1 << j))
					sum += g[j];
			}
			if(sum < arr.size())
				arr[sum] = 1;
		}

		int cnt = 0;
		for(int i=0; i<arr.size(); i++){
			if(arr[i] == 0)
				cnt++;
		}

		queue<pair<pair<vector<int>, pair<int, int> >, int> > q;
		q.push(make_pair(make_pair(arr, make_pair(0, 0)), cnt));
		while(!q.empty()){
			vector<int> cur = q.front().first.first;
			int last = q.front().first.second.first;
			int level = q.front().first.second.second;
			int count = q.front().second;
			if(count == 0){
				res = level;
				break;
			}
			q.pop();
			for(int i=last+1; i<=v; i++){
				if(check[i])
					continue;
				vector<int> buf = cur;
				int qwe = 0;
				for(int j=0; j<buf.size(); j++){
					if(cur[j] == 1 && j + i < cur.size() && cur[i + j] == 0){
						buf[j + i] = 1;
						qwe++;
					}
				}
				if(qwe){
					q.push(make_pair(make_pair(buf, make_pair(i, level + 1)), count - qwe));
				}
			}
		}
		cerr<<test<<"\n";
		print(test, res);
 	}

    return 0;
}