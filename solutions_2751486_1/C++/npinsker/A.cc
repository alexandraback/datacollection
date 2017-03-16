#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define ll long long

using namespace std;

int d, zt;
char s[1000005], sv[1000005], v[1000005];

bool isVowel(char a) {
    return a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u';
}

int main() {
    scanf("%d", &zt);
    
    for (int kt=0; kt<zt; ++kt) {
	scanf("%s%d", s, &d);
	
	int l = strlen(s);
	sv[0] = 0;
	for (int i=1; i<l; ++i) {
	    sv[i] = sv[i-1] + isVowel(s[i]);
	}
	
	for (int i=0; i<l; ++i) {
	    v[i] = 0;
	    if (i+d-1 < l) {
		v[i] = (sv[i+d-1] == (i ? sv[i-1] : 0));
	    }
	}
	int last = -1;
	long long result = 0;
	for (int i=0; i<l; ++i) {
	    if (v[i]) {
		result += (long long)(i-last) * (l-(i+d)+1);
		last = i;
	    }
	}
	
	printf("Case #%d: %lld\n", kt+1, result);
    }
}