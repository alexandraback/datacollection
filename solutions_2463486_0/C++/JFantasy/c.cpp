#include <cstdio>
#include <cstring>
#include <algorithm>

#define sqr(x) (x) * (x)

using namespace std;

const int maxn = 105;
const int maxk = 10;

struct bigint {
    int num[maxn], len;
    bigint(int x = 0) {
        memset(num, 0, sizeof(num));
        len = 0;
        while (x) {
            num[len ++] = x % 10;
            x /= 10;
        }
        if (!len) ++ len;
    }
    bigint(char *s) {
        memset(num, 0, sizeof(num));
        len = strlen(s);
        for (int i = len - 1; i >= 0; -- i) num[len - i - 1] = s[i] - '0';
    }
    bigint operator + (const bigint &ot) {
        bigint ret;
        ret.len = max(len, ot.len);
        for (int i = 0; i < ret.len; ++ i) {
            ret.num[i] += num[i] + ot.num[i];
            if (ret.num[i] >= 10) {
                ret.num[i] -= 10;
                ++ ret.num[i + 1];
            }
        }
        if (ret.num[ret.len]) ++ ret.len;
        return ret;
    }
    bigint operator + (const int &val) {
        bigint ret(*this);
        ret.num[0] += val;
        int i = 0;
        while (ret.num[i] >= 10) {
            ret.num[i] -= 10;
            ++ ret.num[i + 1];
            ++ i;
        }
        if (ret.num[ret.len]) ++ ret.len;
        return ret;
    }
    bigint operator - (const bigint &ot) {
        bigint ret(*this);
        for (int i = 0; i < ret.len; ++ i) {
            ret.num[i] -= ot.num[i];
            if (ret.num[i] < 0) {
                ret.num[i] += 10;
                -- ret.num[i + 1];
            }
        }
        while (ret.len > 1 && !ret.num[ret.len - 1]) -- ret.len;
        return ret;
    }
    bigint operator - (const int &val) {
        bigint ret(*this);
        ret.num[0] -= val;
        int i = 0;
        while (ret.num[i] < 0) {
            ret.num[i] += 10;
            -- ret.num[i + 1];
            ++ i;
        }
        while (ret.len > 1 && !ret.num[ret.len - 1]) -- ret.len;
        return ret;
    }
    bigint operator * (const bigint &ot) {
        bigint ret;
        for (int i = 0; i < len; ++ i) {
            for (int j = 0; j < ot.len; ++ j) {
                ret.num[i + j] += num[i] * ot.num[j];
                if (ret.num[i + j] >= 10) {
                    ret.num[i + j + 1] += ret.num[i + j] / 10;
                    ret.num[i + j] %= 10;
                }
            }
        }
        ret.len = len + ot.len;
        while (ret.len > 1 && !ret.num[ret.len - 1]) -- ret.len;
        return ret;
    }
    bigint operator / (const int val) {
        bigint ret;
        int d = 0;
        for (int i = len - 1; i >= 0; -- i) {
            ret.num[i] = (d * 10 + num[i]) / val;
            d = (d * 10 + num[i]) % val;
        }
        ret.len = len;
        while (ret.len > 1 && !ret.num[ret.len - 1]) -- ret.len;
        return ret;
    }
    bigint sqrt() {
        bigint lower(0), upper(*this), ret(0);
        while (lower <= upper) {
            bigint mid = (lower + upper) / 2;
            if ((mid * mid) <= (*this)) {
                ret = mid;
                lower = mid + int(1);
            } else upper = mid - int(1);
        }
        return ret;
    }
    bool operator < (const bigint &ot) const {
        if (len != ot.len) return len < ot.len;
        for (int i = len - 1; i >= 0; -- i) {
            if (num[i] != ot.num[i]) return num[i] < ot.num[i];
        }
        return 0;
    }
    bool operator <= (const bigint &ot) const {
        if (len != ot.len) return len < ot.len;
        for (int i = len - 1; i >= 0; -- i) {
            if (num[i] != ot.num[i]) return num[i] < ot.num[i];
        }
        return 1;
    }
    void print() {
        for (int i = len - 1; i >= 0; -- i) printf("%d", num[i]);
        puts("");
    }
    bool zero() {
        return !num[0] && len <= 1;
    }
} f[maxn][maxk][2], g[maxn][maxk], a, b;
char s1[maxn], s2[maxn];

void init() {
    scanf("%s%s", s1, s2);
    a = bigint(s1).sqrt();
    b = bigint(s2).sqrt();
    if (a * a < bigint(s1)) a = a + 1;
}

int check(bigint x) {
    if (x.len == 1) return 0;
    int s = 0;
    for (int i = 0; i < x.len / 2; ++ i) {
        s += x.num[x.len - i - 1] * x.num[x.len - i - 1] * 2;
    }
    if (x.len & 1) s += x.num[x.len / 2] * x.num[x.len / 2];
    if (s >= 10) return 0;
    int l = x.len / 2 - 1, r = x.len / 2 + (x.len & 1);
    for (int i = 0; i < x.len / 2; ++ i) {
        if (x.num[l] < x.num[r]) return 1;
        if (x.num[l] > x.num[r]) return 0;
        -- l;
        ++ r;
    }
    return 0;
}

bigint cal(bigint x) {
    bigint ans(0);

    memset(g, 0, sizeof(g));
    g[0][0] = bigint(1);
    for (int i = 1; i * 2 < x.len; ++ i) {
        for (int j = 0; j < 5; ++ j) {
            if (g[i - 1][j].zero()) continue;
            for (int h = (i == 1); h < 5; ++ h) {
                if (j + h * h >= 5) continue;
                g[i][j + h * h] = g[i][j + h * h] + g[i - 1][j];
            }
        }
    }
    for (int i = 1; i * 2 < x.len; ++ i) {
        for (int j = 0; j < 5; ++ j) {
            if (g[i][j].zero()) continue;
            ans = ans + g[i][j];
        }
    }
    for (int i = 0; i * 2 + 1 < x.len; ++ i) {
        for (int j = 0; j < 5; ++ j) {
            if (g[i][j].zero()) continue;
            for (int h = 0; h < 5; ++ h) {
                if (j * 2 + h * h >= 10) continue;
                ans = ans + g[i][j];
            }
        }
    }

    memset(f, 0, sizeof(f));
    f[0][0][0] = bigint(1);
    for (int i = 1; i <= x.len / 2; ++ i) {
        for (int j = 0; j < 5; ++ j) {
            if (!f[i - 1][j][0].zero()) {
                for (int h = (i == 1); h <= x.num[x.len - i]; ++ h) {
                    if (j + h * h >= 5) continue;
                    f[i][j + h * h][h < x.num[x.len - i]] = f[i][j + h * h][h < x.num[x.len - i]] + f[i - 1][j][0];
                }
            }
            if (!f[i - 1][j][1].zero()) {
                for (int h = 0; h < 5; ++ h) {
                    if (j + h * h >= 5) continue;
                    f[i][j + h * h][1] = f[i][j + h * h][1] + f[i - 1][j][1];
                }
            }
        }
    }
    if (x.len & 1) {
        for (int i = 0; i < 5; ++ i) {
            if (f[x.len / 2][i][1].zero()) continue;
            for (int j = 0; j < 5; ++ j) {
                if (i * 2 + j * j >= 10) continue;
                ans = ans + f[x.len / 2][i][1];
            }
        }
        for (int i = 0; i < 5; ++ i) {
            if (f[x.len / 2][i][0].zero()) continue;
            for (int j = 0; j <= x.num[x.len / 2]; ++ j) {
                if (i * 2 + j * j >= 10) continue;
                ans = ans + f[x.len / 2][i][0];
            }
        }
    } else {
        for (int i = 0; i < 5; ++ i) {
            ans = ans + f[x.len / 2][i][0] + f[x.len / 2][i][1];
        }
    }

    ans = ans - check(x);
    return ans;
}

void work() {
    (cal(b) - cal(a - 1)).print();
}

int main() {
    int cas, t = 0;
    scanf("%d", &cas);
    while (cas --) {
        init();
        printf("Case #%d: ", ++ t);
        work();
    }
    return 0;
}