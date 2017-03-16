#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

const int MAX_VAL = 10;
const int MAX_SUM = 3 * MAX_VAL;

int works[MAX_SUM+1][MAX_VAL+1] = {{ 0 }};
int works_surp[MAX_SUM+1][MAX_VAL+1] = {{ 0 }};
int surp_possible[MAX_SUM+1] = { 0 };


void init_works()
{
    for (int p=0; p<=MAX_VAL; p++)
        for (int t=0; t<=MAX_SUM; t++)
            for (int a=p; a<=MAX_VAL; a++)
                for (int b=0; b<=MAX_VAL; b++)
                {   
                    int c = t - a - b;
                    if (c<0 || c>MAX_VAL) continue;

                    int ma = max(max(a,b),c);
                    int mi = min(min(a,b),c);
                    if (ma - mi < 2) works[t][p] = 1;
                    if (ma - mi == 2) 
                    {
                        works_surp[t][p] = 1;
                        surp_possible[t] = 1;
                    }
                }
}

int t[120];
int M[120][120];



bool custom_cmp(const int &a, const int &b)
{
    int atmp = a;
    int btmp = b;
    if (atmp < 2) atmp += 31;
    if (btmp < 2) btmp += 31;

    return atmp < btmp;
}

int main()
{
    init_works();

//    for (int i=0; i<=MAX_SUM; i++)
//        cout << i << " " << surp_possible[i] << " " << works_surp[i][0] << " " << works[i][0] << endl;        

    int T;
    cin >> T;
    for (int cases=1; cases<=T; cases++)
    {
        int N, S, p;
        cin >> N >> S >> p;

        for (int i=0; i<N; i++)
            cin >> t[i];

        sort(t, t+N, custom_cmp);
/*
        for (int i=0; i<N; i++)
            cout << t[i] << " ";
        cout << endl;
*/

        for (int i=0; i<120; i++)
            for (int j=0; j<120; j++)
                M[i][j] = -1;

        // $M$ depends on $p$
        M[0][0] = 0;
        for (int n=1; n<=N; n++)
            M[0][n] = M[0][n-1] + works[t[n-1]][p];

        for (int s=1; s<=S; s++)
        {
            M[s][s] = M[s-1][s-1] + works_surp[t[s-1]][p];

            for (int n=s+1; n<=N; n++)
            {
                assert(M[s][n-1] != -1);
                M[s][n] = M[s][n-1] + works[t[n-1]][p];

                assert(M[s-1][n] != -1);
                assert(M[s][n] != -1);

                if (surp_possible[t[n-1]])
                {
                        assert(M[s-1][n-1] != -1);
                    M[s][n] = max(M[s][n], M[s-1][n-1] + works_surp[t[n-1]][p]);
                }

            }
        }
        cout << "Case #" << cases << ": " << M[S][N] << endl;
    }
}
