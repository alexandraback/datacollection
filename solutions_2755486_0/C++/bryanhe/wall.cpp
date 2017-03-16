#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>

#define TRIBES 11
#define ATTACKS 11

using namespace std;

class Tribe {
public:
    int64_t d;
    int64_t n;
    int64_t w;
    int64_t e;
    int64_t s;
    int64_t delta_d;
    int64_t delta_p;
    int64_t delta_s;
};

class Attack {
public:
    int tribe;
    int64_t d;
    int64_t w;
    int64_t e;
    int64_t s;

    bool operator< (const Attack o) const {
        return d < o.d;
    }
};

Tribe tribe[TRIBES];
Attack attack[TRIBES * ATTACKS];

int main()
{
    int T;
    cin >> T;
    for (int counter = 1; counter <= T; counter++) {
        int N;
        cin >> N;

        int64_t numAttacks = 0;
        for (int i = 0; i < N; i++) {
            cin >> tribe[i].d >> tribe[i].n >> tribe[i].w >> tribe[i].e >> tribe[i].s >> tribe[i].delta_d >> tribe[i].delta_p >> tribe[i].delta_s;
            numAttacks += tribe[i].n;

            tribe[i].w *= 2;
            tribe[i].e *= 2;
            tribe[i].delta_p *= 2;
        }

        numAttacks = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < tribe[i].n; j++) {
                attack[numAttacks].tribe = i;
                attack[numAttacks].d = tribe[i].d + tribe[i].delta_d * j;
                attack[numAttacks].w = tribe[i].w + tribe[i].delta_p * j;
                attack[numAttacks].e = tribe[i].e + tribe[i].delta_p * j;
                attack[numAttacks].s = tribe[i].s + tribe[i].delta_s * j;

                numAttacks++;
            }
        }

        int64_t minW = attack[0].w;
        int64_t maxE = attack[0].e;
        for (int i = 0; i < numAttacks; i++) {
            minW = min(minW, attack[i].w);
            maxE = max(maxE, attack[i].e);
        }

        int64_t *wall_temp = new int64_t[maxE - minW + 1];
        int64_t *wall = (wall_temp - minW);
        for (int i = minW; i <= maxE; i++) {
            wall[i] = 0;
        }

        sort(attack, attack + numAttacks);
        int64_t index = 0;
        int64_t successes = 0;
        while (index < numAttacks) {
            int64_t end = index;
            while (end < numAttacks && attack[index].d == attack[end].d) {
                end++;
            }

            for (int i = index; i < end; i++) {
                    //cout << "Tribe #" << attack[i].tribe << " attacked on day " << attack[i].d << " at [" << attack[i].w << ", " << attack[i].e << "] with strength " << attack[i].s << ".\n";
                for (int j = attack[i].w; j <= attack[i].e; j++) {
                    if (wall[j] < attack[i].s) {
                        //cout << "\tAttack was successful.\n";
                        successes++;
                        break;
                    }
                }
            }

            for (int i = index; i < end; i++) {
                for (int j = attack[i].w; j <= attack[i].e; j++) {
                    wall[j] = max(wall[j], attack[i].s);
                }
            }

            index = end;
        }

        delete[] wall_temp;

        cout << "Case #" << counter << ": " << successes << "\n";
    }

    return 0;
}

