#include <iostream>
#include <algorithm>
#include <cstdlib>
// #include <cassert>

using namespace std;
typedef int quad;

const quad Q1 = 1;
const quad Qi = 2;
const quad Qj = 3;
const quad Qk = 4;

quad front[100001];
quad back[100001];

quad fromChar(char c){
	switch (c){
		case 'i' : return Qi;
		case 'j' : return Qj;
		case 'k' : return Qk;
		default : return 0;
	}
}
string toChar(quad x){
	string sign = x>=0 ? "" : "-";
	switch (abs(x)){
		case Q1 : return sign+"1";
		case Qi : return sign+"i";
		case Qj : return sign+"j";
		case Qk : return sign+"k";
		default : return sign+"0";
	}
}
quad multiply(quad a, quad b){
	static const quad table[5][5] = {
		{0, 0, 0, 0, 0},
		{0, Q1, Qi, Qj, Qk},
		{0, Qi, -Q1, Qk, -Qj},
		{0, Qj, -Qk, -Q1, Qi},
		{0, Qk, Qj, -Qi, -Q1}
		};
	return (table[abs(a)][abs(b)]*(abs(a)*abs(b)/a/b));
}


quad power(quad x, int expo){
	if (x==1) return 1;
	if (x==-1) return (expo%2==0)? 1 : -1;
	switch (((expo%4)+4)%4){
		case 0: return Q1;
		case 1: return x;
		case 2: return -Q1;
		case 3: return -x;
	}
	return 0;
}


string hasAWay(int L, int X, string const& S){
	// seperate between two string s
	// seperate between one string s
	memset(front, 0, sizeof(front));
	memset(back, 0, sizeof(back));
	front[0] = fromChar(S[0]);
	back[L-1] = fromChar(S[L-1]);
	int frontPos[9];
	int backPos[9];
	for (int i=0; i<9; i++){
		frontPos[i] = -1;
		backPos[i] = -1;
	}
	frontPos[front[0]+4] = 0;
	backPos[back[L-1]+4] = L-1;
	frontPos[Q1+4] = -1;
	backPos[Q1+4] = L;
	for (int i=1; i<L; i++){
		front[i] = multiply(front[i-1], fromChar(S[i]));
		if (frontPos[front[i]+4]==-1){
			frontPos[front[i]+4] = i;
		}
		back[L-i-1] = multiply(fromChar(S[L-i-1]), back[L-i]);
		if (backPos[back[L-i-1]+4]==-1){
			backPos[back[L-i-1]+4] = L-i-1;
		}
	}
	// assert(front[L-1]==back[0]);
	quad package = back[0];

	if (power(package, X) != -Q1) {
		return "NO";
	}
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			if (i+j<X){	
				for (int x =-Qk; x<=Qk; x++){
					if (frontPos[x+4]!=-1 && multiply(power(package,i),x) == Qi){
						for (int y=-Qk; y<=Qk; y++){
							if (backPos[y+4]!=-1 && multiply(y, power(package,j)) == Qk){
								if (i+j<X-1 || (frontPos[x+4]<backPos[y+4])){
									// cout<<endl;
									// cout<<toChar(y)<<toChar(power(package,j))<<endl;
									// cout<<S.substr(0,frontPos[x+4]+1)<<i<<endl;
									// cout<<S.substr(backPos[y+4],L-backPos[y+4])<<j<<endl;
									// cout<<toChar(package)<<" "<<L<<" "<<X<<endl;
									return "YES";
								}
							}
						}
					}
				}
			}
		}
	}
	return "NO";
}

int main(){
	int T;
	cin>>T;
	for (size_t i=0; i<T; i++){
		int L, X;
		string S;
		cin>>L>>X;
		cin>>S;
		cout<<"Case #"<<i+1<<": "<<hasAWay(L,X,S)<<endl;
		// hasAWay(L,X,S);
	}
}