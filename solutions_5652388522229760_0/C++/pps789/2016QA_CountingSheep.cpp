#include<iostream>
#include<algorithm>
using namespace std;

bool chk[10];
bool go(int x){
	while (x){
		chk[x % 10] = true;
		x /= 10;
	}
	for (int i = 0; i < 10; i++) if (!chk[i]) return false;
	return true;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++){
		int n; cin >> n;
		cout << "Case #" << tc << ": ";
		if (n == 0) cout << "INSOMNIA" << endl;
		else{
			for (int i = 0; i < 10; i++) chk[i] = false;
			int det = n;
			while (!go(det)) det += n;
			cout << det << endl;
		}
	}
}