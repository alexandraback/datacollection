#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tonext(int a, int n){
	int c = 0;
	if(a > n)
		return 0;

	c += tonext(a+a-1,n)+1;
	return c;
}

int ia(int a, int k){
	for(int i = 0; i < k; i++){
		a += a-1;
	}
	return a;
}

int main(){
	ifstream in("mote.in");
	ofstream out("mote.out");
	
	int T;
	in >> T;
	
	for(int i = 0; i < T; i++){
		int a, N;
		in >> a >> N;
		vector<int> n(N);
		for(int j = 0; j < N; j++){
			in >> n[j];
		}
		if(a==1){
			//cout << N << endl;
			out << "Case #" << i+1 << ": " << N << endl;
			continue;
		}
		sort(n.begin(), n.end());
		
		
		long long b = a;
		long long s = 0;
		vector<int> k(N);
		vector<long long> f(N+1);
		
		for(int j = 0; j < N; j++){
			k[j] = tonext(b,n[j]);
			f[j] = s + N-j;
			s += k[j];
			b = ia(b,k[j]);
			b += n[j];
		}
		f[N] = s;
		
		long long m = f[0];
		for(int j = 0; j < N+1; j++){
			if(f[j] < m)
				m = f[j];
		}
		//cout << m << endl;
		out << "Case #" << i+1 << ": " << m << endl;
	}
	
	return 0;
}

