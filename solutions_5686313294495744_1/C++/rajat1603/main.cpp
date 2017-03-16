#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
int t;
int tc = 0;
int n;
string str1[N];
string str2[N];
int arr1[N];
int arr2[N];
map < string , int > m1;
map < string , int > m2;
int cur1;
int cur2;
vector < int > v[N];
int match[N];
bool visited[N];
bool dfs(int node){
	if(visited[node]){
		return 0;
	}
	visited[node] = 1;
	for(int next : v[node]){
		if(match[next] == -1 || dfs(match[next])){
			match[next] = node;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin >> t;
	while(t--){
		++tc;
		cout << "Case #" << tc << ": "; 
		cin >> n;
		for(int i = 1 ; i <= n ; ++i){
			str1[i] = "";
			str2[i] = "";
			cin >> str1[i] >> str2[i];
		}
		m1.clear();
		m2.clear();
		cur1 = 0;
		cur2 = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(m1[str1[i]] == 0){
				m1[str1[i]] = ++cur1;
			}
			if(m2[str2[i]] == 0){
				m2[str2[i]] = ++cur2;
			}
		}
		for(int i = 1 ; i <= n ; ++i){
			arr1[i] = m1[str1[i]];
			arr2[i] = m2[str2[i]];
		}
		for(int i = 1 ; i <= n ; ++i){
			v[i].clear();
		}
		for(int i = 1 ; i <= n ; ++i){
			v[arr1[i]].emplace_back(arr2[i]);
		}
		memset(match , -1 , sizeof(match));
		memset(visited , 0 , sizeof(visited));
		int ans = cur1 + cur2;
		for(int i = 1 ; i <= cur1 ; ++i){
			ans -= dfs(i);
			memset(visited , 0 , sizeof(visited));
		}
		cout << n - ans << endl;
	}
}