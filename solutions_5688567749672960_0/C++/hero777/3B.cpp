#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

static int quick_pow10(int n)
{
    static long long pow10[17] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000,
	10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000
    };

    return pow10[n]; 
}

long long v[1000001];

void solve (){
	//long long v[N];
	//if (N <= 19) return N;
	forn (i, 20)
		v[i ] =  i;
	for (int i = 20; i < 1000001; i++){
		v[i] = v[i-1]+1;
		ostringstream ss;
		ss << i;
		string str = ss.str();
		int p[str.length()];
		forn(j, str.length()){
			p[j] = str[j] - '0';
		}
		if (p[str.length()-1] == 0){
			continue;
		}
		long long B = 0;
		forn(j, str.length())
			B = B + p[j]*quick_pow10(j);
		printf("%lld\n", B);
		if (B< i-1) v[i] = min(v[B] + 1, v[i]);
	}

		
}

long long solve (long long N){
	if (N<=20) return N;
	long long M =N;
	ostringstream ss;
	ss << M;
	string str = ss.str();
	int p[str.length()];
	forn(i, str.length()){
		p[i] = str[i] - '0';
	}
	if (p[str.length()-1] == 0) return solve(M-1) +1;
	//if (p[0] == 1){
	//	long long K = quick_pow10(str.length()-1) - 1;
	//	return (M-K)+ solve (K);
	//}
	//long long K = quick_pow10(str.length()-1);
	long long B = 0;
	forn(i, str.length())
		B = B + p[i]*quick_pow10(i);
	printf("%lld\n", B);
	if (B< M-1) return solve(B) + 1;
	else return solve(M-1) +1;
	//forn(i, str.length()/2){
	//	K = K + p[i] * quick_pow10(i);
	//	B = B+ p[i] * quick_pow10(str.length()-1-i);
	//}
	//printf("%lld\n", K);
	
	//return (N-B) + solve(K);
}

int main(){
	int T;
	ifstream input;
	ofstream output;
	input.open("a.txt");
	output.open("output.txt");
	input >> T;
	solve();
	forn(i, T){
		printf("break\n");
		long long N;
		input >> N;

		long long ans = v[N];
		output << "Case #"<< i+1 <<": " << ans << endl;	
	}
}
