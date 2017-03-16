#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define ll long long
#define DICTL 521196

using namespace std;

int n, zt, best[4025];
char word[530000][15], str[4025];
char wlen[530000];

FILE *dict = fopen("dict.txt", "r");

int match(int windex, int sindex) {
    int l = wlen[windex], c=0, last = -999;
    for (int i=0; i<l; ++i) {
	if (str[sindex+i] != word[windex][i]) {
	    if (last > i-5) return 100000000;
	    last = i;
	    ++c;
	}
    }
    return c;
}
int main() {
    for (int i=0; i<DICTL; ++i) {
	fscanf(dict, "%s", word[i]);
	wlen[i] = strlen(word[i]);
    }
    
    scanf("%d", &zt);
    for (int kt=0; kt<zt; ++kt) {
	scanf("%s", str);
	int n = strlen(str);
	
	memset(best, 63, sizeof(best));
	
	for (int i=0; i<n; ++i) {
	    for (int j=0; j<DICTL; ++j) {
		int l = wlen[j];
		if (l <= i+1 && best[i] > best[i-l]) {
		    best[i] = min(best[i], best[i-l] + match(j, i-l+1));
		}
	    }
	}
	printf("Case #%d: %d\n", kt+1, best[n-1]);
    }
}