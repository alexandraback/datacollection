#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int main(){
	int T, N;
	string S;
	cin >> T;
	for(int caso=1; caso<=T; ++caso){
		cin >> N;
		cin >> S;
		int res = 0, acum = 0;
		for(int i=0; i<(int)S.size(); ++i){
			if(S[i]=='0')continue;
			if(acum<i){
				res += i-acum;
				acum = i;
			}
			acum += S[i]-'0';
		}
		cout << "Case #" << caso << ": " << res << endl;
	}
	
	return 0;
}
