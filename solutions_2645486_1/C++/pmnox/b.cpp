#define ll long long
#include <cstdio>

using namespace std;

ll val[111111];
ll ile[111111];
int st = 0;

ll E, R, N;
ll v[111111];

ll solve() {
   st = 0;
   ll res = 0;
   scanf("%lld%lld%lld", &E, &R, &N); 
   if (R >= E) R = E;
   for (int i = 0; i < N ; i++) scanf("%lld", &v[i]);
   for (int i = 0; i < N ; i++)  {
	if (st == 0) {
		val[st] = v[i];
		ile[st] = E;
		st ++;
		res += E * v[i];	
	} else {
		ll kol = 0;
		res += R * v[i];
		while (st > 0 && val[st-1] < v[i]) {
			ll rem = (E - R) - kol;
			if (rem == 0) break;
			if (ile[st-1] > rem) {
				ile[st-1] -= rem;
				kol += rem;
				res -= rem * val[st-1];
				break;
			}
			else {
				kol += ile[st-1];
				res -= ile[st-1] * val[st-1];
				st--;
			}
		}
		res += kol * v[i];
		ile[st] = kol + R;
		val[st] = v[i];
		st++;	
	}


   }

   return res;
}

int main(int argc, char ** argv) {
	int T; 
	scanf("%d", &T);;
	for (int i = 1; i <= T; i++) { printf("Case #%d: %lld\n", i, solve()); }
	return 0;
}
