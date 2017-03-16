#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        int d[N], h[N], m[N];
        int total = 0;
        for (int i = 0; i < N; ++i) {
            cin >> d[i] >> h[i] >> m[i];
            total += h[i];
        }
        
        if ((N == 2) && (d[0] > d[1])) {
            swap(d[0], d[1]);
            swap(h[0], h[1]);
            swap(m[0], m[1]);
        }
        
        cout << "Case #" << tc << ": ";
        if ((total == N) && (N == 2)) {
            if (m[0] < m[1]) {
                cout << "1\n";
            } else  {
                cout << "0\n";
            }
        } else {
            cout << "0\n";
        }
        
    }

	return 0;
}

















