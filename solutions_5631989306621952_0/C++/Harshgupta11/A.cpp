#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

void solve()
{
    string S;
    deque<char> B;
    cin >> S;
    B.push_back(S[0]);
    for(int i = 1;i<S.size();++i){
       if(B[0] <= S[i]) B.push_front(S[i]);
       else             B.push_back(S[i]);
    }
    for(int i = 0;i<B.size();++i){
    	cout << B[i];
    }
    cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for(int i = 1;i<=T;++i){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}
