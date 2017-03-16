#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 10050;          //3  4  5     7     9 10
const int divisors[11] = {0, 0, 0, 2, 3, 2, 0, 2, 0, 2, 3};

int T;
int n, num, got;
int curDiv[11];
int psz;
int notPrime[MAXN], primes[MAXN];
string s;

bool divisible(int p, int d) {
	ll res = 0, P = 1;
	forn(i, s.size()) {
		res = (res + P * (s[i] - '0')) % d;			
		P = (P * p) % d;
	}
	return res == 0;
}

void getNumbers(int pos, int sum) {
	if (pos == n - 1) {
	    if (sum % 6 == 0) {
	    	bool ok = 1;
	    	
	        for (int p = 2; p <= 10; p++) {
	        	ok = 0;
	        	forn(i, psz) {
	        		if (divisible(p, primes[i])) {
	        			ok = 1;
	        			curDiv[p] = primes[i];
	        			break;
	        		}
	        	}
	        		
	        	if (!ok)
	        		break;	        		
	        }

	        if (ok) {
	        	for (int i = 2; i <= 10; i++)
	        		if (divisors[i] != 0 && divisors[i] != curDiv[i])
	        			assert(false);

	        	reverse(all(s));	
	        	cout << s;
	        	reverse(all(s));
	        	
	        	for (int i = 2; i <= 10; i++)
	        		cout << ' ' << curDiv[i];
	        	cout << '\n';
	        	
	        	got++;
	        }
	    }
		
	    if (got == num)
	    	exit(0);
	    	
		return;
	}
	
	s[pos] = '0';
	getNumbers(pos + 1, sum);
	s[pos] = '1';
	getNumbers(pos + 1, (sum + 1) % 6);
}

int main() {
	
	psz = 0;
	for (int i = 2; i < MAXN; i++)
		if (!notPrime[i]) {
			primes[psz++] = i;
			for (int j = i * 2; j < MAXN; j += i)
				notPrime[j] = 1;	
		}
		
	cin >> T;
	cin >> n >> num;
	
	printf("Case #1:\n");

	forn(i, n)
		s += '1';
	
	got = 0;
	getNumbers(1, 2);	
		
	return 0;
}                  