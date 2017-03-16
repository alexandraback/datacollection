#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

struct trip {
	int x,y,z;
};

int J,P,S,K;
int T;

int gcd(int m,int n) {return n==0?m:gcd(n,m%n);}

int main() {
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		cin >> J >> P >> S >> K;
		int g=gcd(J,P);
		int lcm=J/g*P;
		int i,j,k;
		i=j=k=0;
		int lcmc=0,pairc=0,zc=0;
		int Mpairc=K*J*P;
		vector<trip> r;
		while (1) {
			r.push_back({i,j,k});
			i=(i+1)%J;
			j=(j+1)%P;
			//k=(k+1)%S;
			lcmc++;pairc++;zc++;
			if (pairc==Mpairc) break;
			if (zc==min(J*K,J*P)) {
				k++;
				zc=0;
				if (k==S) break;
			}
			if (lcmc==lcm) {
				lcmc=0;
				j=(j+1)%P;
			}
		}

		printf("Case #%d: %d\n",cas,(int)r.size());
		for (int c=0;c<r.size();c++) printf("%d %d %d\n",r[c].x+1,r[c].y+1,r[c].z+1);
	}
}
