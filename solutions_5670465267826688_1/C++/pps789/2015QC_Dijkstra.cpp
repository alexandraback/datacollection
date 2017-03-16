#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int E = 0, I = 1, J = 2, K = 3;
const int ME = 4, MI = 5, MJ = 6, MK = 7;

const int qmut[8][8] = {
	{ E, I, J, K, ME, MI, MJ, MK },
	{ I, ME, K, MJ, MI, E, MK, J },
	{ J, MK, ME, I, MJ, K, E, MI },
	{ K, J, MI, ME, MK, MJ, I, E },

	{ ME, MI, MJ, MK, E, I, J, K },
	{ MI, E, MK, J, I, ME, K, MJ },
	{ MJ, K, E, MI, J, MK, ME, I },
	{ MK, MJ, I, E, K, J, MI, ME }
};

int main(){
	freopen("large.in", "r", stdin);
	freopen("large.txt", "w", stdout);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		long long L, X; string str;
		cin >> L >> X >> str;

		string str8 = "";
		for (int i = 0; i < 8; i++) str8 += str;

		int getI = -1, getJ = -1;
		int now = E;
		for (int i = 0; i < str8.size(); i++){
			now = qmut[now][str8[i] - 'i' + 1];
			if (getI == -1){
				if (now == I){
					getI = i;
					now = E;
				}
			}
			else if (getJ == -1){
				if (now == J)
					getJ = i;
			}
			else break;
		}

		if (getI == -1 || getJ == -1){
			cout << "NO" << endl;
			continue;
		}

		if (getJ >= L*X - 1){
			cout << "NO" << endl;
			continue;
		}

		now = E;
		if (getJ%L != L - 1){
			for (int i = (getJ + 1) % L; i < str.size(); i++)
				now = qmut[now][str[i] - 'i' + 1];
		}

		int cyc = E;
		for (int i = 0; i < str.size(); i++)
			cyc = qmut[cyc][str[i] - 'i' + 1];

		int used_cycle = (getJ + L) / L;

		int left_cycle = (X - used_cycle) % 4;


		for (int i = 0; i < left_cycle; i++)
			now = qmut[now][cyc];

		if (now == K)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}