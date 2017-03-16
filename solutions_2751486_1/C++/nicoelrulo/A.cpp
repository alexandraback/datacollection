#include <iostream>
#include <cstdio>
using namespace std;
#define forn(i,n) for(int i=0; i<(int)(n); i++)
typedef long long tint;

bool isVowel(char c){
	if(c=='a')return true;
	if(c=='e')return true;
	if(c=='i')return true;
	if(c=='o')return true;
	if(c=='u')return true;
	return false;
}

int main(){
	int t; cin>>t;
	int caso=0;
	while(t>0){
		t--;
		caso++;
		string s; int n; cin>>s>>n;
		int cons = 0;
		tint res = 0;
		int ult = -1;
		forn(i,s.size()){
			if(isVowel(s[i]))cons=0;
			else cons++;
			
			if(cons>=n){
				res+=((int)(s.size()) - i)*(i-n+1-ult);
				ult=i-n+1;
			}
		}
		printf("Case #%d: %I64d\n", caso, res);
	}
}
