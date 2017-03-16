#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	cin >>test;
	for (int i=1; i<=test; ++i){
		cout <<"Case #" <<i <<": ";
		int n,m;
		cin >>n >>m;
		vector<vector<int> > a(n,vector<int>(m));
		vector<int> max_row(n),max_col(m);
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j){
				cin >>a[i][j];
				max_row[i]=max(max_row[i],a[i][j]);
				max_col[j]=max(max_col[j],a[i][j]);
			}
		bool f=true;
		for (int i=0; i<n; ++i)
			if (f){
				for (int j=0; j<m; ++j)
					if (a[i][j]<max_row[i] && a[i][j]<max_col[j]){
						f=false;
						break;
					}
			}
			else
				break;
		if (f)
			cout <<"YES";
		else
			cout <<"NO";
		cout <<endl;
	}
}