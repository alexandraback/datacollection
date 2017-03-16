#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>


using namespace std;

#define repp(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define rep(i,n) repp(i,0,(n)-1)

#define mp make_pair
#define pb push_back


void solve(){
	int r, c, m;
	cin >> r >> c >> m;
	char ans[60][60];
	bool flip = false;
	if(r > c) {
		flip = true;
		swap(r,c);
	}
	rep(i,r)rep(j,c) ans[i][j] = '*';
	int n = r * c - m;
//	cout << r <<' ' << c << ' ' << m << ' '<< n << endl;
	bool possible = true;
	if(n == 1){
		ans[0][0] = 'c';
	}else{
		if(r == 1){
			ans [0][0] = 'c';
			repp(i,1,n-1) ans[0][i] = '.';
		}else if(r == 2){
			if (n == 2 || (n%2==1) ) possible = false;
			else{
				rep(i, n/2) ans[0][i] = ans[1][i] = '.';
				ans[0][0] = 'c';
			}
		}else{
			if( n == 2 || n == 3 || n == 5 || n == 7){
				possible = false;
			}else{
				if(n >= 2*r){
					if(n % r != 1){
						rep(i,n) ans[i%r][i/r] = '.';
						ans[0][0] = 'c';
					}else{
						if(n/r == 2){
							rep(i,n) ans[i%(r-1)][i/(r-1)] = '.';
							ans[0][0] = 'c';
						}else{
							rep(i,n+1) ans[i%r][i/r] = '.';
							ans[0][0] = 'c';
							ans[r-1][n/r-1] = '*';
						}
					}
				}else{
					if(n%3 != 1){
						rep(i,n) ans[i%3][i/3] = '.';
						ans[0][0] = 'c';
					}else{
						rep(i,n+1) ans[i%3][i/3] = '.';
						ans[0][0] = 'c';
						ans[2][n/3-1] = '*';
					}
				}
			}
		}
	}
	if(possible){
		if(flip){
			rep(i,c){
				cout << endl;
				rep(j,r) cout << ans[j][i];
			}
		}else{
			rep(i,r){
				cout << endl;
				rep(j,c) cout << ans[i][j];
			}
		}
	}else{
		cout << endl;
		cout << "Impossible";
	}

}

int main(){
	int T;
	cin >> T;
	rep(i,T){
		cout << "Case #" << i+1 << ": ";
		solve();
		cout << endl;
	}
	return 0;
}


