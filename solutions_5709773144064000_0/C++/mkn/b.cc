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
	double c, f, x;
	cin >> c >> f >> x;
	double speed = 2.0;

	double ans = x;
	double now = 0;

	rep(n,100000){
		ans = min(ans, now + x/speed);
		now += c / speed;
		speed += f;
	}
	printf("%.7f",ans);
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


