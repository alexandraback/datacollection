#include <iostream>
using namespace std;

#define MAX 1000000
bool D[MAX];

int c, d, v;
void check(int coin){
	for (int i = MAX-1; i >= 0; i--){
		if (D[i]){
			for (int j = 1; j <= c; j++)
				D[i + coin * j] = true;
		}
	}
}
void logic(){
	for (int i = 0; i < MAX; i++)
		D[i] = false;
	D[0] = true;
	cin >> c >> d >> v;

	int arr[110] = { 0 };

	for (int i = 0; i < d; i++){
		cin >> arr[i];
		check(arr[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++){
		if (D[i]) continue;
		check(i);
		cnt++;
	}
	cout << cnt << endl;
}
int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++){
		cout << "Case #" << i << ": ";
		logic();
	}
}