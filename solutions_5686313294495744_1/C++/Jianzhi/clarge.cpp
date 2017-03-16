#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
typedef pair<string,string> pi;
int tc, n;
map<string,int> fm, sm;
int fc, sc;
string a, b;
vector<int> adjList[1005];
pi word[1005];
bool visited[1005];
int match[1005];

bool alternate(int x){
	visited[x] = true;
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); it++){
		if (match[*it] == x) continue;
		if (match[*it] == -1){
			match[*it] = x;
			match[x] = *it;
			return true;
		}
		if (visited[match[*it]]) continue;
		bool cur = alternate(match[*it]);
		if (cur){
			match[x] = *it;
			match[*it] = x;
			return true;
		}
	}
	return false;
}

void cleaning(){
	sm.clear();
	fm.clear();
	fc = 0;
	sc = 0;
	for (int i = 0; i < 1005; i++){
		adjList[i].clear();
	}
	memset(match, -1, sizeof(match));
}

int main(){
	freopen("C-large.in", "r", stdin);
	freopen("clargeout.txt", "w", stdout);
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++){
		cleaning();
		scanf("%d", &n);
		for (int j = 0; j < n; j++){
			cin >> a >> b;
			word[j] = make_pair(a, b);

			if (fm.find(a) == fm.end()){
				fm[a] = fc;
				fc++;
			}

			if (sm.find(b) == sm.end()){
				sm[b] = sc;
				sc++;
			}

		}

		for (int j = 0; j < n; j++){
			adjList[fm[word[j].first]].push_back(fc + sm[word[j].second]);
			adjList[fc + sm[word[j].second]].push_back(fm[word[j].first]);
		}

		for (int j = 0; j < fc; j++){
			memset(visited, 0, sizeof(visited));
			alternate(j);
		}

		int total = 0;
		for (int j = 0; j < fc + sc; j++){
			if (match[j] != -1){
				total++;
			} else {
				total += 2;
			}
		}
		printf("Case #%d: %d\n", i + 1, n - total/2);
		
	}
	
	
}
