#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int D,P[1000];

string getstate() {
	string result = "";
	for(int i = 0; i < D; i++)
		result += (char)(P[i] + '0');
	return result;
}


int BFS() {
	int result = 1000;
	queue<pair<int,string> > Q;
	Q.push(make_pair(0,getstate()));
	while(!Q.empty() && Q.front().first < result) {
		int t = Q.front().first;
		string s = Q.front().second;
		Q.pop();
		// cout << t << " " << s << endl;
		int n = s[0] - '0';
		result = min(result, t + n);
		for(int i = 1; n - i >= i; i++) {
			string s2 = s.substr(1) + (char)(n - i + '0') + (char)(i + '0');
			sort(s2.begin(), s2.end(), std::greater<int>());
			Q.push(make_pair(t + 1, s2));
		}
	}
	return result;
}
	
int main() {
	int T; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cin >> D;
		for(int i = 0, x; i < D; i++) {
			cin >> P[i];
		}
		sort(P,P+D, std::greater<int>());
		cout << "Case #" << Z << ": " << BFS() << endl;
	}
}