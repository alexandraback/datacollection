#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ALL(x) x.begin(),x.end()


int A[100][100];
int main(int argc, char const *argv[])
{
	freopen("ins.txt","r",stdin);
	freopen("outs.txt","w",stdout);
	int t;
	cin >> t;
	int ctr = 1;
	while(t--){
		int cts[3000] = {0};
		cout << "Case #"<<ctr<<": ";
		int n;
		cin >> n;
		for(int i = 1 ; i <= 2*n-1 ; i++){
			for(int j = 1 ; j <= n ; j++){
				cin >> A[i][j];
				cts[A[i][j]]++;
			}
		}
		vector<int> ans;
		for(int i = 1 ; i <= 2500 ; i++){
			if(cts[i]%2)
				ans.pb(i);
		}
		sort(ALL(ans));
		for(int i = 0 ; i < ans.size() ; i++)
			cout << ans[i] << " ";
		cout << "\n";
		ctr++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}