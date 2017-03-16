#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int M = 1e5 + 10;
const ll Q = 1e18 + 15.;
struct num{
	int z;
	char s;
	num(){
		z = 1;
		s = '1';
	}
	num(int z1, char s1){
		z = z1;
		s = s1;
	}
};
num a[M];
num table[4][4] = {{num(1, '1'), num(1, 'i'), num(1, 'j'), num(1, 'k')},
				   {num(1, 'i'), num(-1, '1'), num(1, 'k'), num(-1, 'j')},
				   {num(1, 'j'), num(-1, 'k'), num(-1, '1'), num(1, 'i')},
				   {num(1, 'k'), num(1, 'j'), num(-1, 'i'), num(-1, '1')}};

map<char, int> ma;

inline num operator * (const num &a, const num &b){
	num res = table[ma[a.s]][ma[b.s]];
	res.z *= a.z;
	res.z *= b.z;
	return res;
}

					



char s[200000];
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ma['1'] = 0;
	ma['i'] = 1;
	ma['j'] = 2;
	ma['k'] = 3;
	
	int t;
	scanf("%d", &t);
	for (int tq = 1; tq <= t; tq++){
		int l;
		ll x;
		cin >> l >> x;
		scanf("%s", s);
		for (int i = 0; i < l; i++){
			a[i].z = 1;
			a[i].s = s[i];
		}
		num res;
		for (int i = 0; i < l; i++)
			res = res * a[i];
		num res1;
		for (int i = 0; i < x % 4; i++)
			res1 = res1 * res;
		string ans;
		if (!(res1.z == -1 && res1.s == '1'))
			ans = "NO\n";
		else{
			num tmp;
			ll d1 = Q, d2 = Q;
			for (int i = 0; i <= l; i++){
				if (i)
					tmp = tmp * a[i - 1];
				num qq = tmp;
				for (int j = 0; j < 4; j++){
					if (qq.z == 1 && qq.s == 'i'){
						d1 = min(d1, 1LL * j * l + i);
						break;
					}
					qq = res * qq;
				}
			}

			num tmp1;
			for (int i = l; i >= 0; i--){
				if (i != l)
					tmp1 = a[i] * tmp1;
				num qq = tmp1;
				for (int j = 0; j < 4; j++){
					if (qq.z == 1 && qq.s == 'k'){
						d2 = min(d2, 1LL * j * l + l - i);
						break;
					}
					qq = qq * res;
				}
			}
			ll gg = d1 / l + d2 / l;
			if (d1 % l || d2 % l)
				gg++;
			if (d1 % l + d2 % l > l)
				gg++;
		//	cerr << d1 << " " << d2 << endl;
			if (gg > x)
				ans = "NO\n";
			else
				ans = "YES\n";	
		}
		cout << "Case #" << tq << ": " << ans;
		cerr << "test " << tq << " done" << endl;
	}
	return 0;       
}                                              	