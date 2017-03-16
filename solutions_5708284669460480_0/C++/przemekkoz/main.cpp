//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
typedef long long LL;
typedef long double LD;
const int INF = 1000000009;
const int MAXS = 103;

inline int R(int a, int b) {return a+rand()%(b-a+1);}

void obliczP(int n, const char *S, int *P)
{
    int b = 0;
    P[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        while(b > 0 && S[b+1] != S[i]) b = P[b];
        if(S[b+1] == S[i]) b++;
        P[i] = b;
    }
}
int obl_nprefiks(int n, const char *S, const int *P, int prefiks, char litera)
{
    int b = prefiks;
    if(b == n) b = P[b];
    while(b > 0 && S[b+1] != litera) b = P[b];
    if(S[b+1] == litera) b++;
    return b;
}

LD tab[MAXS][MAXS][MAXS];

int main()
{
    int t;
    scanf("%d", &t);
    for(int ti = 1;ti <= t;ti++)
    {
        int K,L,S;
        vector<char> keyboard;
        vector<int> litcnt(256);
        vector<char> target;
        vector<int> targetP;
        scanf("%d%d%d", &K, &L, &S);
        keyboard.resize(K+1);
        target.resize(L+1);
        targetP.resize(L+1);
        for(int i = 1;i <= K;i++) scanf(" %c", &keyboard[i]);
        for(int i = 1;i <= L;i++) scanf(" %c", &target[i]);
        for(int i = 1;i <= K;i++) litcnt[keyboard[i]]++;
        
        obliczP(L, &target[0], &targetP[0]);
    
        int banany = 1+(S-L)/(L-targetP[L]);
        for(int i = 1;i <= L;i++)
        {
            bool jest = false;
            for(int j = 1;j <= K;j++)
                if(keyboard[j] == target[i])
                {
                    jest = true;
                    break;
                }
            if(!jest)
            {
                banany = 0;
                break;
            }
        }
        //cerr << "Banany: " << banany << endl;
        
        for(int i = 0;i <= S;i++)
            for(int j = 0;j <= S;j++)
                for(int l = 0;l <= S;l++)
                    tab[i][j][l] = 0;

        tab[0][0][0] = 1;
        
        for(int pozycja = 0;pozycja < S;pozycja++)
            for(int wystopilo = 0;wystopilo <= banany;wystopilo++)
                for(int prefiks = 0;prefiks <= L;prefiks++)
                    for(char litera = 'A';litera <= 'Z';litera++)
                        if(litcnt[litera])
                        {
                            int npozycja = pozycja+1;
                            int nprefiks = obl_nprefiks(L, &target[0], &targetP[0], prefiks, litera);
                            int nwystopilo = wystopilo+(nprefiks == L);
                            tab[npozycja][nwystopilo][nprefiks] += tab[pozycja][wystopilo][prefiks]*litcnt[litera]/K;
                        }
        
        LD wyn = 0;
        for(int wystopilo = 1;wystopilo <= banany;wystopilo++)
            for(int prefiks = 0;prefiks <= L;prefiks++)
            {
                //cerr << " Wyst: " << wystopilo << " Pref: " << prefiks << " tab[S][wyst][pref]: " << fixed << tab[S][wystopilo][prefiks] << endl;
                wyn += tab[S][wystopilo][prefiks]*wystopilo;
            }
        
        wyn = banany-wyn;
        
        printf("Case #%d: %.8Lf\n", ti, wyn);
    }
    return 0;
}
