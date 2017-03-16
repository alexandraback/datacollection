#include <bits/stdc++.h>
using namespace std;
int f[1010];
bool ok[1010];
bool visited[1010];
int end[1010];
int main(){
	int test;
	scanf("%d", &test);
	for (int w = 1; w <= test; w++) {
		printf("Case #%d: ", w);
		int n, x;
		cin>>n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			f[i] = x - 1;
		}
		int self = 0;
		for (int i = 0; i < n; i++) end[i] = 0;
		for (int i = 0; i < n; i++) {
			if(f[f[i]] == i) {
				self++;
			}
		} 
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			int st = i;
			for (int j = 0; j < n; j++) visited[j] = false;
			visited[st] = true;
			int cnt = 0, cy;
			while (true){
				cnt++;
			    // cout<<st<<" ";
			    st = f[st];
			    if(visited[st]) {
			    	cy = st;
			    	// cout<<endl;
			    	break;
			    } 
			    visited[st] = true;
			}
			// cout<<cnt<<endl;
			// cout<<cy<<endl;
			int cysiz = 1;
			st = f[st];
			while (st != cy){
			    cysiz++;
			    st = f[st];
			}
			// cout<<cysiz<<endl;
			maxi = max(maxi, cysiz);
			if(cysiz == 2) {
				end[cy] = max(end[cy], cnt - 2);
				// cout<<cy<<" here "<<end[cy]<<endl;
			} 
		}
		for (int i = 0; i < n; i++) {
			if(f[f[i]] == i) {
				// cout<<end[i]<<" * "<<end[f[i]]<<endl;
				maxi = max(maxi, end[i] + end[f[i]] + 2);
			}
		}
		cout<<maxi<<endl;
	}
}