#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
typedef long long ll;
#define f0(i,N) for (int i=0; i< N; i++) 
#define f1(i,N) for (int i=1; i<=N; i++) 
int cJP[11][11], cPS[11][11], cJS[11][11];
int J, P, S, K, ans;

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	f1(t, T)
	{
		vector <string> St;
		cout << "Case #" << t << ": ";
		memset(cJP, 0, sizeof(cJP));
		memset(cPS, 0, sizeof(cPS));
		memset(cJS, 0, sizeof(cJS));
		cin >> J >> P >> S >> K; ans = 0;
		f1(i,J) f1(j,P) f1(k, S)
		{
			cJP[i][j]++; cPS[j][k]++; cJS[i][k]++;
			if (cJP[i][j] <= K && cPS[j][k] <= K && cJS[i][k] <= K) {
				ans++; 
				ostringstream convert;
				convert << i << " " << j << " " << k << endl;
				St.push_back(convert.str());
			}
			else { cJP[i][j]--; cPS[j][k]--; cJS[i][k]--; }
		}
		cout << ans << endl;
		for (auto i = St.begin(); i < St.end(); i++)
			cout << *i;
	}
	return 0;
}
