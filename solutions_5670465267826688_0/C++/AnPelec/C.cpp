#include <iostream>
#include <fstream>
#include <windows.h>
#include <utility>

#define SUBMIT 0
#ifdef SUBMIT
    #define cin fin
    #define cout fout
#endif // SUBMIT

using namespace std;

ifstream fin("C-small.in");
ofstream fout("C-small.out");

typedef pair < char, bool > quaternion; /// 'i, j, k' and true/false

int T;
int L, X;
string ijk, solve, answer;

quaternion combine(quaternion x, quaternion y) {
    quaternion retVal; retVal.second = !(x.second ^ y.second);

    if (x.first == '1') retVal.first = y.first;
    else if (y.first == '1') retVal.first = x.first;
    else if (x.first == y.first) {retVal.first = '1'; retVal.second = !retVal.second;}
    else {
        if (x.first == 'i') {
            if (y.first == 'j') {
                retVal.first = 'k';
            } else if (y.first == 'k') {
                retVal.first = 'j';
                retVal.second = !retVal.second;
            }
        } else if (x.first == 'j') {
            if (y.first == 'i') {
                retVal.first = 'k';
                retVal.second = !retVal.second;
            } else if (y.first == 'k') {
                retVal.first = 'i';
            }
        } else {
            if (y.first == 'i') {
                retVal.first = 'j';
            } else if (y.first == 'j') {
                retVal.first = 'i';
                retVal.second = !retVal.second;
            }
        }
    }
    return retVal;
}

int find_idx(int start, char target) {
    quaternion idx;
    idx.first = '1';
    idx.second = true;

    if (target == 'k') {
        for (int i=start; i<solve.size(); i++) {
            quaternion now; now.first = solve[i]; now.second = true;
            idx = combine(idx, now);
        }

        if (idx.first == target && idx.second)
            return 42;
        else return -1;
    } else {
        for (int i=start; i<solve.size(); i++) {
            quaternion now; now.first = solve[i]; now.second = true;
            idx = combine(idx, now);
            if (idx.first == target && idx.second)
                return i;
        }
        return -1;
    }
}

int main()
{
    cin >> T;

    for (int test=1; test<=T; test++) {
        cin >> L >> X;
        cin >> ijk;

        answer = "YES";
        solve = "";
        for (int i=0; i<X; i++)
            solve += ijk;

        int x = find_idx(0, 'i');
        if (x == -1)
            answer = "NO";
        int y = find_idx(x+1, 'j');
        if (y == -1)
            answer = "NO";
        int z = find_idx(y+1, 'k');
        if (z == -1)
            answer = "NO";

        cout << "Case #" << test << ": " << answer << "\n";
    }


    return 0;
}
