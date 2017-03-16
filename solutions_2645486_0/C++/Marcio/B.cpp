#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,n) fr(i,0,n)
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
#define N 20

int pd[N][N], v[N];
int e, r, n;

int memo(int ind, int val){
	if(ind == n) return 0;
	int& rec = pd[ind][val];
	if(~rec) return rec;
	
	rep(i, val+1){
		rec = max(rec, i * v[ind] + memo(ind+1, min(e, val - i + r)));
	}
	
	return rec;
}


int main(){
	ios::sync_with_stdio(false);
	int casos;
	 cin >> casos;
	 
	 rep(cas, casos){
	 	cin >> e >> r >> n;
	 	rep(i, n) cin >> v[i];
	 	memset(pd, -1, sizeof pd);
	 	int cont = memo(0, e);
		cout << "Case #" << (cas+1) << ": " <<  cont << endl;
	 }
}


