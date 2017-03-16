#include <bits/stdc++.h>
using namespace std;

int ntest;
int n,cnt[3000],x;
int a[10][10];
void solve(int test) {
    cout << "Case #" << test+1 << ": ";
    cin >> n;
    memset(cnt,0,sizeof cnt);
    for(int i=0; i<2*n-1; i++){
      for(int j=0; j<n; j++){                
        cin >> x;         
				cnt[x] ++;   	
			}
    }    
    for(int i=1; i<2600; i++){
   	  if(cnt[i]&1) cout << i << " ";
    }
    cout << endl;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    for(int test=0; test< ntest; test++) {
        solve(test);
    }
    return 0;
}

