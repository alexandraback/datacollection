#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair< long long, pair<string, string> > ANSTYPE;

int cases;
string A, B;
int N;

string minPre(string x, string y){
	int cnt = 0;
	for(int i = 0; i < x.length(); ++i)
		if(x[i] == y[i] || x[i] == '?' || y[i] == '?') ++cnt;
	if(cnt == x.length()){
		string ret = "";
		for(int i = 0; i < x.length(); ++i){
			ret += min(x[i], y[i]);
			if(ret[i] == '?') ret[i] = '0';
		}
		return ret;
	}

	return "x";
}

string fx(string x, string y){
	string ret = x;
	for(int i = 0; i < x.length(); ++i)
		if(x[i] == '?') ret[i] = y[0];
	return ret;
}

string gao(){
	cin >> A >> B;
	N = A.length();
	
	string C = minPre(A, B);
	if(C != "x")
		return C + " " + C;

	ANSTYPE res = make_pair(1000000000000000000, make_pair("", ""));

	for(int i = 0; i < N; ++i){
		C = minPre(A.substr(0, i), B.substr(0, i));
		if(C != "x")
			for(char ii = '0'; ii <= '9'; ++ii)
				if(ii == A[i] || A[i] == '?')
					for(char jj = '0'; jj <= '9'; ++jj)
						if ((jj == B[i] || B[i] == '?') && ii != jj){
							string a = "0", b = "9";
							if(ii < jj){
								a = "9";
								b = "0";
							}
							string newA = C + ii + fx(A.substr(i + 1, N), a);
							string newB = C + jj + fx(B.substr(i + 1, N), b);
							res = min(res, make_pair(llabs(stoll(newA) - stoll(newB)), make_pair(newA, newB)));
						}
	}

	return res.second.first + " " + res.second.second;
	
}

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx)
		cout << "Case #" << xx << ": " << gao() << endl;
}
