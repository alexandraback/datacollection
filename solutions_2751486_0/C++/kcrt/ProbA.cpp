
/*
 * 	FILENAME - FILEDESCRIPTION
 *		Programmed by kcrt <kcrt@kcrt.net>
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;
constexpr int maxchars = 256;

int GetNValue(const char *s, long long n){

	const char *lastnull = s + strlen(s);
	int value = 0;
	char xstr[maxchars] = {'\0'};

	memset(xstr, 'x', n);

	if(0){
		for(const char *start = s; start < lastnull; start++){
			for(const char *end=start+n-1; end < lastnull; end++){
				if(strnstr(start, xstr, end-start+1)){
					value++;
				}
			}
		}
	}else{
		const char *findstart;
		for(const char *start = s; start < lastnull; start++){
			const char *firstxs = strstr(start, xstr);
			if(!firstxs){

			}else{
				value += (lastnull - (firstxs + n - 1));
			}
		}
	}

	return value;

}

int main(){

	int testcase;
	char s[maxchars];
	long long n;
	long long value;

	scanf("%d", &testcase);

	for(int i = 0; i < testcase; i++){
		// read
		scanf("%s %lld\n", s, &n);

		// vowel -> a
		// consonants -> x
		for(char *p = s; *p != '\0'; p++){
			switch(*p){
				case 'a': case 'i': case 'u': case 'e': case 'o':
					*p = 'a';
					break;
				default:
					*p = 'x';
					break;
			}
		}

		value = GetNValue(s, n);
		
		printf("Case #%d: %lld\n", i+1, value);
	}

}
