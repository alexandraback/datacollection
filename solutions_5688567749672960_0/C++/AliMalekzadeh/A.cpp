#include<iostream>
using namespace std;

const int maxn = 2 * 1000 * 1000;

int tt, n, sar, tah;

int d[maxn], saf[maxn], mark[maxn];

int f(int x){
	int y = 0;
	while(x){
		y = y * 10;
		y += x%10;
		x /= 10;
	}
	return y;
}

int main(){
	ios::sync_with_stdio(0);
	mark[1] = 1;
	d[1] = 1;
	saf[tah++] = 1;
	while(sar < tah){
		int x = saf[sar++];
		if (!mark[x+1]){
			mark[x+1] = 1;
			saf[tah++] = x+1;
			d[x+1] = d[x] + 1;
		}
		int y = f(x);
		if (y<1000000)
		if (!mark[y]){
			mark[y] = 1;
			saf[tah++] = y;
			d[y] = d[x] + 1;
		}
	}
	cin >> tt;
	for (int i=0 ; i<tt ; i++){
		cin >> n;
		cout << "Case #" << i+1 << ": " << d[n] << endl;
	}
}
