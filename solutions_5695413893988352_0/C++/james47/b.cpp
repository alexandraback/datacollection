/*************************************************************************
    > File Name: b.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun May  1 01:05:31 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int T, cas = 0;
string C, J, S;
string ansC, ansJ;
int mind, minC, minJ;
void dfs(string S, int dep){
	if (dep == S.length()){
		int len = S.length() / 2;
		int tempC = 0, tempJ = 0;
		for (int i = len-1, f = 1; i >= 0; --i, f *= 10){
			tempC += (S[i]-'0') * f;
		}
		for (int i = S.length()-1, f = 1; i >= len; i--, f *= 10){
			tempJ += (S[i]-'0') * f;
		}
		if (mind == -1 || abs(tempC - tempJ) < mind){
			mind = abs(tempC - tempJ);
			minC = tempC;
			minJ = tempJ;
			ansC = S.substr(0, len);
			ansJ = S.substr(len, len);
		}
		else if (abs(tempC - tempJ) == mind){
			if (tempC < minC){
				minC = tempC;
				minJ = tempJ;
				ansC = S.substr(0, len);
				ansJ = S.substr(len, len);
			}
			else if (tempC == minC && tempJ < minJ){
				minJ = tempJ;
				ansC = S.substr(0, len);
				ansJ = S.substr(len, len);
			}
		}
		return;
	}
	if (S[dep] == '?'){
		for (int i = 0; i < 10; i++){
			S[dep] = i+'0';
			dfs(S, dep+1);
			S[dep] = '?';
		}
	}
	else dfs(S, dep+1);
}
int main()
{
	cin >> T;
	while(T--){
		mind = -1;
		cin >> C >> J;
		S = C + J;
		dfs(S, 0);
		cout << "Case #" << ++cas << ": " << ansC << ' ' << ansJ << endl;
	}
	return 0;
}
