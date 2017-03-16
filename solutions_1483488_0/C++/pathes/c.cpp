#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2000009;

int T, A, B;

bool isUsed[MAXN];

int digits(int x) {
	int tmp = x;
	int res = 1;
	while (tmp >= 10) {
		tmp /= 10;
		res++;
	}
	return res;
}

inline int transpose(int x, int d) {
	//Check what's the d-th digit from right
	int check = x;
	int p = d;
	int r = 1;
	while (p > 1) {
		check /= 10;
		p--;
		r *= 10;
	}
	return ((x-check*r)*10+check);
}

int main(){
	cin >> T;
	for (int t=0; t<T; ++t) {
		int res = 0;
		cin >> A;
		cin >> B;
		for (int i=A; i<=B; ++i)
			isUsed[i] = false;
		for (int i=A; i<=B; ++i)
			if (!isUsed[i]) { //Generate all possible recycle numbers
				isUsed[i] = true;
				int d = digits(i); //num of digits
				int q = 1; //how many recycled encountered;
				int actual = transpose(i, d); //let's begin
				while (actual != i) {
					if (actual >= A && actual <= B) {
						q++;
						isUsed[actual] = true;
					}
					actual = transpose(actual, d);
				}
				res += q*(q-1)/2; //that's how many pairs there are
			}
		cout << "Case #" << (t+1) << ": " << res << endl;
	}
}
