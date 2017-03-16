#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int a[1000][1000];
int r[1000], c[1000];
int main(){
	freopen("B-large.in","r", stdin);
	freopen("B.out","w", stdout);

	int T;
	cin>>T;
	for (int cas = 1; cas<=T; cas++){
		int n,m;
		cin>>n>>m;
		for (int i = 0; i<n; i++) r[i] = 0;
		for (int i = 0; i<m; i++) c[i] = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++){
				cin>>a[i][j];
				r[i] = max(r[i], a[i][j]);
				c[j] = max(c[j], a[i][j]);
			}
		bool yes = true;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				if (a[i][j] < r[i] && a[i][j] < c[j])
					yes = false;
		cout<<"Case #"<<cas<<": ";
		if (yes)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
