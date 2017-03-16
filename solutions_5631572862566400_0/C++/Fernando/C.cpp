#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int T, N;
vector<int> F;

int main()
{
    ifstream cin("C-small-attempt0.in");
    ofstream cout("C-small.out");

    cin >> T;
    for (int casenum = 1; casenum <= T; casenum++)
    {
        cin >> N;
        F.resize(N);
        for (int i = 0; i < N; i++) 
        {
            cin >> F[i];
            F[i]--;
        }
        
        int ans = 0;
        vector<int> pairs(N);
        for (int i = 0; i < N; i++)
        {
            vector<int> app(N);
            int j = i;
            int step = 0;
            while (app[j] == 0)
            {
                step++;
                app[j] = step;
                j = F[j];
            }
            if (app[j] == step - 1)
            {
                if (step - 1 > pairs[j]) pairs[j] = step-1;
            }
            else
            {
                if (app[j] == 1 && step > ans) ans = step;
            }
        }
        int alt = 0;
        for (int i = 0; i < N; i++)
            if (F[F[i]] == i)
            {
                alt += pairs[i];
            }
        if (alt > ans) ans = alt;
        
        cout << "Case #" << casenum << ": " << ans << endl;
    }
            

    return 0;
}
