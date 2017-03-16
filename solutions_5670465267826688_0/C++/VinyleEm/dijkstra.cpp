#include <iostream>
#include <string.h>
#include <sstream>
#include <string>

using namespace std;

// i -> 2, j -> 3, k -> 4
// -i -> -2, -j -> -3, -k -> -4
// 1 -> 1, -1 -> -1
typedef int quart;

quart to_q(char c)
{
    switch (c) {
        case '1':
            return 1;
        case 'i':
            return 2;
        case 'j':
            return 3;
        case 'k':
            return 4;
    }

    throw;
}

quart qmult(quart a, quart b)
{
    if (a < 0)
        return -qmult(-a, b);
    else if (b < 0)
        return -qmult(a, -b);
    else if (a == 1)
        return b;
    else if (b == 1)
        return a;
    else if (a == b)
        return -1;
    else if (a == 2) {
        return b == 3 ? 4 : -3;
    } else if (a == 3) {
        return b == 2 ? -4 : 2;
    } else if (a == 4) {
        return b == 2 ? 3 : -2;
    }
    
    return 12;
}

const int MAXLEN = 200100;
int dp[MAXLEN][9][4];

int is_a_good_split(int x, quart pq, int i, const string& name)
{
    if (x == (int)name.size()) {
        return (i == 3 && pq == 1) || (i == 2 && pq == to_q('k'));
    }

    int& ans = dp[x][pq + 4][i];
    if (ans >= 0)
        return ans;
    ans = 0;

    static const string D = "ijk";

    if (i < 3 and pq == to_q(D[i])) {
        if (is_a_good_split(x, 1, i + 1, name))
            return ans = 1;
    }

    if (is_a_good_split(x + 1, qmult(pq, to_q(name[x])), i, name))
        return ans = 1;

    return ans;
}

string reps(const string& s, int r)
{
    ostringstream os;
    for (int i = 0;i < r; ++i)
        os << s;
    return os.str();
}

string solve(const string& name, int X)
{
    int n = (int)name.size();
    memset(dp, -1, sizeof dp);

    return is_a_good_split(0, 1, 0, reps(name, X)) ? "YES" : "NO";
}


int main(int argc, char **argv)
{
    int num_cases;
    cin >> num_cases;

    for (int cas = 1;cas <= num_cases; ++cas) {
        int L;
        long long X;
        string name;

        cin >> L >> X >> name;

        string ret = "NO";
        for (int i = 1;i <= 20 and i <= X; i++)
            if (i % 4 == X % 4 and solve(name, i) == "YES") {
                ret = "YES";
                break;
            }

        cout << "Case #" << cas << ": " << ret << endl;
    }

    return 0;
}
