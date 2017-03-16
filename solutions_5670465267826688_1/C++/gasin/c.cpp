#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

char a[3] = {'i','j','k'};

char calc(char x, char y, int &z){
	if(x == '1') return y;
	if(y == '1') return x;
	if(x == 'i'){
		if(y == 'i'){
			z *= -1;
			return '1';
		}
		if(y == 'j') return 'k';
		if(y == 'k'){
			z *= -1;
			return 'j';
		}
	}
	if(x == 'j'){
		if(y == 'i'){
			z *= -1;
			return 'k';
		}
		if(y == 'j'){
			z *= -1;
			return '1';
		}
		if(y == 'k') return 'i';
	}
	if(x == 'k'){
		if(y == 'i') return 'j';
		if(y == 'j'){
			z *= -1;
			return 'i';
		}
		if(y == 'k'){
			z *= -1;
			return '1';
		}
	}
	return '1';
}

void solve(){
	ll l, x;
	bool ok = true;
	int yes = 0;
	int z = 1;
	scanf("%lld%lld",&l,&x);
	if(x > 10){
		x -= 10;
		x = x%4;
		x += 10;
	}
	string str, s;
	cin >> str;
	rep(i,x) s += str;
	char c = '1';
	rep(i,s.size()){
		c = calc(c,s[i],z);
		if(c == a[yes] && z == 1){
			if(yes == 2) continue;
			yes++;
			c = '1';
		}
	}
	if(yes == 2 && z == 1&& c == 'k') puts("YES");
	else puts("NO");
}

int main(){
	int t;
	scanf("%d",&t);
	rep(i,t){
		printf("Case #%d: ",i+1);
		solve();
	}
}