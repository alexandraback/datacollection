//
//  main.cpp
//  TestCppCode
//

#include <iostream>
#include <list>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

//#define TEST

const int size = 1000;

class data {
public:
    int sx, sy;
    int step;
    string path;
    data(int x, int y, int st, string p) {
        sx = x; sy = y; step = st; path = p;
    }
};

int main() {
#ifdef TEST
    for (int X=-100; X<=100; X++) for (int Y=-100;Y<=100;Y++) { static int t = 0; t++;
#else
    int T; cin>>T;
    for (int t = 1; t <= T; t++) {
        int X, Y; cin >> X >> Y;
#endif
        int visited[size][size] = {0};
        queue< data* > Q;
        Q.push(new data(0, 0, 1, "")); visited[size/2+0][size/2+0]=1;
        string answer;
        while (!Q.empty()) {
            data *d = Q.front(); Q.pop();
            int x = d->sx; int y = d->sy; int step = d->step;
            //cout << "x = " << x << ", y = " << y << "\n";
            int xx, yy;
            // Direction E;
            xx = x+step, yy = y;
            if (size/2+xx >=0 && size/2+xx <size && size/2+yy >=0 && size/2+yy <size && !(visited[size/2+xx][size/2+yy])) {
                if (xx == X && yy == Y) {
                    answer = d->path + "E"; break;
                }
                data *dE = new data(xx, yy, step + 1, d->path + "E");
                Q.push(dE); visited[size/2+xx][size/2+yy] = 1;
            }

            // Direction W
            xx = x-step, yy = y;
            if (size/2+xx >=0 && size/2+xx <size && size/2+yy >=0 && size/2+yy <size && !(visited[size/2+xx][size/2+yy])) {
                if (xx == X && yy == Y) {
                    answer = d->path + "W"; break;
                }
                data *dW = new data(xx, yy, step + 1, d->path + "W");
                Q.push(dW); visited[size/2+xx][size/2+yy] = 1;
            }

            // Direction N
            xx = x, yy = y+step;
            if (size/2+xx >=0 && size/2+xx <size && size/2+yy >=0 && size/2+yy <size && !(visited[size/2+xx][size/2+yy])) {
                if (xx == X && yy == Y){
                    answer = d->path + "N"; break;
                }
                data *dN = new data(xx, yy, step + 1, d->path + "N");
                Q.push(dN); visited[size/2+xx][size/2+yy] = 1;
            }

            // Direction S
            xx = x, yy = y-step;
            if (size/2+xx >=0 && size/2+xx <size && size/2+yy >=0 && size/2+yy <size && !(visited[size/2+xx][size/2+yy])) {
                if (xx == X && yy == Y){
                    answer = d->path + "S"; break;
                }
                data *dS = new data(xx, yy, step + 1, d->path + "S");
                Q.push(dS); visited[size/2+xx][size/2+yy] = 1;
            }
            
            delete d; d = NULL;
        }
        printf("Case #%d: %s\n", t, answer.c_str());
#ifdef TEST
        // Verify the answers
        int ax = 0, ay = 0;
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i]=='N') ay+=(i+1);
            else if (answer[i]=='S') ay-=(i+1);
            else if (answer[i]=='E') ax+=(i+1);
            else if (answer[i]=='W') ax-=(i+1);
            else { printf("----- invalid character found at %d -> %c -----\n", i, answer[i]); break; }
        }
        if (!(ax == X && ay == Y)) {
            printf("Wrong answer at X,Y = (%d,%d). Answer came out = (%d,%d)\n", X, Y, ax, ay); break;
        }
#endif
    }
}