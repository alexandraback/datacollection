#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int k, l, s;
char word[200];
bool seen[200][200];
double cache[200][200];
double p[256];

bool matches(char* line) {
    int i;
    int len = strlen(line);
    for (i = 0; i < len; i++)
        if (line[i] != word[i])
            return false;
    return true;
}

int maxPrefix(int prefix, int letter) {
    char line[200];
    int i;
    for (i = 0; i < prefix; i++)
        line[i] = word[i];
    line[prefix] = letter;
    line[prefix+1] = 0;
    for (i = 0; i < prefix+1; i++)
        if (matches(line+i) && prefix+1-i <= l)
            return prefix+1-i;
    return 0;
}

double expected(int prefix, int remaining) {
    if (remaining <= 0)
        return 0.0;
    if (seen[prefix][remaining])
        return cache[prefix][remaining];
    int i;
    double ans = 0.0;
    for (i = 'A'; i <= 'Z'; i++) {
        if (p[i] == 0)
            continue;
        int maxPref = maxPrefix(prefix, i);
        if (maxPref == l)
            ans += p[i];
        ans += p[i] * expected(maxPref, remaining - 1);
        
    }
    seen[prefix][remaining] = true;
    cache[prefix][remaining] = ans;
    //fprintf(stderr, "%d %d = %f\n", prefix, remaining, ans);
    return ans;
}

int maxBananas() {
    if (s < l)
        return 0;
    int i;
    int overlap = 0;
    for (i = 0; i < l; i++)
        if (p[word[i]] == 0)
            return 0;
    for (i = 1; i < l; i++) {
        if (matches(word+i)) {
            overlap = l-i;
            break;
        }
    }
    return 1 + (s - l) / (l - overlap);
}

int main() {
    int TT, T;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        scanf("%d%d%d", &k, &l, &s);
        char alphabet[200];
        scanf("%s", alphabet);
        scanf("%s", word);
        
        int i, j;
        
        //initialise everything
        for (i = 'A'; i <= 'z'; i++)
            p[i] = 0;
        for (i = 0; i <= l; i++)
            for (j = 0; j <= s; j++)
                seen[i][j] = 0;
        for (i = 0; i < k; i++)
            p[alphabet[i]] += 1.0/k;
        
        printf("%.10lf\n", maxBananas() - expected(0, s));
    }
}
        