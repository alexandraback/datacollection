#include <iostream>
#include <vector>
#include "../../gcjoutput.h"

using namespace std;

enum quaternionType {one, qi, qj, qk};

struct quaternion {
    quaternionType type;
    bool minus;
};

quaternion table[4][4];

quaternion mul(const quaternion &a, const quaternion &b) {
    quaternion res = table[a.type][b.type];
    res.minus = ((res.minus != a.minus) != b.minus);
    return res;
}

quaternion power(const quaternion &a, long long pow) {
    if (pow == 0)
        return {one, false};
    quaternion elem = power(a, pow / 2);
    if (pow % 2 == 0)
        return mul(elem, elem);
    else
        return mul(mul(elem, elem), a);
}

char getChar(long long pos, const vector<char> &qs) {
    pos %= qs.size();
    return qs[pos];
}

quaternion getQ(char c) {
    quaternion res;
    res.minus = false;
    switch (c) {
        case 'i': res.type = qi; break;
        case 'j': res.type = qj; break;
        case 'k': res.type = qk; break;
    }
    return res;
}

int main()
{
    table[one][one] = {one, false};
    table[one][qi] = {qi, false};
    table[one][qj] = {qj, false};
    table[one][qk] = {qk, false};
    table[qi][one] = {qi, false};
    table[qj][one] = {qj, false};
    table[qk][one] = {qk, false};

    table[qi][qi] = {one, true};
    table[qj][qj] = {one, true};
    table[qk][qk] = {one, true};

    table[qi][qj] = {qk, false};
    table[qi][qk] = {qj, true};
    table[qj][qi] = {qk, true};
    table[qj][qk] = {qi, false};
    table[qk][qi] = {qj, false};
    table[qk][qj] = {qi, true};

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        long long l, x;
        scanf("%lld %lld\n", &l, &x);
        vector <char> qs(l);
        for (int j = 0; j < l; j++) {
            char c;
            scanf("%c", &c);
            qs[j] = c;
        }

        quaternion now = {one, false};
        for (int j = 0; j < l; j++)
            now = mul(now, getQ(qs[j]));
        now = power(now, x);
        if (now.type != one || now.minus != true) {
            output << nextCase << "NO";
            continue;
        }

        long long minposI = -1;
        now = {one, false};
        for (long long pos = 0; pos < min(10LL * l, x * l); pos++) {
            quaternion posQ = getQ(getChar(pos, qs));
            now = mul(now, posQ);

            if (now.type == qi && now.minus == false) {
                minposI = pos;
                break;
            }
        }

        if (minposI == -1) {
            output << nextCase << "NO";
            continue;
        }

        long long maxposK = -1;
        now = {one, false};
        for (long long pos = x * l - 1; pos >= max(x * l - 10LL * l, 0LL); pos--) {
            quaternion posQ = getQ(getChar(pos, qs));
            now = mul(posQ, now);

            if (now.type == qk && now.minus == false) {
                maxposK = pos;
                break;
            }
        }

        if (maxposK == -1 || maxposK <= minposI + 1) {
            output << nextCase << "NO";
            continue;
        }

        output << nextCase << "YES";
    }
    return 0;
}
