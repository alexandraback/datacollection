#include <bits/stdc++.h>

using namespace std;

#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli				pair<ll, int>
#define pb				push_back
#define mp				make_pair
#define MOD				1000000007
#define F				first
#define S				second

ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a);
		a = (a * a);
		b >>= 1;
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;

	for(int t = 1;t<=T;t++){

		unsigned ll b, m, lim = 1;

		cin >> b >> m;
		lim <<= b-2;

		cout << "Case #" << t << ": ";
		if(m > lim){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		else if (m == lim){

			cout << "POSSIBLE\n";
			for(int i=0;i<b;i++){
				for(int j=0;j<b;j++){

					if(j>i)
						cout << "1";
					else
						cout << "0";
					
				}
				cout << "\n";
			}

		}
		else{

			int diff = lim - m;
			cout << "POSSIBLE\n";
			int cmp = (lim >> 1);

			int cut[b];
			cut[0] = 0;
			for(int i=1;i<b;i++){
				cut[i] = 1;
			}

			int set = 1;
			while(set < b){
				// cout << cmp << " " << diff << "\n";
				// cout << (cmp & diff) << ":\n";
				if(cmp&diff){
					cut[set] = 0;
				}
				set++;
				cmp >>= 1;
			}
			for(int i=0;i<b;i++){
				for(int j=0;j<b;j++){
					if(i == 0){
						cout << cut[j];
					}
					else{
						if(j>i)
							cout << "1";
						else
							cout << "0";
					}
				}
				cout << "\n";
			}
		}

	}

	return 0;
}
