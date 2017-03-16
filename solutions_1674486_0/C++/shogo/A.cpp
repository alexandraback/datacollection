#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 10000;

int N;
int map[2000][2000];
int supers[2000];

bool inherit(int A) {
    if(supers[A]>0) return true;
    supers[A]++;
    for(int i=1;i<=N;++i) {
        if(map[A][i]<INF && inherit(i)) return true;
    }
    return false;
}

bool solve()
{
    cin >> N;
    fill(map[0], map[0]+2000*2000, INF);
    for(int X=1;X<=N;++X) {
        int M;
        cin >> M;
        for(int i=0;i<M;++i) {
            int Y;
            cin >> Y;
            map[X][Y] = 1;
        }
    }

    for(int X=1;X<=N;++X) {
        fill(supers, supers+2000, 0);
        if(inherit(X)) return true;
    }
    return false;
}

int main(void)
{
    int T;
    cin >> T;
    for(int no=1; no<=T; ++no) {
        if(solve()) {
            cout << "Case #" << no << ": Yes" << endl;
        } else {
            cout << "Case #" << no << ": No" << endl;
        }
    }
    return 0;
}
