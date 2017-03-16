#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define FT first
#define SD second
#define Y first
#define X second

vector<string>token(string a) {
    vector<string>w;a.push_back(' ');
    while(!a.empty()){w.push_back(a.substr(0,a.find(" ")));a=a.substr(a.find(" ")+1,a.size()-1);}return w;
}

map<string,int> mapik;
vector<string> amapik;
int dodaj(string a) {if(mapik.count(a)==0) {mapik[a]=mapik.size()-1;amapik.PB(a);}return mapik[a];}

const int INF = 1000000000;
const LL INFINF = 1000000000000000000LL;

char tmp_str[1000];
string scanf_string() {
    scanf("%s",tmp_str);
    return tmp_str;
}

inline bool get_bit(int w, int i) {
    return (w>>i)&1;
}

LL wyznacz_skret(PI pkt1, PI pkt2, PI cel)
{
    // -X na lewo, 0 prosto, +X na prawo
    PI wektorA = MP(pkt2.first - pkt1.first, pkt2.second - pkt1.second);
    PI wektorB = MP(cel.first - pkt1.first, cel.second - pkt1.second);
    return (LL)wektorB.first * wektorA.second - (LL)wektorA.first * wektorB.second;
}


LL binarka(LL a, LL b, LL target, LL map(LL)) // [a,b]
{
    // [mniejsze od target][wieksze rowne target]
    // znajdz i pierwszego elementu [wieksze...]
    while (a < b)
    {
        LL c = (a + b) / 2;
        if (map(c) >= target) {
            b = c;
        }
        else {
            a = c + 1;
        }
    }
    return a;
}

LL wyznacz_skret2(PI &pkt1, PI &pkt2, PI &cel)
{
    // -X na lewo, 0 prosto, +X na prawo
    int WA1 = pkt2.first - pkt1.first; 
    int WA2 = pkt2.second - pkt1.second;

    int WB1 = cel.first - pkt1.first;
    int WB2 = cel.second - pkt1.second;
    return (LL)WB1 * WA2 - (LL)WA1 * WB2;
}

// ==========================================================

const int N = 1000;
int n;
string slowa[20][2];
set<string> slowa_ok[2];
set<int> prawdziwe;

int main() {
    int daa;scanf("%d",&daa);
    for(int ind=1;ind<=daa;ind++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            slowa[i][0] = scanf_string();
            slowa[i][1] = scanf_string();
        }

        int best = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            slowa_ok[0].clear();
            slowa_ok[1].clear();
            prawdziwe.clear();
            int zz = i;
            int ok = 1;
            for (int k = 0; zz > 0;k++)
            {
                if (zz % 2)
                {
                    slowa_ok[0].insert(slowa[k][0]);
                    slowa_ok[1].insert(slowa[k][1]);
                    prawdziwe.insert(k);
                }
                zz /= 2;
            }
            for (int k = 0; k < n; k++)
            {
                if (prawdziwe.count(k) == 0)
                {
                    if (slowa_ok[0].count(slowa[k][0]) == 0 || slowa_ok[1].count(slowa[k][1]) == 0)
                    {
                        ok = 0;
                        break;
                    }

                }

            }
            if (ok)
            {
                best = max(best, (int)(n - prawdziwe.size()));
            }
        }
        
        printf("Case #%d: %d\n",ind, best);
    }
    return 0;
}
