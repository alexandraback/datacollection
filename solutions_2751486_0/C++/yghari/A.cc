#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

#ifdef _DEBUG_
static const bool _debug_ = true;
#else
static const bool _debug_ = false;
#endif

#define derr if (_debug_) cerr

void preprocess() {
}

bool isConsonant(char a) {
    return !(a == 'a' || a=='e' || a=='i' || a=='o' || a=='u');
}

void doTest(int tt) {
    printf("Case #%d: ", tt);
    string NAME;
    int n;
    cin >> NAME >> n;
    //derr << " NAME = " << NAME << " n = " << n << endl;
    int L = NAME.size();
    int ll;
    unsigned beg, clen = 0;
    bool isInSeq = false;
    ULL result = 0ULL;
    unsigned lastbeg=0;

    bool isCons = false;
    for (ll=0; ll<L; ++ll) {
        isCons = isConsonant(NAME[ll]);
        if (!isInSeq && isCons) {
            beg = ll;
            clen = 1;
            isInSeq = true;
            //derr << " found new begin at : " << beg << endl;
        } else if (isInSeq && isCons) {
            ++clen;
        } else if (!isCons) {
            if (isInSeq) {
                if (clen >= n) lastbeg = ll-n+1;
                //derr << " found end at : " << ll << " clen = " << clen << endl;
            }
            isInSeq = false;
            clen = 0;
            continue;
        }
        if (isInSeq && (clen==n)) {
            if (lastbeg < beg) {
                ULL nn = (L-ll);
                ULL kk = (beg-lastbeg);
                result += kk*nn;
                //derr << " result adjust for kk=" << kk << " nn=" << nn << " result = " << result << endl;
            }
        }
        if (clen >= n) {
            //result += (beg-lastbeg);
            //derr << " beg-lastbeg at " << ll << " = " << (beg-lastbeg) << endl;
            result += (L-ll);
            //derr << " L-ll at " << ll << " = " << (L-ll) << endl;
        }
        //derr << " result at " << ll << " and clen " << clen << " and lastbeg = " << lastbeg << " = " << result << endl;
    }

    printf("%llu\n", result);
}

int main() {
    preprocess();
    int T;
    cin >> T;
    for (int tt=1; tt<=T; ++tt) {
        doTest(tt);
    }
    return 0;
}

