#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <sstream>
#include <cstdio>
#include <iostream>

using namespace std;

const double EPS = 1e-11;


bool check(int id, double m, double X, vector<double>& people) {
    double mintot = people[id] + m * X;
    double small_sum = 0;

    for (int i = 0; i < people.size(); ++i) {
        if (i == id)
            continue;

        if (people[i] + EPS < mintot) {
            small_sum += (mintot - people[i]);
        }
    }

    if ((1 - m) * X + EPS < small_sum) {
        return true;
    } else {
        return false;
    }
}


int main()
{
    int N;
    int T;
    int X;
    vector<double> people;
    vector<double> answers;

    scanf("%d", &T);

    for (int test = 1; test <= T; ++test) {
        scanf("%d", &N);

        people.resize(N);
        answers.resize(N);
        X = 0;

        for (int i = 0; i < N; ++i) {
            scanf("%lf", &people[i]);
            X += people[i];
        }

        for (int i = 0; i < N; ++i) {
            int steps = 70;
            double l = 0, r = 1;
            double m, ans = -1;

            while (--steps) {
                m = (l + r) / 2;
//                printf("m = %.10lf\n", m);

                if (check(i, m, X, people)) {

                    r = m;
                    ans = m;
//                    printf("check true, l = %.10lf, r = %.10lf\n", l, r);
                } else {
                    l = m;
//                    printf("check false, l = %.10lf, r = %.10lf\n", l, r);
                }
            }

            if (ans < 0) {
                ans = l;
            }

            answers[i] = ans;
        }

        printf("Case #%d: ", test);

        for (int i = 0; i < N; ++i) {
            printf("%.9lf ", answers[i] * 100);
        }

        printf("\n");
    }

    return 0;
}
