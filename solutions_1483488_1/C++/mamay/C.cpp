#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

int getDigits(int n){
	char s[80];
	sprintf(s, "%d", n);
	int res = strlen(s);
	return res;
}

int recycledOfNBelowB(int n, int B, int d){
	int P = 1;
	for(int i = 0;i < d-1;++i) P *= 10;
	int k = 10;
	int nByK = n/k;
	set<int> s;
	while(nByK != 0){
		int x = (n%k) * P + nByK;
		if(x > n && x <= B) s.insert(x);
		nByK /= 10;
		P /= 10;
		k *= 10;
	}

	return s.size();
}

int main(){
	int t;
	cin >> t;
	for(int i = 0;i < t;++i){
		cerr << "at case " << i+1 << endl;
		cerr.flush();
		int A, B, res = 0;
		cin >> A >> B;
		int d = getDigits(A);
		for(int h = A;h < B;++h)
			res += recycledOfNBelowB(h, B, d);
		cout << "Case #" << (i+1) << ": " << res << endl;
	}
	return 0;
}

