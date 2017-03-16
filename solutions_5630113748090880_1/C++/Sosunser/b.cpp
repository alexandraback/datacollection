#include <bits/stdc++.h>
using namespace std;

int t,n,x;

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		scanf("%d",&n);
		map<int,int> m;
		for(int i = 0; i < n*2-1; i++){
			for(int j = 0; j < n; j++){
				scanf("%d",&x);
				m[x]++;
			}
		}
		set<int> res;
		for(auto i : m) if(i.second%2 == 1) res.insert(i.first);
		cout << "Case #" << k+1 << ": ";
		for(int i : res) cout << i << " ";
		cout << endl;
	}
}