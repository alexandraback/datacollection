#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

typedef struct {
    int num;
    int type;
    vector<int> keys;
} Chest;

const int MAX_TYPES = 200;

int K;
int N;

vector<int> KEYS(MAX_TYPES, 0);
vector<Chest> CHESTS;

void read_input()
{
    cin >> K >> N;

    fill(KEYS.begin(), KEYS.end(), 0);
    for (int i = 0; i < K; ++i) {
        int t;
        cin >> t;
        ++KEYS[t];
    }

    CHESTS.clear();
    CHESTS.reserve(N);
    for (int j = 0; j < N; ++j) {
        int t, m;
        cin >> t >> m;
        Chest c;
        c.num = j;
        c.type = t;
        c.keys.reserve(m);
        for (; m > 0; --m) {
            int key;
            cin >> key;
            c.keys.push_back(key);
        }
        CHESTS.push_back(c);
    }
#if 0
    cout << K << ' ' << N << endl;
    for (int i = 0; i < MAX_TYPES; ++i) {
        cout << KEYS[i] << ' ';
    }
    cout << endl;
    for (auto &c: CHESTS) {
        cout << c.type << ':';
        for (int key: c.keys) {
            cout << ' ' << key;
        }
        cout << endl;
    }
#endif
}

const int FAIL = -1;

int MEMO[1 << 20];

bool solve_step(long closed_mask, stack<int> &answer)
{
    if (closed_mask == 0) {
        // hooray, all chests are opened!
        return true;
    }
    if (MEMO[closed_mask] == FAIL) {
        // oops, we already tried that
        return false;
    }
    for (const Chest &c: CHESTS) {
        bool is_closed = (closed_mask & (1 << c.num));
        if (!is_closed) continue;
        if (KEYS[c.type] > 0) {  // we have a key to open chest #t
            --KEYS[c.type];  // use that key
            // add the keys from the opened chest
            for (int key: c.keys) {
                ++KEYS[key];
            }
            // recursive iteration with updated mask
            int mask = (closed_mask & ~(1 << c.num));
            if (solve_step(mask, answer)) {
                // hooray!
                answer.push(c.num);
                return true;
            } else {
                // undo the chest opening
                ++KEYS[c.type];
                for (int key: c.keys) {
                    --KEYS[key];
                }
            }
        }
    }
    MEMO[closed_mask] = FAIL;
    return false;
}

string solve()
{
    memset(MEMO, 0, sizeof(MEMO));
    stack<int> answer;
    int closed_mask = (1 << N) - 1;
    if (solve_step(closed_mask, answer)) {
        stringstream ss;
        while (answer.size() > 1) {
            ss << (1+answer.top()) << " ";
            answer.pop();
        }
        if (!answer.empty()) {
            ss << (1+answer.top());
        }
        return ss.str();
    } else {
        return "IMPOSSIBLE";
    }
}


int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        read_input();
        string answer = solve();
        cout << "Case #" << t << ": " << answer << endl;
    }
}