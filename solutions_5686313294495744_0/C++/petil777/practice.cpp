#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ll long long
string str;
ll key = 0xffffffffffffff;
int test, n, number, fake;
map<string, int> M;
vector<int> list, vis;
vector<int> graph[1010];
struct my{
	int first, second;
	bool operator<(const my &i)const{

		if (first == i.first)return second < i.second;
		return first > i.first;
	}
}info[1010];
void bfs(int st)
{
	int cnt = 0;
	vis[st] = 1;
	queue<int> que;
	que.push(st);
	while (!que.empty()){
		int now = que.front(); que.pop();
		int fi = 0, se = 0;
		for (int i = 0; i < graph[now].size(); i++){
			
			int next = graph[now][i];
			if (info[now].first == info[next].first)fi = 1;
			else se = 1;
			if (vis[graph[now][i]])continue;
			vis[graph[now][i]] = 1;
			++cnt;
			que.push(graph[now][i]);
		}
		if (fi && se)++cnt;
	}
	fake += cnt/2;
}
int main(){
	freopen("C-small-attempt9.in", "r", stdin);
	freopen("C9.txt", "w", stdout);

	cin >> test;
	int lev = 0;
	while (test--){
		list.clear();
		number = 0;
		M.clear();
		++lev;
		cin >> n;
		vis = vector<int>(n + 1, 0);
		vector<int>one(2010, 0); vector<int>two(2010, 0); vector<int>ck(1010, 0);
		for (int i = 1; i <= n; i++){
			cin >> str;
			if (M.find(str) == M.end()){
				M[str] = ++number;
				info[i].first = number;
			}
			else info[i].first = M[str];
			cin >> str;
			if (M.find(str) == M.end()){
				M[str] = ++number;
				info[i].second = number;
			}
			else info[i].second = M[str];

			one[info[i].first]++;
			two[info[i].second]++;

		}
		fake = 0;
		//sort(info + 1, info + n + 1);
		for (int i = 1; i <= n; i++){
			if (one[info[i].first] == 1 || two[info[i].second] == 1){
				ck[i] = 1;
			}
		}
		one = two = vector<int>(2010, 0);
		for (int i = 1; i <= n; i++){
			if (ck[i]){
				one[info[i].first] ++; two[info[i].second]++;
			}
		}
		for (int i = 1; i <= n; i++){
			if (ck[i]){
				continue;
			}
			if (one[info[i].first] && two[info[i].second])ck[i] = -1, ++fake;
		}
		int off = 0;
	
		for (int i = 1; i <= n; i++){
			if (ck[i] != 1 && ck[i] != -1){
				list.push_back(i);
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < list.size(); j++){
				if (info[i].first == info[j].first || info[i].second == info[j].second){
					graph[i].push_back(j); graph[j].push_back(i);
				}
			}
		}
		for (int i = 1; i <= n; i++){
			if (ck[i] == 0 && !vis[i]){
				bfs(i);
			}
		}


		printf("Case #%d: ", lev);
		cout << fake << endl;
		for (int i = 1; i <= n; i++)graph[i].clear();
	}
}