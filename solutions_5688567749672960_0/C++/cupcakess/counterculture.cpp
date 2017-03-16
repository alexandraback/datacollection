#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define infin 2147483647
#define pb push_back
#define rs resize
#define mp make_pair
#define sz(x) int((x).size())
#define vv(x) vector<vector<x> >
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int reversed(int n){
	string s = to_string(n);
	reverse(s.begin(), s.end());
	return stoi(s);
}

int main(){
	int tests;
	cin>>tests;
	for(int t=1; t<=tests; t++){
		int n;
		cin>>n;
		vector<unordered_set<int> > granne(n);
		for(int i=1; i<n; i++){
			granne[i].insert(i+1);
			int r = reversed(i);
			if(r <= n) granne[i].insert(r);
		}
		vector<int> dist(n+1, infin);
		queue<int> q;
		dist[1] = 1;
		for(q.push(1); !q.empty(); q.pop()){
			int f = q.front(), d = dist[f];
			// cout<<f<<endl;
			if(f == n) break;
			for(unordered_set<int>::iterator it = granne[f].begin(); it != granne[f].end(); it++){
				if(d+1 < dist[*it]){
					dist[*it] = d+1;
					q.push(*it);
				}
			}
		}
		printf("Case #%d: %d\n", t, dist[n]);
	}
}