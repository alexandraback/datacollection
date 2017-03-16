#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <queue>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

struct D {
    double cookies;
    double time;
    int farms;

    bool operator<(const D& o) const {
        return time > o.time;
    }
};

double calc(double c, double f, double x) {
    priority_queue<D> q;
    q.push((D){ 0, 0, 0 });
    while (!q.empty()) {
        D d = q.top(); q.pop();

        if (d.cookies >= x) return d.time;

        // farm買わない
        double time = d.time + (x - d.cookies) / (d.farms * f + 2);
        q.push((D){ x, time, d.farms });

        if (d.cookies < c) {
            double t = d.time + (c - d.cookies) / (d.farms * f + 2);
            q.push((D){ c, t, d.farms });
        }

        double cookies = d.cookies;
        int farms = d.farms;
        while (cookies >= c) {
            // famr買う
            farms++;
            cookies -= c;

            // printf("push cookis:%lf time:%lf farms:%d\n", cookies, d.time, farms);

            q.push((D){ cookies, d.time, farms });
        }
    }

    puts("ERROR: not found answer");
    assert(false);
    return 0;
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);

        printf("Case #%d: %lf\n", cc+1, calc(c, f, x));
    }

}

