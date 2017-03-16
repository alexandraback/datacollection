#include <stdio.h>
#include <string.h>

bool vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int nvalue(char *name, int n, int L) {
    int result = 0, consonants;
    for (int i = 0; i < L; ++i)
    {
        consonants = 0;
        for (int j = i; j < L; ++j)
        {
            if (consonants >= n)
                result++;
            else if(!vowel(name[j]))
                consonants++;
            else
                consonants = 0;
            if (j == L-1 && consonants >= n)
                result++;
        }
    }
    return result;
}

int main() {
    int T, n;
    char name[100];
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        scanf("%s %d", name, &n);
        int L = strlen(name);
        printf("Case #%d: %d\n", t+1, nvalue(name, n, L));
    }
}