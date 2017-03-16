#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
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

char tmp_str[10000000];
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
int sumy[1000];
string data1;
string data2;

int wart(int pos, int prop)
{
    if (pos < 3)
    {
        if (data1[pos] == '?')
            return prop;
        return data1[pos] - '0';
    }
    else
    {
        if (data2[pos-3] == '?')
            return prop;
        return data2[pos-3] - '0';
    }
}

int main() {
    int daa;scanf("%d",&daa);
    for(int ind=1;ind<=daa;ind++) {
        data1 = scanf_string();
        data2 = scanf_string();
        int dl = data1.size();
        while (data1.size()<3)
        {
            data1 = "0" + data1;
            data2 = "0" + data2;
        }
        int res = 100000;
        string best1;
        string best2;
        int bestnum1;
        int bestnum2;

        for (int i = 0; i < 10; i++)
        {
            for (int i2 = 0; i2 < 10; i2++)
                for (int i3 = 0; i3 < 10; i3++)
                    for (int i4 = 0; i4 < 10; i4++)
                        for (int i5 = 0; i5 < 10; i5++)
                            for (int i6 = 0; i6 < 10; i6++)
                            {
                                int warto1 = wart(0, i) * 100 + wart(1, i2) * 10 + wart(2, i3);
                                int warto2 = wart(3, i4) * 100 + wart(4, i5) * 10 + wart(5, i6);
                                int diff = abs(warto1 - warto2);
                                if (diff < res || diff == res && bestnum1 > warto1 || diff == res && bestnum1 == warto1 && bestnum2 > warto1)
                                {
                                    char tmp[10];
                                    sprintf(tmp, "%d", warto1);
                                    best1 = tmp;
                                    bestnum1 = warto1;
                                    sprintf(tmp, "%d", warto2);
                                    best2 = tmp;
                                    bestnum2 = warto2;
                                    res = diff;
                                }

                            }
        }

        while (best1.size() < dl)
        {
            best1 = "0" + best1;
        }
            while (best2.size()<dl)
            {
            best2 = "0" + best2;
        }

        printf("Case #%d: %s %s\n", ind, best1.c_str(), best2.c_str());
    }
    return 0;
}
