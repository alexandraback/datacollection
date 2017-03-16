#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

ll matrix[2505];
void solve()
{
	memset(matrix,0,sizeof(matrix));
	ll N, temp,i;
	cin >> N;
	//cout << N<< '\n';
	ll size = N*(2*N-1);
	for( i = 1;i<=size;++i){
		cin >> temp;
		//cout << i << ' ' << temp << '\n';
		++matrix[temp];
	}
	for(int i = 1;i<=2500;++i){
		//cout << i << ' ' << matrix[i] << '\n';
		if(matrix[i]&1){
			cout << i << ' ' ;
			//cout << matrix[i] << '\n';
		}
	}
	cout << '\n';


}

int main()
{
	int T;
	cin >> T;
	for(int i = 1;i<=T;++i){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}
