#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream inp("B-large.in");
	cin.rdbuf(inp.rdbuf());
	ofstream out("output.txt");
	cout.rdbuf(out.rdbuf());
	int t; cin>>t;
	for(int i=1;i<=t;i++){
		int n,m; cin>>n>>m;
		vector<vector<int>> ms(n);
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				int a; cin>>a; ms[j].push_back(a);
			}
		}
		vector<int> row(n,0);
		vector<int> col(m,0);
		int res=0;
		for(int s=100;s>=1;s--){
			for(int j=0;j<n;j++){
				for(int k=0;k<m;k++){
					if (ms[j][k]!=s) continue;
					if (row[j]==2 && col[k]==2) {res=1; goto end;}
					if (row[j]!=2) row[j]=1;
					if (col[k]!=2) col[k]=1;
				}
			}
			for(int j=0;j<n;j++)
				if (row[j]==1) row[j]=2;
			for(int k=0;k<m;k++)
				if (col[k]==1) col[k]=2;
		}
end:
		cout<<"Case #"<<i<<": ";
		if (res==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}