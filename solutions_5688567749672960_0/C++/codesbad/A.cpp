#include <bits/stdc++.h>
using namespace std;

int bfs(int start,long long dest) {
	bool visited[1000010] = {0};
	queue<pair<int,int>>que;
	que.push(make_pair(start,0));
	while (!que.empty()) {
		pair<int,int>temp = que.front(); que.pop();
		int place = temp.first; 
		int depth = temp.second;
		if (place == dest) return depth;
		if (place > dest) continue;
		if (visited[place]) continue;
		visited[place] = true;
		//go up
		int newPlace = place+1;
		//cout <<"newPlace "<< newPlace << endl;
		que.push(make_pair(newPlace,depth+1));
		//reverse
		stringstream ss; ss << place;
		string s; ss >> s;
		reverse(s.begin(),s.end());
		//cout << s << endl;
		stringstream ss1(s);
		int np2; ss1>>np2;
		//cout << "np2 " << np2 << endl;
		que.push(make_pair(np2,depth+1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	//cout <<"hey" << endl;
	for(int caseNum=1;caseNum<=T;caseNum++) {
		long long N; cin >> N;
		int tot = bfs(0, N);
		cout << "Case #"<<caseNum<<": "<< tot << "\n";
	}
	return 0;
}