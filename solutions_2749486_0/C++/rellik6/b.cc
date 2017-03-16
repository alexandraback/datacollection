#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct state {
    int x, y;
    string s;
    state(int _x, int _y, string _s): x(_x), y(_y), s(_s) {}
};

const int NDIR = 4;
const int DX[NDIR] = {-1, 0, 0, 1};
const int DY[NDIR] = {0, -1, 1, 0};
const char *DIR_SYM = "WSNE";

const int MAXX = 210;
const int MAX_STEP = MAXX * 2;

queue<state> q;
bool visited[MAXX * 2 + 10][MAXX * 2 + 10][MAX_STEP];

int main() 
{
    int tot_case;
    cin >> tot_case;
    for (int num_case = 1; num_case <= tot_case; num_case++) {
        int x, y;
        cin >> x >> y;

        memset(visited, 0, sizeof(visited));
        q.push(state(0, 0, ""));
        visited[MAXX][MAXX][0] = true;
        while (!q.empty()) {
            state now = q.front();
            if (now.x == x and now.y == y) {
                cout << "Case #" << num_case << ": " << now.s << endl;
                break;
            }
            q.pop();
            int next = now.s.length() + 1;
            for (int i = 0; i < NDIR; i++) {
                state new_state = state(now.x + DX[i] * next,
                        now.y + DY[i] * next, now.s + DIR_SYM[i]);
                if (new_state.x + MAXX <= 0 
                        || new_state.x + MAXX > MAXX * 2) {
                    continue;
                }
                if (new_state.y + MAXX <= 0 
                        || new_state.y + MAXX > MAXX * 2) {
                    continue;
                }
                if (!visited[new_state.x + MAXX][new_state.y + MAXX][next]) {
                    q.push(new_state);
                    visited[new_state.x + MAXX][new_state.y + MAXX][next] 
                        = true;
                }
            }
        }

        while (!q.empty()) {
            q.pop();
        }
    }
}
