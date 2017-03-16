// IN THE NAME OF GOD

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long int lld;
typedef long double ldb;

#define all(c) c.begin(),c.end()
#define tr(c,it) for(__typeof(c.begin()) it; it!=c.end(); it++)

#define ff ifstream cin; ofstream cout; cout.open("out.txt");

// Aditya Jain

int main(){
	int t;
	ff
	cin.open("B-small-attempt0 (1).in");
	cin >> t;
	int j=0;
	while(t--){
		j++;
		int n, x;
		cin >> n;
		map <int,int> M;
		for(int i=0; i<2*n-1; i++){
			for(int j=0; j<n; j++){
				cin >> x;
				M[x]++;
			}
		}
		vector <int> ans;
		for(int i=0; i<=2500; i++){
			if(M[i]!=0 && M[i]%2==1){
				ans.pb(i);
			}
		}
		
		cout << "Case #" << j << ": ";
		sort(all(ans));
		for(int i=0; i<ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
