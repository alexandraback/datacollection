#include<iostream>
#include<vector>
using namespace std;

const int BUF = 10;


class Hiker {
public:
    int pos, tookTime;
    Hiker(){}
    Hiker(int pos, int tookTime):
        pos(pos), tookTime(tookTime){}
};


int nHiker;
Hiker hiker[BUF];

void read() {
    nHiker = 0;
    
    int nGroup;
    cin >> nGroup;
    
    for (int i = 0; i < nGroup; ++i) {
        int pos, N, M;
        cin >> pos >> N >> M;
        for (int j = 0; j < N; ++j) {
            hiker[nHiker++] = Hiker(pos, M + j);
        }
    }
}


vector<double> collisionTime(Hiker slow, Hiker fast) {
    vector<double> timeList;

    int dist = (360 + slow.pos - fast.pos) % 360;
    double speed = (360.0 / fast.tookTime - 360.0 / slow.tookTime);

    timeList.push_back(dist / speed);
    timeList.push_back((dist + 360)/ speed);
    
    return timeList;
}

double goalTime(Hiker hiker) {
    int dist = 360 - hiker.pos;
    double speed = 360.0 / hiker.tookTime;
    return dist / speed;
}

void work(int cases) {
    if (nHiker == 1 || hiker[0].tookTime == hiker[1].tookTime) {
        cout << "Case #" << cases << ": 0" << endl;
        return;
    }

    if (hiker[0].tookTime < hiker[1].tookTime)
        swap(hiker[0], hiker[1]);
    
    int ans = 0;
    if (hiker[0].pos >= hiker[1].pos) {
        if (goalTime(hiker[0]) > collisionTime(hiker[0], hiker[1])[1] - 1e-6)
            ans = 1;
    }
    else {
        if (goalTime(hiker[0]) > collisionTime(hiker[0], hiker[1])[0] - 1e-6)
            ans = 1;
    }

    cout << "Case #" << cases << ": " << ans << endl;
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
