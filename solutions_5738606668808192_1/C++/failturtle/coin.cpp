#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) < (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

#define DEBUG

#ifdef DEBUG
#define D(x...) printf(x)
#else
#define D(x...) 
#endif

typedef long long ll;
typedef pair<int,int> ii;

string an[505];
int asdf[505][123];

ll checkPrime (ll a) {
	ll i = 3;
	while (i*i<=a) {
		if (a%i==0) return i;
		i++;
	}
	return -1;
}

int main() {
	int t;
//	scanf("%d\n", &t);
	t = 1;
	srand(1230);
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d:\n", _);
		set <string> ss;
		string s;
		int cnt = 0;
		while (cnt < 500) {
			s.clear();
			s+='1';
			fo(i,0,14) s+=rand()%2+'0';
			s+='1';
			if (ss.find(s) == ss.end()) {
				bool good = 1;
				for (int i = 2; i <= 10; i++) {
					ll ret = 0;
					ll pow = 1;
					fo(j,0,16) {
						if (s[j] == '1') ret += pow;
						pow *= i;			
					}	
					if (checkPrime(ret) == -1) {
						good = 0;
						break;
					} else {
						asdf[cnt][i] = checkPrime(ret);
					}
				}
				if (good) {
					ss.insert(s);
					an[cnt] = s;
					cnt++;
				}
			}
		}
		fo(i,0,cnt) 
		{
			reverse(an[i].begin(), an[i].end());
			cout << an[i] << an[i] << ' ';
			fo(j,2,10) cout << asdf[i][j] << ' ';
			cout << asdf[i][10] << endl;
		}
	}
	
	return 0;
}
