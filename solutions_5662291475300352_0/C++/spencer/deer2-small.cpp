#include <bits/stdc++.h>
using namespace std;

struct Hiker
{
    int d, m;
    long double v;

    Hiker(int _d, int _m): d(_d), m(_m), v((long double)360/_m) { }
};


vector<Hiker> read_input()
{
    vector<Hiker> hikers;
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int D, H, M; cin >> D >> H >> M;
        for (int h = 0; h < H; h++)
            hikers.push_back(Hiker(D, M+h));
    }
    return hikers;
}

long double to_finish(Hiker h)
{
    long double remain = 360 - h.d;
    return remain * h.m / 360;
}

int solve(vector<Hiker> hikers)
{
    if (hikers.size() == 1) return 0;

    Hiker slow = hikers[0], fast = hikers[1];
    if (slow.m == fast.m) return 0;
    if (slow.m < fast.m) swap(slow, fast);


    // if (fast.d < slow.d)
    // {
    //     if (to_finish(fast) < to_finish(slow)) return 0;
    //     else
    //     {
    //         long double t = (slow.d - fast.d)/(fast.v - slow.v);
    //         long double meeting = slow.d + t * slow.v;
    //         slow.d = fast.d = meeting;
    //     }
    // }

    return to_finish(slow) < to_finish(fast) + fast.m ? 0 : 1;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++)
        printf("Case #%d: %d\n", t, solve(read_input()));
    return 0;
}
