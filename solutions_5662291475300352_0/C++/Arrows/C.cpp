#include <bits/stdc++.h>

using namespace std;

void work(int cas) {

    int n;
    cin >> n;
    vector<pair<int, int> > vec;
    for(int i = 1; i <= n; i++) {
	int d, t, m;
	cin >> d >> t >> m; 
	if (t == 1){
	    vec.push_back (make_pair (d, m));
	}else{
	    vec.push_back (make_pair (d, m));
	    vec.push_back (make_pair (d, m+1));
	}
    }
    double x1 = (360.0-vec[0].first)/360.0*vec[0].second;
    double x2 = (360.0-vec[1].first)/360.0*vec[1].second;
    double x3 = (720.0-vec[0].first)/360.0*vec[0].second;
    double x4 = (720.0-vec[1].first)/360.0*vec[1].second;
    int ans = 1;
    if (x1 < x2 && x3 > x2){
	ans = 0;
    }
    if (x2 < x1 && x4 > x1){
	ans = 0;
    }
    cout << "Case #" << cas << ": " << ans << endl;
}

int main (){
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas ++){
	work(cas);
    }
}



