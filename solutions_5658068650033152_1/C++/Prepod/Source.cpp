#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream inp("C-large.in");
	cin.rdbuf(inp.rdbuf());
	ofstream out("output.txt");
	cout.rdbuf(out.rdbuf());
	int T; cin>>T;
	for(int t=1; t<=T; t++) {
		int n, m, k; cin>>n>>m>>k;
		vector<vector<int>> ar(n, vector<int> (m));
		int x=n/2, y=m/2;
		ar[x][y]=2; k--;
		while(1) {
			int mx = 1000000000;
			for(int i=1; i<n-1; i++) {
				for(int j=1; j<m-1; j++) {
					if (ar[i][j]!=2) continue;
					int a = (ar[i+1][j]==0) + (ar[i-1][j]==0) + (ar[i][j+1]==0) + (ar[i][j-1]==0);
					if (a==0) continue;
					if (a<mx) {
						mx = a;
						x = i;
						y = j;
					}
				}
			}
			if (mx-1>k) break;
			if (ar[x+1][y] == 0) ar[x+1][y]=2;
			if (ar[x-1][y] == 0) ar[x-1][y]=2;
			if (ar[x][y+1] == 0) ar[x][y+1]=2;
			if (ar[x][y-1] == 0) ar[x][y-1]=2;
			ar[x][y] = 1;
			k-=mx;
		}
		int r=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if (ar[i][j]==2) r++;
		if (k>0) r+=k;
		cout<<"Case #"<<t<<": "<<r<<endl;
	}
	return 0;
}