#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;

int b[60][60];
vi v[110];
int used[110];
int rowcnt[51];
int colcnt[51];

int n;

bool isfull(){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(rowcnt[i]){
			cnt++;
		}

		if(colcnt[i]){
			cnt++;
		}
	}

	return cnt == 2*n - 1;
}

bool checkrow(vi &vv, int row){
	for(int i = 0; i < n; i++){
		if(b[row][i] != -1){
			if(vv[i] != b[row][i]){
				return false;
			}
		}
	}
	return true;
}

bool checkcol(vi &vv, int col){
	for(int i = 0; i < n; i++){
		if(b[i][col] != -1){
			if(vv[i] != b[i][col]){
				return false;
			}
		}
	}
	return true;
}

int bf(){
	if(isfull()){
		return 1;
	}else{
		int mnpos = 10000;
		int mnidx = -1;

		for(int i = 0; i < 2*n - 1; i++){
			if(!used[i]){
				int cur = 0;
				for(int j = 0; j < n; j++){
					if(!rowcnt[j]){
						cur += checkrow(v[i], j);
					}
				}

				for(int j = 0; j < n; j++){
					if(!colcnt[j]){
						cur += checkcol(v[i], j);
					}
				}

				if(cur < mnpos){
					mnpos = cur;
					mnidx = i;
				}
			}
		}

		for(int j = 0; j < n; j++){
			if(!rowcnt[j]){
				if(checkrow(v[mnidx], j)){
					for(int k = 0; k < n; k++){
						b[j][k] = v[mnidx][k];
					}
					rowcnt[j] = 1;
					used[mnidx] = 1;
					return bf();
				}
			}
		}

		for(int j = 0; j < n; j++){
			if(!colcnt[j]){
				if(checkcol(v[mnidx], j)){
					for(int k = 0; k < n; k++){
						b[k][j] = v[mnidx][k];
					}
					colcnt[j] = 1;
					used[mnidx] = 1;
					return bf();
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;	
	for(int t = 1; t <= T; t++){
		cin >> n;
		for(int i = 0; i < 110; i++){
			v[i].clear();
		}
		memset(b, -1, sizeof b);
		memset(rowcnt, 0, sizeof rowcnt);
		memset(colcnt, 0, sizeof colcnt);
		memset(used, 0, sizeof used);

		int mn = 1000000;
		int mx = 0;
		for(int i = 0; i < 2*n - 1; i++){
			for(int j = 0; j < n; j++){
				int aux;
				cin >> aux;
				mn = min(aux, mn);
				mx = max(aux, mx);
				v[i].pb(aux);
			}	
		}

		int mncnt = 0;
		int mxcnt = 0;
		for(int i = 0; i < 2*n - 1; i++){
			for(int j = 0; j < n; j++){
				if(v[i][j] == mn){
					mncnt ++;
				}

				if(v[i][j] == mx){
					mxcnt++;
				}
			}
		}
	

		int tofind = 0;
		if(mncnt == 2){
			tofind = mn;
		}else{
			tofind = mx;
		}

		vi mnv;
		for(int i = 0; i < 2*n - 1; i++){
			for(int j = 0; j < n; j++){
				if(v[i][j] == tofind){
					mnv.pb(i);
					break;
				}
			}
		}

		used[mnv[0]] = 1;
		used[mnv[1]] = 1;

		
		if(tofind == mn){
			for(int i = 0; i < v[mnv[0]].size(); i++){
				for(int j = 0; j < n; j++){
					b[0][j] = v[mnv[0]][j];
				}
			}
			rowcnt[0] = 1;
			for(int i = 0; i < v[mnv[1]].size(); i++){
				for(int j = 0; j < n; j++){
					b[j][0] = v[mnv[1]][j];
				}
			}
			colcnt[0] = 1;
		}else{
			for(int i = 0; i < v[mnv[0]].size(); i++){
				for(int j = 0; j < n; j++){
					b[n-1][j] = v[mnv[0]][j];
				}
			}
			rowcnt[n-1] = 1;
			for(int i = 0; i < v[mnv[1]].size(); i++){
				for(int j = 0; j < n; j++){
					b[j][n-1] = v[mnv[1]][j];
				}
			}
			colcnt[n-1] = 1;

		}

		bf();
		
		cout << "Case #" << t << ":";
		bool ok = false;
		for(int i = 0; i < n; i++){
			if(rowcnt[i] == 0){
				for(int j = 0; j < n; j++){
					cout << " " << b[i][j];
				}	
				break;
			}
		}

		if(!ok){
			for(int i = 0; i < n; i++){
				if(colcnt[i] == 0){
					for(int j = 0; j < n; j++){
						cout << " " << b[j][i];
					}	
					break;
				}
			}
		}

		cout << endl;

	}
	
	return 0;
}
