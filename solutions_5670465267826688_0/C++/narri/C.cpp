#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

enum QQTYPE {
    ONE = 0,
    II = 1,
    JJ = 2,
    KK = 3
};

struct QQ {
    int sign;
    int type;
    QQ(int a, int b): sign(a), type(b){;}
    QQ(){sign = 1;type = ONE;}
    bool operator==(const QQ &x) const {
        return sign == x.sign && type == x.type;
    }
};

int TYPETABLE[4][4] = 
{
    {ONE, II, JJ, KK},
    {II, ONE, KK, JJ},
    {JJ, KK, ONE, II},
    {KK, JJ, II, ONE}
};

int SIGNTABLE[4][4] = {
    {1, 1, 1, 1},
    {1,-1, 1,-1},
    {1,-1,-1, 1},
    {1, 1,-1,-1},
};

struct QQ qqmul(const QQ &a, const QQ &b) {
    int newsign = a.sign * b.sign * SIGNTABLE[a.type][b.type];
    int newtype = TYPETABLE[a.type][b.type];
    return QQ(newsign, newtype);
}


int main(int argc, char **argv) {
    int CASES;
    cin >> CASES;
    for(int _cn=1;_cn<=CASES;++_cn) {
        long long L,X;
        bool res = false;
        cin >> L >> X;
        string S;
        cin >> S;
        vector<QQ> ss;
        for(int i=0;i<S.size();++i) {
            switch(S[i]) {
                case 'i': ss.push_back(QQ(1, II));break;
                case 'j': ss.push_back(QQ(1, JJ));break;
                case 'k': ss.push_back(QQ(1, KK));break;
            };
        }
        assert(ss.size() == S.size());
        assert(ss.size() == L);
        QQ prod(1, ONE);
        QQ smul(1, ONE);
        for(int i=0;i<L;++i) {
            smul = qqmul(smul, ss[i]);
        }
        int ntimes = X % 4;
        for(int z=0;z<ntimes;++z) {
            prod = qqmul(prod, smul);
        }
        const QQ GOALI(1, II);
        const QQ GOALK(1, KK);
        //now we only need to find first for I and last for K
        int firsti = 0;
        int lastk = 0;
        bool ok = true;
        const QQ neg1(-1, ONE);
        if(!(prod == neg1)) {
            goto jail;
        }
        {
            QQ curr(1, ONE);
            for(int iter=0;iter<min(X,4LL);++iter) {
                for(int z=0;z<L;++z) {
                    curr = qqmul(curr, ss[z]);
                    ++firsti;
                    if(curr == GOALI) {
                        goto gg;
                    }
                }
            }
            ok = false;
gg:;
        }
        {
            QQ curr(1, ONE);
            for(int iter=0;iter<min(X,4LL);++iter) {
                for(int z=L-1;z>=0;--z) {
                    curr = qqmul(ss[z], curr);
                    ++lastk;
                    if(curr == GOALK) {
                        goto gg2;
                    }
                }
            }
            ok = false;
gg2:;
        }
        if(ok) {
            if(firsti + lastk < L*X) {
                res = true;
            }
        }
jail:;
        printf("Case #%d: %s\n", _cn, res?"YES":"NO");
    }
    return 0;
}
