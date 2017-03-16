#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define ll long long

using namespace std;

int d, zt;
char s[1000005], v[1000005];

bool isVowel(char a) {
    return a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u';
}

int main() {
    scanf("%d", &zt);
    
    for (int kt=0; kt<zt; ++kt) {
	scanf("%s%d", s, &d);
	
	int l = strlen(s);
	
	for (int i=0; i<l; ++i) {
	    v[i] = 0;
	    for (int j=0; j<d; ++j) {
		if (i+j < l && !isVowel(s[i+j])) {
		    v[i]++;
		}
		else break;
	    }
	    v[i] = (v[i] == d);
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