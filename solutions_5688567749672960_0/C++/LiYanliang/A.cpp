#include <iostream>
#include <queue>

using namespace std;

int q[1000005];

int fan(int a){
	int ans = 0;
	while (a > 0){
		ans *= 10;
		ans += a % 10;
		a /= 10;
	}
	return ans;
}

int main(){
	queue<int> qwe;
	qwe.push(1);
	int wid, t, ci = 2, tem;
	q[1] = 1;
	while (!qwe.empty()){
		wid = qwe.size();
		while (wid--){
			t = qwe.front();
			qwe.pop();
			if (t >= 1000000) continue;
			if (!q[t + 1]){
				qwe.push(t + 1);
				q[t + 1] = ci;
			}
			if (!q[tem = fan(t)]){
				qwe.push(tem);
				q[tem] = ci;
			}
		}
		ci++;
	}
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++){
		int a;
		cin >> a;
		cout << "Case #" << k << ": " << q[a] << endl;
	}
	
	return 0;
}
