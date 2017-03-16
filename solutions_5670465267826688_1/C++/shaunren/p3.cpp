#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdint.h>
using namespace std;

char ch[10002], mt[200][200], inv[200], v[10002], bv[5], vs[] = "eEiIjJkK";

inline char cov(char a)
{
    if (a=='1') return 'e';
    return a;
}

inline char neg(char a)
{
    return isupper(a) ? tolower(a) : toupper(a);
}

inline char mul(char a, char b)
{
    int sgn = (isupper(a) ? -1:1) * (isupper(b) ? -1:1);
    a = tolower(a);
    b = tolower(b);
    return sgn<0 ? neg(mt[a][b]) : mt[a][b];
}


__attribute__((optimize("-O3")))
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);

    for (int i=0;i<strlen(vs);i++)
        mt['e'][vs[i]] = mt[vs[i]]['e'] = vs[i];
    mt['i']['i'] = 'E';
    mt['i']['j'] = 'k';
    mt['i']['k'] = 'J';
    mt['j']['i'] = 'K';
    mt['j']['j'] = 'E';
    mt['j']['k'] = 'i';
    mt['k']['i'] = 'j';
    mt['k']['j'] = 'I';
    mt['k']['k'] = 'E';
    for (int i=0;i<strlen(vs);i++)
        for (int j=0;j<strlen(vs);j++)
            if (!mt[vs[i]][vs[j]]) mt[vs[i]][vs[j]] = mul(vs[i], vs[j]);

    inv['e'] = 'e';
    inv['E'] = 'E';
    inv['i'] = 'I';
    inv['I'] = 'i';
    inv['j'] = 'J';
    inv['J'] = 'j';
    inv['k'] = 'K';
    inv['K'] = 'k';

    int ncases;
    cin >> ncases;
    for (int cas=1;cas<=ncases;cas++) {
        int l;
        uint64_t x;
        cin >> l >> x;
        cin >> ch;
        v[0] = 'e';
        for (int i=1;i<=l;i++) {
            ch[i-1] = cov(ch[i-1]);
            v[i] = mt[v[i-1]][ch[i-1]];
            //cout << v[i];
        }
        //cout << endl;
        
        bv[0] = 'e';
        for (int i=1;i<4;i++)
            bv[i] = mt[bv[i-1]][v[l]];

        bool found = false;

        for (int m=0;m<=l;m++) {
            char p = mt['i'][inv[v[m]]];
            char _lp = tolower(p);
            if (_lp != 'e' && _lp != tolower(v[l])) continue;
            
            for (int b=0;b<4;b++) {
                if (bv[b]!=p) continue;
                char c='e';
                for (int n=m+1;n<=l;n++) { // find j in same block
                    c = mt[c][ch[n-1]];
                    if (c=='j') { // find k
                        char q = mt[inv[v[n]]][v[l]];
                        for (int f=0;f<4;f++) {
                            if (mt[q][bv[f]] == 'k' && x-b-f-1>=0 && (x-b-f-1)%4 == 0) {
                                found = true;
                                goto done;
                            }
                        }
                    }
                }
                for (int d=0;d<4;d++) {
                    char cc = mt[c][bv[d]];
                    for (int n=0;n<=l;n++) { // find j in different block
                        
                        if (mt[cc][v[n]]=='j') { // find k
                            char q = mt[inv[v[n]]][v[l]];
                            for (int f=0;f<4;f++) {
                                if (mt[q][bv[f]] == 'k' && x-b-d-f-2>=0 && (x-b-d-f-2)%4 == 0) {
                                    found = true;
                                    goto done;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        done:
        cout << "Case #" << cas << ": " << (found?"YES":"NO") << '\n';
        
    }
    
    
    return 0;
}














