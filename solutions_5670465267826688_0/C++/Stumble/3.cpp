#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;

const int MAXN = 11111*1000;
int T;
LL L,X;
char data[MAXN];
int len;
#define symi 2
#define symj 3
#define symk 4
int sym_map[1900];
struct qnum;

struct qnum
{
    int sign;
    int val;
    qnum(int sign, int val):sign(sign),val(val) {};
    qnum(int val):sign(1),val(val) {};
    qnum() {};
    qnum operator*(const qnum &b);
};
qnum calc[10][10];
qnum qnum::operator*(const qnum &b) {
    int s = (sign * b.sign) * calc[val][b.val].sign;
    int v  = calc[val][b.val].val;
    return qnum(s,v);
};

void init()
{
    cin >> L >> X;
    cin >> &data[1];
    if (X > 15) {
        X %= 4;
        X += 12;
    }
    int pos = L + 1;
    for (int i = 1; i < X; i++) {
        for (int j = 1; j <= L; j++) {
            data[pos++] = data[j];
        }
    }
    len = X * L;
    // cout << &data[1] << endl;
}

int lookup(int beg, int symbol, bool last = false)
{
    qnum now = qnum(1);
    int pos = beg;
    while (pos <= len) {
        now = now * qnum(1,sym_map[data[pos]]);
        pos++;
        if(!last && now.val == symbol && now.sign == 1) return pos;
        if(last && now.val == symbol && now.sign == 1 && pos == len + 1) return pos;
    }
    return -1;
}

const char * solve()
{
    int rtn = lookup(1,symi);
    if (rtn < 0) return "NO";

    rtn = lookup(rtn,symj);
    if (rtn < 0) return "NO";

    rtn = lookup(rtn,symk,1);
    if (rtn < 0) return "NO";

    return "YES";
}

void table_init()
{
    sym_map['i'] = symi;
    sym_map['j'] = symj;
    sym_map['k'] = symk;

    calc[symi][symi] = qnum(-1,1);
    calc[symi][symj] = qnum(symk);
    calc[symi][symk] = qnum(-1,symj);

    calc[symj][symi] = qnum(-1,symk);
    calc[symj][symj] = qnum(-1,1);
    calc[symj][symk] = qnum(1,symi);

    calc[symk][symi] = qnum(symj);
    calc[symk][symj] = qnum(-1,symi);
    calc[symk][symk] = qnum(-1,1);

    for (int i = 1; i <= 4; i++) {
        calc[i][1] = calc[1][i] = qnum(i);
    }


    // for (int i = 1; i <= 4; i++) {
    //     for (int j = 1; j <= 4; j++) {
    //         qnum ans = qnum(i) * qnum(j);
    //         if(ans.sign == -1) printf("-");
    //         printf("%d ",ans.val);
    //     }

    //     puts("");
    // }

}

int main(int argc, char *argv[])
{
    // freopen("cast.txt","r",stdin);
    table_init();

    cin >> T;

    for (int tt = 1; tt <= T; tt++) {
        init();
        printf("Case #%d: %s\n",tt, solve());
    }
    return 0;
}



