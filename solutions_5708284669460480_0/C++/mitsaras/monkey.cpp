#include <map>
#include <cstdlib>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <cmath>
using namespace std;

int K, L, S; 
char k[10], l[10], s[10];
int alpha[26] = {0};

int common(char a[], char b[], int i) {
    int j = 0;
    
    while (a[j++] == b[i++]) {
        if (!a[j] || !b[i]) return j;
    }
    return j - 1;
}

bool next (char a[], int n) {
    int i = n-1;
    while (true) {
        do {a[i]++;} while (a[i] <= 'Z' && alpha[a[i] - 'A'] == 0);
        if (a[i] > 'Z') {
            a[i] = 'A';
            if (i == 0)
                return false;
            else
                i--;
        } else {
            return true;
        }
    }
}

double prob (char a[], int n) {
    double pr = 1.;
    for (int i = 0; i < n; i++)
        pr *= ((double) alpha[a[i] - 'A']) / K;
    return pr;
}

int main () {

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
        scanf("%d %d %d", &K, &L, &S);
        scanf(" %s %s", k, l);

        for (int j = 'A'; j <= 'Z'; j++)
            alpha[j - 'A'] = 0;
        for (int j = 0; j < K; j++)
            alpha[k[j] - 'A']++;

        if (prob(l, L) == 0.0) {
            printf("Case #%d: 0.0\n", i);
            continue;
        }

        double expct = 0.;
        for (int j = 0; j < S; j++)
            s[j] = 'A';

        int mm = 0;
        do {
            int match = 0;
            for (int j = 0; j < S; j++)
                if (common(l, s, j) == L)
                    match++;
            mm = max(mm, match);
            expct += match * prob(s, S);
            //printf("string %s, matches %d, pr = %f\n", s, match, prob(s,S));
        } while (next(s,S));
        
		printf("Case #%d: %.7f\n", i, mm - expct);
    }

	return 0;
}
