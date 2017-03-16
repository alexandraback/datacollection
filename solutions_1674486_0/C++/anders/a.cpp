#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

vector<int> v[1001];
bool visited[1001];

int main(){
	int cases;
	cin >> cases;
	for(int c=1; c<=cases; ++c){
		printf("Case #%d: ",c);
		int n;
		cin >> n;
		for(int i=1; i<=n; ++i){
			v[i].clear();
			int x;
			cin >> x;
			for(int j=0; j<x; ++j){
				int y;
				cin >> y;
				v[i].push_back(y);
			}
		}
		bool yes=false;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				visited[j]=false;
			}
			queue<int> q;
			q.push(i);
			
			while(!q.empty()){
				int current=q.front();
				q.pop();
				if(visited[current]){
					yes=true;
					break;
				}
				visited[current]=true;
				for(int j=0; j<v[current].size(); ++j){
					q.push(v[current][j]);
				}

			}
			if(yes) break;
		}
		if(yes){
			printf("Yes\n");
		}else{
			printf("No\n");
		}

	}

	return 0;
}

