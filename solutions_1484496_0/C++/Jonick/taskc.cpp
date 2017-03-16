#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector< vector< int > > solveDP( int mod, const vector<int>& a )
{
	vector< vector< int > > res(a.size() + 1, vector<int>(mod, -1));
	res[a.size()][0] = 0;
	for( int i = a.size() - 1; i >= 0; i-- ) {
		for( int j = 0; j < mod; j++ ) {
			if( res[i+1][j] == 0 ) {
				res[i][(j+a[i]) % mod] = 0;
				res[i][(j-a[i]%mod+mod) % mod] = 0;
				res[i][j] = 0;
			} 
		}
	}
	return res;
}

int iterationsLeft = 0;
bool search(int n, vector<int> cur, vector<int>& ans, const vector<int>& a, const vector< vector< vector<int> > >& ar )
{
	if( iterationsLeft < 0 ) {
		return false;
	}
	iterationsLeft--;
	for( int i = 0; i < ar.size(); i++ ) {
		if( ar[i][n][cur[i]] != 0 ) {
			return false;
		}
	}
	if( n >= a.size() ) {
		bool isAll0 = true;
		for( int i = 0; i < ans.size(); i++ ) {
			if( ans[i] != 0 ) {
				isAll0 = false;
			}
		}
		if( isAll0 ) {
			return false;
		}
		for( int i = 0; i < ans.size(); i++ ) {
			if( ans[i] == 1 ) {
				cout << a[i] << " ";
			}
		}
		cout << endl;
		for( int i = 0; i < ans.size(); i++ ) {
			if( ans[i] == -1 ) {
				cout << a[i] << " ";
			}
		}
		cout << endl;
		return true;
	}
	for( int nxt = -1; nxt <= 1; nxt++ ) {
		vector<int> aa = cur;
		ans[n] = nxt;
		for( int i = 0; i < ar.size(); i++ ) {
			aa[i] = (aa[i] + nxt * (a[n] % ar[i][0].size()) + ar[i][0].size()) % ar[i][0].size();
		}
		if( search(n+1, aa, ans, a, ar) ) {
			return true;
		}
	}
	return false;
}

void solveTest()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for( int i = 0; i < n; i++ ) {
		cin >> a[i];
	}
	vector < vector<vector<int> > > ar;
	for( int i = 0; i < 20; i++ ) {
		int mod = rand() % 3000 + 500;
		ar.push_back( solveDP( mod, a ) );
	}

	iterationsLeft = 1000000;
	vector<int> ans(ar.size());
	if( !search(0, vector<int>(ar.size()), ans, a, ar) ) {
		cout << "Impossible" << endl;
	}
}

int main()
{
	srand(49104141);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc = 0;
	cin >> tc;
	for( int i = 1; i <= tc; i++ ) {
		cout << "Case #" << i << ":" << endl;
		solveTest();
	}
	return 0;
}
