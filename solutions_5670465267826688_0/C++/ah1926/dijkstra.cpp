#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long int64;

class Quaternion {
  public:
    Quaternion():
      versor(0) {}

    Quaternion(const char _versor, const int sign = 1):
      versor(sign * indexMap[_versor]) {}

    Quaternion(const string &expression) {
        if (expression[0] == '-')
            *this = Quaternion(expression[1], -1);
        else
            *this = Quaternion(expression[0]);
    }

    Quaternion(const char *expression):
      Quaternion(string(expression)) {}

    Quaternion operator=(const string &expression) {
        return *this = Quaternion(expression);
    }

    Quaternion operator*(const Quaternion &other) const {
        return Quaternion(Sign(versor) * Sign(other.versor) * multiplicationMatrix[Abs(versor)][Abs(other.versor)]);
    }

    Quaternion operator*=(const Quaternion &other) {
        return *this = *this * other;
    }

    bool operator==(const Quaternion &other) const {
        return versor == other.versor;
    }

    bool operator!=(const Quaternion &other) const {
        return versor != other.versor;
    }

  private:
    static vector< vector<int> > multiplicationMatrix;
    static map<char, int> indexMap;

    int versor;

    Quaternion(const int _versor):
      versor(_versor) {}

    static int Abs(const int value) {
        if (value < 0)
            return -value;
        return value;
    }

    static int Sign(const int value) {
        if (value < 0)
            return -1;
        if (value > 0)
            return 1;
        return 0;
    }
};

vector< vector<int> > Quaternion::multiplicationMatrix = {
  {0, 0, 0, 0, 0},
  {0, 1, 2, 3, 4},
  {0, 2, -1, 4, -3},
  {0, 3, -4, -1, 2},
  {0, 4, 3, -2, -1}
};

map<char, int> Quaternion::indexMap = {
  {'0', 0}, {'1', 1}, {'i', 2}, {'j', 3}, {'k', 4}
};

inline Quaternion Power(Quaternion q, int64 p) {
    Quaternion r = '1';
    for (; p > 0; p >>= 1) {
        if (p & 1)
            r *= q;
        q *= q;
    }
    return r;
}

pair<Quaternion, int> GetPrefix(const string &S) {
    Quaternion p = '1';
    int prefix = 0;
    while (prefix < int(S.length()) && p != 'i')
        p *= S[prefix++];
    return make_pair(p, prefix);
}

pair<Quaternion, int> GetSuffix(const string &S) {
    Quaternion s = '1';
    int suffix = 0;
    while (suffix < int(S.length()) && s != 'k')
        s = Quaternion(S[int(S.length()) - 1 - suffix++]) * s;
    return make_pair(s, suffix);
}

bool Brute(const string &S) {
    Quaternion total = '1';
    for (int i = 0; i < int(S.length()); ++i)
        total *= S[i];
    Quaternion p, s;
    int prefix, suffix;
    tie(p, prefix) = GetPrefix(S);
    tie(s, suffix) = GetSuffix(S);
    Quaternion middle = '1';
    for (int i = prefix; i < int(S.length()) - suffix; ++i)
        middle *= S[i];
    return (p == 'i' && middle == 'j' && s == 'k');
}

bool SolveBig(const string &S, const int64 X) {
    string SPeriod = "";
    for (int i = 0; i < 4; ++i)
        SPeriod += S;
    Quaternion p, s;
    int prefix, suffix;
    tie(p, prefix) = GetPrefix(SPeriod);
    tie(s, suffix) = GetSuffix(SPeriod);
    Quaternion middle = '1';
    for (int i = 0; i < int(S.length()); ++i)
        middle *= S[i];
    middle = Power(middle, X - 8);
    for (int i = int(SPeriod.length()) - 1; i >= prefix; --i)
        middle = Quaternion(SPeriod[i]) * middle;
    for (int i = 0; i < int(SPeriod.length()) - suffix; ++i)
        middle *= SPeriod[i];
    return (p == 'i' && middle == 'j' && s == 'k');
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int N;
        int64 X;
        string S;
        cin >> N >> X >> S;
        string answer = "";
        if (X <= 8) {
            string totalS = "";
            for (int i = 0; i < X; ++i)
                totalS += S;
            if (Brute(totalS))
                answer = "YES";
            else
                answer = "NO";
        } else {
            if (SolveBig(S, X))
                answer = "YES";
            else
                answer = "NO";
        }
        cout << "Case #" << t << ": " << answer << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
