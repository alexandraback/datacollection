#include <bits/stdc++.h>
using namespace std;

#define rREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define rFOR(i,a,b) for(int i = (a); i >= (b); i--)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define itr iterator

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

bool possible[35]; 
bool tem[36];

int nb(int n){
	printf("contando %d\n", n);
	int ret = 0;
	while(n > 0){
		n -= n & -n;
		ret++;
	}
	return ret;
}

int main(){
	int c, d, v;
	int t;
	cin >> t;
	REP(caso, t){
		cin >> c >> d >> v;
		REP(i, 31)
			possible[i] = tem[i] = false;
		possible[0] = true;
		int submask = 0;
		REP(i, d){
			int nv;
			cin >> nv;
			if(nv == 0)
				continue;
			if(nv > 22){
				tem[nv] = true;
			}
			else{
				submask |= (1<<nv-1);
			}}
			/*if(nv == 0)
				continue;
			tem[nv] = true;
			for(int k = 30-nv; k >= 0; k--){
				if(possible[k])
					possible[k+nv] = true;
			}
			if(nv >= 3)
				submask |= (1<<(nv-3));
		}
		if(v >= 1 && !tem[1]){
			tem[1] = true;
			d++;

		}
		else if (v == 1){
			if(tem[1]){
				cout << "Case #" << caso+1 << ": " << 0 << endl;
			}
			else cout << "Case #" << caso+1 << ": " << 1 << endl;
		}
		if(v >= 2 && !tem[2]){
			tem[2] = true;
			d++;
		}*/
		int ans = 0;
		int mask = 0;
		ans = 3111;
		REP(mask, (1<<22)){
			if((mask & submask) == submask){
				REP(i, 31)
					possible[i] = false;
				possible[0] = true;
				for(int i = 22+1; i <= 30; i++){
					if(tem[i]){
						for(int k = v-i; k>= 0; k--){
							if(possible[k])
								possible[k+i] = true;
						}
					}
				}
				REP(bit, 22){
					if(mask & (1<<bit)){
						for(int k = v-(bit+1); k >= 0; k--){
							if(possible[k])
								possible[k+(bit+1)] = true;
						}
					}
				}
				bool ok = true;
				REP(i, v+1)
					if(!possible[i]){
						ok = false;
						//printf("mask = %d, cara %d impossivel\n", mask, i);
						break;
					}
				int dif = 0;
				REP(i, 22){
					if((mask & (1<<i)) && !(submask &  (1<<i)))
						dif++;
				}
				if(ok){
					ans = min(ans, dif);
				}
			}
		}
		cout << "Case #" << caso+1 << ": " << ans << endl;
	}
	return 0;
}