
/*
 * 	FILENAME - FILEDESCRIPTION
 *		Programmed by kcrt <kcrt@kcrt.net>
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

const char WAY[] = "NSWE";

int Check(string s, long long tx, long long ty){

	int depth = 1;
	long long x = 0;
	long long y = 0;
	for(auto c = s.begin(); c != s.end(); c++){
		if(*c == 'N') y += depth;
		if(*c == 'S') y -= depth;
		if(*c == 'W') x -= depth;
		if(*c == 'E') x += depth;
		depth++;
	}
	printf("%s\n", (x==tx && y==ty) ? "ok!": "boo");
	return 1;

}

int main(){

	int testcase;
	string bestway;
	scanf("%d", &testcase);

	for(int i = 0; i < testcase; i++){
		// read
		long long tx;
		long long ty;
		scanf("%lld %lld\n", &tx, &ty);

		string ans = "";
		if(tx == 0){
			// do nothing;
		}else if (tx > 0){
			for(long long i = 0; i < tx; i++){
				ans += "WE";
			}
		}else{
			for(long long i = 0; i < -tx; i++){
				ans += "EW";
			}
		}

		if(ty == 0){
			// do nothing;
		}else if (ty > 0){
			for(long long i = 0; i < ty; i++){
				ans += "SN";
			}
		}else{
			for(long long i = 0; i < -ty; i++){
				ans += "NS";
			}
		}

		// Check(ans, tx, ty);

		printf("Case #%d: %s\n", i+1, ans.c_str());
	}

}
