#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

#define MAX_N 1005

int nComps;
int T, N, f[MAX_N];
int inD[MAX_N];

//Info per component:
int cycLen[MAX_N];
int bestLen[MAX_N];
bool canDoExtra[MAX_N];
int longestChain[MAX_N];

bool isInCycle[MAX_N];
//Info per node:
int len[MAX_N];
int compNum[MAX_N];

bool onStack[MAX_N];
int dep[MAX_N];
int lastPlc[MAX_N];

void resetAll() {
    nComps = 0;
    FO (i,0,MAX_N) {
        cycLen[i] = -1;
        compNum[i] = -1;
        bestLen[i] = -1;
        len[i] = -1;
        inD[i] = 0;
        canDoExtra[i] = false;
        isInCycle[i] = false;
        longestChain[i] = 0;
    }
}

int getInfo (int c, int l) {
    if (compNum[c] != -1) return compNum[c];
    if (onStack[c]) {
        compNum[c] = nComps++;
        cycLen[compNum[c]] = l - dep[c];
        onStack[c] = false;
        dep[c] = -1;
        len[c] = 0;
        return compNum[c];
    }
    onStack[c] = true;
    dep[c] = l;
    compNum[c] = getInfo (f[c], l+1);
    len[c] = len[f[c]]+1;
    bestLen[compNum[c]] = max (bestLen[compNum[c]], len[c]);

    onStack[c] = false;
    dep[c] = -1;
    return compNum[c];
}

int fLastPlc (int c) {
    if (onStack[c]) {
        onStack[c] = false;
        return -1;
    }
    onStack[c] = true;
    int lP = fLastPlc (f[c]);
    onStack[c] = false;
    if (lP == -1) return c;
    else return lP;
}

int cStart;
bool fInCycle (int c) {
    if (onStack[c]) {
        onStack[c] = false;
        if (c == cStart) {
            return true;
        }
        else return false;
    }
    onStack[c] = true;
    bool ans = fInCycle(f[c]);
    onStack[c] = false;
    return ans;
}

void fLongestChain (int c, int d) {
    if (isInCycle[c]) longestChain[c] = max (longestChain[c], d);
    else fLongestChain (f[c], d+1);
}

int main() {
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        resetAll();
        scanf ("%d", &N);
        FO (i,0,N) scanf ("%d", &f[i]);
        FO (i,0,N) f[i] = f[i]-1;
        FO (i,0,N) inD[f[i]]++;
        //Make components. In each component get the cyc length and if it's a 2 cyc. Also get length of thing
        FO (i,0,N) {
            getInfo (i,0);
            cStart = i;
            isInCycle[i] = fInCycle(i);
        }
        FO (i,0,N) fLongestChain(i,0);
        FO (i,0,N) {
            //printf ("%d: lastPlc: %d\n", i, fLastPlc(i));
            int fLast = fLastPlc(i);
            bestLen[compNum[i]] = max (bestLen[compNum[i]], len[i] + longestChain[fLast]);
        }
        FO (i,0,N) {
            //printf ("Component[%d]: %d %d\n", i, compNum[i], len[i]);
        }
        //Test getting all 2 comps:
        int ans = 0;
        FO (i,0,N) {
            if (cycLen[i] == 2) {
                ans += bestLen[i];
            }
        }
        int othAns = 0;
        FO (i,0,N) othAns = max (othAns, cycLen[i]);
        printf ("%d\n", max(ans,othAns));
    }
    return 0;
}
