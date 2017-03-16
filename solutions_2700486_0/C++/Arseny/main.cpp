#include <iostream>

using namespace std;

int N;
int X;
int Y;

const int MAX_Q = 20000;
double PNK[MAX_Q][MAX_Q];

void reset()
{
    for (int i = 0; i < MAX_Q; ++i)
        for (int j = 0; j < MAX_Q; ++j)
            PNK[i][j] = -2;
}

double pnk(int n, int k)
{
    if (k == 0) return 1.0;
    if (n < k) return 0.0;
    double p = PNK[n][k];
    if (p > -1) return p;
    p = 0.5*pnk(n-1, k-1) + 0.5*pnk(n-1, k);
    PNK[n][k] = p;
}


double solve()
{
    if (X < 0) X = -X; // the problem is symmetrical
    int L = (X+Y)/2;
    int layer = 0;
    int layer_capacity = 1;
    
    // fill-up full layers
    while (layer <= L && N >= layer_capacity) {
        N-= layer_capacity;
        layer+= 1;
        layer_capacity+= 4;
    }

    if (layer < L) return 0.0; // no chance
    if (layer > L) return 1.0; // layer L is full

    int hc = (layer_capacity-1)/2;

    if (Y == hc) return 0.0; // Y is at the top of the layer => no chance
    if (N > hc+Y) return 1.0; // layer L is full at height Y

    return pnk(N, 1+Y);
}

int main(int argc, char const *argv[])
{
    reset();

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> X >> Y;
        double chance = solve();
        cout << "Case #" << t << ": " << chance << endl;
    }
}