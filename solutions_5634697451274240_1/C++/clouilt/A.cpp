#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T;

int main(){
	char str[233];
	cin>>T;
	for(int cs=1; cs<=T; ++cs){
		cin>>str;

		int len = strlen(str);
		int need = 0;
		int res = 0;

		for(int i=0; i<len; ++i){
			if( str[len-i-1] == (need?'+':'-')){
				need = !need;
				++res;
			}
		}

		printf("Case #%d: %d\n", cs, res);
	}
	return 0;
}
