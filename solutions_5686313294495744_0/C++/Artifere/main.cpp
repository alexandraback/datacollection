#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <string>
#include <map>

using namespace std;

int nbDiff;


int w1[1000], w2[1000];
int N;

bool seen1[4000], seen2[4000];
bool used1[4000], used2[4000];

int curNbFake;

int best;

void tryAll(int pos)
{
    if (pos == N)
    {
        for (int i = 0; i < nbDiff; i++)
        {
            if ((used1[i] && !seen1[i]) || (used2[i] && !seen2[i]))
                return;
        }

        best = max(best, curNbFake);
        return;
    }

    int u1 = w1[pos];
    int u2 = w2[pos];
    bool prevS1 = seen1[u1], prevS2 = seen2[u2];
    bool prevU1 = used1[u1], prevU2 = used2[u2];

    //cout << "take nb " << pos << " ==> " << u1 << " and " << u2 << endl;
    curNbFake++;
    used1[u1] = true;
    used2[u2] = true;
    tryAll(pos+1);

    curNbFake--;
    used1[u1] = prevU1;
    used2[u2] = prevU2;

    //cout << "see nb " << pos << " ==> " << u1 << " and " << u2 <<endl;
    seen1[u1] = true;
    seen2[u2] = true;
    tryAll(pos+1);
    seen1[u1] = prevS1;
    seen2[u2] = prevS2;

}

int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);


    int nbT;
    cin >> nbT;



    for (int t = 1; t <= nbT; t++)
    {
        nbDiff = 0;
        curNbFake = 0;
        cin >> N;
        map<string, int> corres;
        best = 0;

        for (int i = 0; i < N; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (corres.find(s1) == corres.end())
            {
                corres[s1] = nbDiff;
                nbDiff++;
            }

            if (corres.find(s2) == corres.end())
            {
                corres[s2] = nbDiff;
                nbDiff++;
            }


            w1[i] = corres[s1];
            w2[i] = corres[s2];
        }
        for (int i = 0; i < nbDiff; i++)
        {
            used1[i] = false;
            used2[i] = false;
            seen1[i] = false;
            seen2[i] = false;
        }

        tryAll(0);

        cout << "Case #" << t << ": " << best << '\n';
    }


    return 0;
}
