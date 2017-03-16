//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, k, l, s;
char a[105], b[105];
map<char, int> f;
char tmp[105];
ll nr, dr;
double ans;
void ss(int i){
	if (i == s){
		int mx = 0;
		for (int x = 0; x < s; x++){
			int z = x;
			bool f = true;
			int y;
			for (y = 0; y < l&&z<s; y++, z++){
				if (tmp[z] != b[y]){
					f = false;
					break;
				}
			}
			if (f&&y==l){
				nr++;
				mx++;
			}
		}
		ans = max((int)ans, mx);
		dr++;
		return;
	}
	for (int j = 0; j < k; j++){
		tmp[i] = a[j];
		ss(i + 1);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cs = 1;

	cin >> t;
	while (t--){
		cin >> k >> l >> s;
		cin >> a >> b;
		//int l1 = rl(b, l);
		//double ans = (s - l) / l1 + 1;
		ans = 0;
		//cout << ans << "  ";
		f.clear();
		for (int i = 0; a[i];i++)
			f[a[i]]++;
		/*double d = 1;
		int bi = 0;
		for (int i = 0; i < s; i++, bi++){
		if (bi == l){
		bi -= l1;
		if (s - i < l - bi)break;
		}
		d *= (double)f[b[bi]] / k;
		}*/
		nr = 0;
		dr = 0;
		ss(0);
		double d = (double)nr / dr;
		if (d == 0)
			ans = 0;
		else ans -= d;
		
		for (int i = 0; b[i]; i++)
		if (f[b[i]] == 0)
			ans = 0;
		cout << fixed;
		cout << setprecision(7) << "Case #" << cs << ": " << ans << "\n";
		cs++;
	}
}
