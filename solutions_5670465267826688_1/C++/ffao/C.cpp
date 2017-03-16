#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int multable[][4] = { {0, 1, 2, 3}, 
                     {1, 0, 3, 2},
                     {2, 3, 0, 1},
                     {3, 2, 1, 0} };

int sgn[][4] = { {0, 0, 0, 0},
                {0, 1, 0, 1},
                {0, 1, 1, 0},
                {0, 0, 1, 1} };

int multiply(int a, int b) {
	int vala = a&3;
	int sgna = a>>2;

	int valb = b&3;
	int sgnb = b>>2;

	int valr = multable[vala][valb];
	int sgnr = sgn[vala][valb];

	return valr + ((sgnr ^ sgna ^ sgnb) << 2);
}

int T, teste;
long long L, X;
int cctoi[200];
int totp;
map<int, size_t> occs;
string s;

int bpow(int a, long long e) {
	if (e == 0) return 1;
	if (e == 1) return a;

	int t = bpow(a, e/2);
	t = multiply(t, t);
	if (e % 2) t = multiply(t, a);

	return t;
}

int main() {
	cctoi['i']=1;
	cctoi['j']=2;
	cctoi['k']=3;

	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++teste);

		scanf("%lld %lld", &L, &X);

		cin >> s;
		occs.clear();
		
		int totp = 0;
		for (size_t i = 0; i < s.size(); i++) {
			totp = multiply(totp, cctoi[ s[i] ]);
			if (occs.find(totp) == occs.end()) {
				occs[totp] = i;
			}
		}

		int lngp = bpow(totp, X);
		
		if (X > 30) X = 30;
		long long loc = 0;
		
		int curr = 0;
		for (; loc < X*L; ) {
			curr = multiply(curr, cctoi[s[loc%L]]);
			loc++;
			if (curr == 1) break;
		}

		curr = 0;
		for (; loc < X*L; ) {
			curr = multiply(curr, cctoi[s[loc%L]]);
			loc++;
			if (curr == 2) break;
		}

		printf("%s\n", (loc < X*L && lngp == 4) ? "YES" : "NO");
	}
}