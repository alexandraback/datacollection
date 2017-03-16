#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000100

int T, N, sol[ MAXN ];

int main() {
	ios::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	for(int j=1; j <= T; j++) {
	 in >> N;
	 memset(sol, 0, sizeof sol);
	 sol[ 1 ] = 1;
	 for(int i=1; i <= N; i++) {
		sol[ i+1 ] = ((sol[i+1]==0) ? 1+sol[i] : min(sol[i+1], 1+sol[i]));
		string tmp = to_string( i );
		reverse(tmp.begin(), tmp.end());
		int rev = stoi(tmp);
		if(rev <= N && rev >= i) sol[rev] = ((sol[rev]==0) ? 1 +sol[i] : min(sol[rev], 1+sol[i]));
		
	 }
	 out << "Case #"<<j<<": "<< sol[N] << endl;
    }
    return 0;
}
