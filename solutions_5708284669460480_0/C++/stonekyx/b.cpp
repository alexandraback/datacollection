#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void preKmp(const char *x, int m, int kmpNext[]) {
    int i, j;

    i = 0;
    j = kmpNext[0] = -1;
    while (i < m) {
        while (j > -1 && x[i] != x[j])
            j = kmpNext[j];
        i++;
        j++;
        if (x[i] == x[j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
}

int KMP(const char *x, int m, int n) {
    int i, j, *kmpNext;
    kmpNext = new int[m+10];

    /* Preprocessing */
    preKmp(x, m, kmpNext);

    /* Searching */
    int cnt = 0;
    i = j = 0;
    while (j < n) {
        i++;
        j++;
        if (i >= m) {
            cnt++;
            i = kmpNext[i];
        }
    }
    delete[] kmpNext;
    return cnt;
}

int maxMatch(string &word, int S)
{
    return KMP(word.c_str(), word.length(), S);
}

long double calc(string &word, string &kb, int S, int L)
{
    int kbcnt[26];
    memset(kbcnt, 0, sizeof(kbcnt));
    for(size_t i=0; i<kb.length(); i++) {
        kbcnt[kb[i]-'A']++;
    }

    long double single=1;
    for(size_t i=0; i<word.length(); i++) {
        single *= (long double)kbcnt[word[i]-'A'] / kb.length();
    }
    single *= S-L+1;
    return single;
}

int main()
{
    int T, Tcnt=1;
    cin>>T;
    for(; T; T--,Tcnt++) {
        cout<<"Case #"<<Tcnt<<": ";
        int K, L, S;
        string kb;
        string word;
        cin>>K>>L>>S;
        cin>>kb;
        cin>>word;
        int carry = maxMatch(word, S);
        for(size_t i=0; i<word.length(); i++) {
            if(kb.find(word[i]) == string::npos) {
                carry = 0;
                break;
            }
        }
        if(carry==0) {
            printf("%.6lf\n", 0.0);
            continue;
        }
        printf("%.6lf\n", (double)(carry-calc(word, kb, S, L)));
    }
    return 0;
}

