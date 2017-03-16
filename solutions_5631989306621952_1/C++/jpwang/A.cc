#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

#define MAXN 1024

string S;
int m[MAXN];

string best(int N){
	if(N==0)
		return "";
	string pre = best(m[N-1]); 
	for(int i=m[N-1]; i<N; i++){
		if(S[i]==S[m[N-1]])
			pre=string(1,S[i]) + pre;
		else 
			pre+=string(1,S[i]);
	}
	return pre;
}

int main(){
	int T;
	cin >> T;
	for(int k=0; k<T; k++){
		cin >> S;
		m[0]=0;
		for(int i=1; i<S.size(); i++){
			m[i]=m[i-1];
			if(S[i] > S[m[i-1]])
				m[i]=i;
		}

		cout << "Case #" << (k+1) << ": " << best(S.size()) << "\n";
	}
}
