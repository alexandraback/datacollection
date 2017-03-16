#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char s[5000];
char o[5000];
int main() {
	int T, ics = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		string z;
		z += s[0];
		for(int i=1; s[i]; ++i) {
			string q = s[i] + z;
			if( q > z )
				z = q;
			else
				z += s[i];
		}
		printf("Case #%d: %s\n", ++ics, z.c_str());
	}
	return 0;
}