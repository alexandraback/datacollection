#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


int nbT;

int A,B,K;
int Abits[32], Bbits[32], Kbits[32];
int masks[32];


int main()
{
    freopen("t.in", "r", stdin);
    //freopen("t.out", "w", stdout);
    masks[0] = 1;
    for (int i = 1; i <=32; i++)
        masks[i] = masks[i-1] *2;

    cin >> nbT;
    for (int t = 1; t <= nbT; t++)
    {
        cin >> A >> B >> K;

        for (int i = 0; i <= 31; i++)
        {
            Abits[i] = (A & masks[i]) ? 1:0;
            Bbits[i] = (B & masks[i]) ? 1:0;
            Kbits[i] = (K & masks[i]) ? 1:0;
        }


        int D = min(A,B);
        int E = max(A,B);

        long long rep = 0;
        A = D;
        B = E;



        int curNb = 0;
        for (int i = 0; i < 32; i++)
            curNb += masks[i]* Kbits[i];


        for (int a=  0; a < A; a++)
            for (int b = 0; b < B; b++)
                if ((a&b) < K)
                    rep++;



        cout << "Case #" << t << ": " << rep << '\n';

    }
    return 0;
}
