//Krzysztof Pieprzak
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define Size(x) (int)x.size()
#define VAR(v,n) auto v = (n)
#define FOR(i,a,b) for(VAR(i,a); i < (b); ++i)
#define FORE(i,a,b) for(VAR(i,a); i <= (b); ++i)
#define FORREV(i,a,b) for(VAR(i,b); i >= (a); --i)
#define FORSTEP(i,a,b,step) for(VAR(i,a); i < (b); i += (step))
#define FOREACH(i,c) for(auto i : (c))
#define FOREACHS(i,c,n) for(VAR(i,&(c)[0]); i-(c)<(n); ++i)
#define ALL(x) x.begin(),x.end()
#define CLEAR(t) memset(t, 0, sizeof(t))
#define F first
#define S second
#define MP make_pair
#define PUB push_back
#define POB pop_back
#define pieprzu ios_base::sync_with_stdio(0);

const int    INF = 1000000001;
const double EPS = 10e-9;

const int SIZE = 20;
const int MAXN = 16;

char w[2*MAXN+5][SIZE+5];
int WS = 0;

pii topics[MAXN+5];

vi topics2;
vi topicsList[50];
set<int> vOrg;

char w1[SIZE+5];
char w2[SIZE+5];

int getId(char *ww) {
    FOR (i, 0, WS) {
        if (strcmp(w[i], ww) == 0) {
            return i;
        }
    }

    strcpy(w[WS], ww);
    ++WS;

    return WS-1;
}

void doClear() {
    FOREACH (t1, topics2) {
        topicsList[t1].clear();
    }
    topics2.clear();
    vOrg.clear();
}

void rob(int test) {
    int n;
    scanf("%d", &n);

    doClear();

    WS = 0;
    FOR (i, 0, n) {
        scanf("%s %s", w1, w2);
        topics[i] = MP(getId(w1), getId(w2));
    }

    sort(topics, topics + n);
    topics[n] = MP(-1,-1);

    /*printf("TOPICS:\n");
    FOR (i, 0, n) {
        printf("%d %d\n", topics[i].F, topics[i].S);
    }*/

    int prev = topics[0].F;
    int cnt = 1;
    FORE (i, 1, n) {
        if (topics[i].F == prev) {
            ++cnt;
        } else if (cnt == 1) {
            vOrg.insert(topics[i-1].S);
        } else {
            topics2.PUB(topics[i-1].F);
            FOR (j, 0, cnt) {
                topicsList[topics[i-1].F].PUB(topics[i-j-1].S);
            }
            cnt = 1;
        }
        prev = topics[i].F;
    }

    /*printf("TOPICS2:\n");
    FOREACH (t, topics2) {
        printf("%d\n", t);
        printf("TOPICS_LIST\n");
        FOREACH (tt, topicsList[t]) {
            printf("%d\n", tt);
        }
    }
    printf("\n\n");*/

    if (Size(topics2) == 0) {
        printf("Case #%d: 0\n", test);
        return;
    }

    int mxFake = 0;
    do {
        set<int> v = vOrg;
        set<int> special;
        int fake = 0;
        FOREACH (t1, topics2) {
            int fakeLocal = 0;
            FOREACH (t, topicsList[t1]) {
                if (v.find(t) != v.end()) {
                    ++fakeLocal;
                }
            }
            if (fakeLocal == Size(topicsList[t1])) {
                bool ok = false;
                FOREACH (t, topicsList[t1]) {
                    if (special.find(t) == special.end()) {
                        special.insert(t);
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    fake += fakeLocal - 1;
                } else {
                    fake += fakeLocal;
                }
            } else {
                fake += fakeLocal;
            }
            FOREACH (t, topicsList[t1]) {
                v.insert(t);
            }
        }

        mxFake = max(mxFake, fake);
    } while(next_permutation(ALL(topics2)));

    printf("Case #%d: %d\n", test, mxFake);
}

int main() {
    int test = 1;
    scanf("%d", &test);

    FORE (i, 1, test) rob(i);

    return 0;
}
