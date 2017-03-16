#include<bits/stdc++.h>
using namespace std;
map<int,int> M;
queue<int> Q;
int reverse(int a)
{
	int ans = 0;
	while (a) {
		ans = 10*ans + a%10;
		a /= 10;
	}	
	return ans;
}
int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for (int tc = 1; tc <= 1; tc++) {
		while(!Q.empty()) Q.pop();
		Q.push(1);
		M[1] = 1;
		while(!Q.empty()) {
			int x = Q.front();
			Q.pop();
			if (x > 1000000) continue;
			if(M.find(x+1) ==M.end()){
				M[x+1]=M[x]+1;
				Q.push(x+1);
			}
			if(M.find(reverse(x)) == M.end()) {
				M[reverse(x)] = M[x] + 1;
				Q.push(reverse(x));
			}
		}	
		
	}
	for(int tc = 1; tc <= t; tc++) {
		int n;
		cin>>n;
		cout<<"Case #"<<tc<<": "<<M[n]<<endl;
	}
	return 0;
}
