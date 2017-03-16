#include <iostream>
#include <fstream>
#include <windows.h>
#include <utility>

#define SUBMIT 0
#ifdef SUBMIT
    #define cin fin
    #define cout fout
#endif // SUBMIT

#define NUMBER_OF_REPETITIONS 21LL

using namespace std;

ifstream fin("C-large.in");
ofstream fout("C-large.out");

typedef pair < char, bool > quaternion; /// 'i, j, k' and true/false
typedef long long ll;

int T;
int L;
ll X;
string ijk, solve, answer, answer_of_all;
quaternion whole;

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

int find_idx_large(int start, char target) {
    quaternion idx;
    idx.first = '1';
    idx.second = true;

    for (int i=start; i<solve.size(); i++) {
        quaternion now; now.first = solve[i]; now.second = true;
        idx = combine(idx, now);
        if (idx.first == target && idx.second)
            return i;
    }
    return -1;
}

quaternion remain(int start) {
    quaternion idx;
    idx.first = '1';
    idx.second = true;

    for (int i=start; i<solve.size(); i++) {
        quaternion now; now.first = solve[i]; now.second = true;
        idx = combine(idx, now);
    }
    return idx;
}

quaternion power(quaternion yolo, int len) {
    quaternion retVal;
    if (len%2 != 0 && yolo.second == false)
        retVal.second = false;
    else
        retVal.second = true;

    if (yolo.first == '1')
        retVal.first = '1';
    else {
        if (len%4 == 0)
            retVal.first = '1';
        else if (len%4 == 1)
            retVal.first = yolo.first;
        else if (len%4 == 2) {
            retVal.first = '1';
            retVal.second = !retVal.second;
        } else {
            retVal.first = yolo.first;
            retVal.second = !retVal.second;
        }
    }
    return retVal;
}

int main()
{
    cin >> T;

    for (int test=1; test<=T; test++) {
        cin >> L >> X;
        cin >> ijk;

        whole.first = '1'; whole.second = true;
        for (int i=0; i<ijk.size(); i++) {
            quaternion yolo; yolo.first = ijk[i]; yolo.second = true;
            whole = combine(whole, yolo);
        }

        answer = "YES";
        answer_of_all = "NO";
        solve = "";
        for (int i=0; i<min(NUMBER_OF_REPETITIONS, X); i++) {
            solve += ijk;

            /// for x
            int x = find_idx_large(0, 'i');
            if (x == -1) {
                answer = "NO";
                continue;
            }

            /// for y
            int y = find_idx_large(x+1, 'j');
            if (y == -1) {
                answer = "NO";
                continue;
            }

            /// for z
            int z = find_idx_large(y+1, 'k');
            if (z == -1) {
                answer = "NO";
                continue;
            }

            quaternion add = remain(z+1);
            quaternion ans = power(whole, X-i-1);

            add = combine(add, ans);

            if (add.first == '1' && add.second)
                answer = "YES";
            else
                answer = "NO";

            if (answer == "YES")
                answer_of_all = "YES";

        }

        cout << "Case #" << test << ": " << answer_of_all << "\n";
    }


    return 0;
}
