#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

using namespace std;

int nn,b, p, r[100];
ll a[100],m, s;

int main(){
	
	cin >> nn;
	rep(ii,nn){
		cin >> b >> m; b--;
		rep(i,100)r[i]=0;

		a[0] = 1; s=1;
		if(b>1){
			a[1] = 1;
			s++;
		}

		for(int i=2;i<b;i++){
			a[i]=a[i-1]*2;
			s += a[i];
		}

		if(s < m){
			cout << "Case #"<<ii+1<<": IMPOSSIBLE"<<endl;
			continue;
		}

		for(int i=b-1;i>=0;i--){
			if(m - a[i]>=0){
				m -= a[i];
				r[i] = 1;
			}
		}
		cout << "Case #"<<ii+1<<": POSSIBLE"<<endl;
		rep(i, b){
			rep(j, b)cout<<(i<j ? "1" : "0");cout<<r[i]<<endl;
		}
		rep(i,b+1)cout<<'0';cout<<endl;
	}

}