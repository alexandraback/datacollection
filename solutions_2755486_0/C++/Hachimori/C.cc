#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int BUF = 1005, WALL = 10000;


class Event {
public:
    int day;
    int L, R, power;
    Event(){}
    Event(int day, int L, int R, int power):
        day(day), L(L), R(R), power(power){}

    bool operator< (const Event &e) const {
        return day < e.day;
    }
};

int nMan;
int initDay[BUF], nAttack[BUF], initPow[BUF], initL[BUF], initR[BUF];
int deltaDay[BUF], deltaPos[BUF], deltaPow[BUF];

void read() {
    cin >> nMan;
    for (int i = 0; i < nMan; i++) {
        cin >> initDay[i] >> nAttack[i]
            >> initL[i] >> initR[i] >> initPow[i]
            >> deltaDay[i] >> deltaPos[i] >> deltaPow[i];
        initL[i] *= 2;
        initR[i] *= 2;
        deltaPos[i] *= 2;
    }
}


void work(int cases) {
    vector<Event> event;
    for (int i = 0; i < nMan; i++) {
        int day = initDay[i];
        int power = initPow[i], L = initL[i], R = initR[i];
        for (int j = 0; j < nAttack[i]; j++) {
            event.push_back(Event(day, L, R, power));
            day += deltaDay[i];
            L += deltaPos[i];
            R += deltaPos[i];
            power += deltaPow[i];
        }
    }
    sort(event.begin(), event.end());

    /*
    for (int i = 0; i < event.size(); i++) {
        cout << event[i].day << ' ' << event[i].power << ' ' << event[i].L << ' ' << event[i].R << endl;
    }
    */

    int wall[WALL], ans = 0;
    memset(wall, 0, sizeof(wall));

#define access(p) wall[p + WALL / 2]

    for (int idx = 0; idx < event.size(); ) {
        int nextIdx = idx;
        while (nextIdx < event.size() && event[nextIdx].day == event[idx].day)
            nextIdx++;


        for (int i = idx; i < nextIdx; i++)
            for (int p = event[i].L; p <= event[i].R; p++)
                if (access(p) < event[i].power) {
                    ans++;
                    break;
                }

        for (int i = idx; i < nextIdx; i++)
            for (int p = event[i].L; p <= event[i].R; p++)
                access(p) = max(access(p), event[i].power);

        idx = nextIdx;
    }

    cout << "Case #" << cases << ": " << ans << endl;
}


int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        read();
        work(i + 1);
    }
    return 0;
}
