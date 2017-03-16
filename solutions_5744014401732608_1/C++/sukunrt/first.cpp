#include <bits/stdc++.h>

using namespace std;

int edges[55][55];
long long m, ways[55], n, rem;

void solve(){
    for(int i = n-1; i >= 2; i--){
	for(int j = i+1; j <= n; j++){
	    if( ways[j] <= rem ){
		ways[i] += ways[j];
		rem -= ways[j];
		edges[i][j] = 1;
		edges[1][i]= 1;

	    }
	}

    }
}

int main(){
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
	cin >> n >> m;
	ways[n] = 1;
	edges[1][n] = 1;
	m--;
	rem = m;
	solve();
	cout << "CASE #" << cs << ": ";
	if( rem == 0 ){
	    cout << "POSSIBLE" << endl;
	    for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
		    
		    cout << edges[i][j];
		    edges[i][j] = 0;
		    ways[i] = 0;
		}
		cout << endl;
	    }
	}
	else{
	    cout << "IMPOSSIBLE" << endl;
	    for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
		    
//		    cout << edges[i][j];
		    edges[i][j] = 0;
		    ways[i] = 0;
		}
//		cout << endl;
	    }
	}
    }

    return 0;
}
	
		
