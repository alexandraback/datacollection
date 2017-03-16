
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define forn(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)

using namespace std;

int tc;
bool isok(int a, string s){
	for(int i = s.length()-1; i >= 0; i--){
		if((a%10+'0') !=s[i] && s[i] != '?')
			return false;
		a = (a-(a%10))/10;
	}
	return true;
}

int main(){
	scanf("%d", &tc);
	for(int testc = 1; testc <= tc; testc++){
		printf("Case #%d: ", testc);
		string s1, s2;
		cin >> s1 >> s2;
		if(s1.length()==1){
			if(s1 == s2) cout << "0 0" << endl;
			else
			cout << (s1 == "?" ? s2 + " " + s2 : s1 + " " + s1) << endl;
		}
		if(s1.length() == 2){
			int besta, bestb;
			int min = INF;
			rep(a,100){
				if(!isok(a,s1))
					continue;
				rep(b,100){
					if(!isok(b,s2))
						continue;
					if(min > abs(a-b)){
						min = abs(a-b);
						besta = a;
						bestb = b;
					}
				}
			}			
			printf("%.2d %.2d\n", besta, bestb);
		}
		if(s1.length() == 3){
			int besta, bestb;
			int min = INF;
			rep(a,1000){
				if(!isok(a,s1))
					continue;
				rep(b,1000){
					if(!isok(b,s2))
						continue;
					if(min > abs(a-b)){
						min = abs(a-b);
						besta = a;
						bestb = b;
					}
				}
			}			
			printf("%.3d %.3d\n", besta, bestb);
		}
	}
	return 0;
}
