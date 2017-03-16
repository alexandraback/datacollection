#include <iostream>
#include <cstring>

using namespace std;

#define endl '\n'
#define ll long long int

bool slides[100][100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; Case++){
		memset(slides, false, sizeof(slides));
		cout << "Case #" << Case << ": ";
		ll B, M;
		cin >> B >> M;
		ll maximum = 1 << (B-2);		
		if (M > maximum) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		else cout << "POSSIBLE\n";
		ll cnt = 0;
		for (int i = 2; i < B; i++){
			slides[i][B] = true;
		}
		for (int j = 2; j <= B && cnt < M; j++, cnt++){
			slides[1][j] = true;
		}
		for (int i = 2; i < B-1 && cnt < M; i++){
			for (int j = i+1; j < B && cnt < M; j++, cnt += 1 << (i-2)){
				slides[i][j] = true;
			}
		}
		if (cnt > M){
			ll dif = cnt-M;
			for (int i = 0; dif; i++){
				if (dif & 1){
					slides[i+2][B-1] = false;
				}
				dif >>= 1;
			}
		}
		for (int i = 1; i <= B; i++){
			for (int j = 1; j <= B; j++){
				if (slides[i][j]) cout << 1;
				else cout << 0;
			}
			cout << endl;
		}




	}

}