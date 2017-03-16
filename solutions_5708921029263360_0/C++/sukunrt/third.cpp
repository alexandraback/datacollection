#include <bits/stdc++.h>

using namespace std;

int done[10][8][7];
int pairs[10][9][8];
int am, bm, cm, k_mx;

int check_pairs(int a, int b, int c){
    return( pairs[1][a][b] < k_mx &&
	    pairs[2][a][c] < k_mx &&
	    pairs[3][b][c] < k_mx );
};

	    

vector<int> generate_outfit(){

    for(int i = 1; i <= am; i++){
	for(int j = 1; j <= bm; j++){
	    for(int k = 1; k <= cm; k++){
		if( !done[i][j][k] && check_pairs(i,j,k) ){
		    done[i][j][k] = 1;
		    pairs[1][i][j]++;
		    pairs[2][i][k]++;
		    pairs[3][j][k]++;

		    vector<int> res;
		    res.push_back(i);
		    res.push_back(j);
		    res.push_back(k);
		    return res;
		}
	    }
	}
    }
    vector<int> res;
    return res;
};

int main(){
    int t;
    cin >> t;
    for( int cs = 1; cs <= t; cs++){
	cin >> am >> bm >> cm >> k_mx;
	vector< vector<int> > sol;
	while(true){
	    vector<int> x = generate_outfit();
	    if( x.size() == 0 ) break;
	    sol.push_back(x);
	}
	cout << "Case #" << cs << ": ";
	cout << sol.size() << endl;
	for(int i = 0; i < sol.size(); i++){
	    for(int j = 0; j < 3; j++){
		cout << sol[i][j];
		if( j == 2 ) cout << endl;
		else cout << " ";
	    }
	}
	for(int i = 0 ; i < 6; i++)
	    for(int j = 0; j < 6; j++)
		for(int x = 0; x < 6; x++){
		    done[i][j][x] = 0;
		    pairs[i][j][x] = 0;
		}
    
		    
    };
}
	
	
		    
    
