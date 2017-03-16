#include <iostream>
#include <string>

using namespace std;

// For *all* cases, draw from the top-left and
// click at the bottom-right corner
//
//-------------------------------------------------
// if spaces == 1: trivial case
// if spaces == 0: trivial case
//
// if EVEN(spaces) and spaces < 4 impossible
// if ODD(spaces) and spaces < 9 impossible
//
// if R or C == 2, ODD(M) impossible
// if R or C == 1, fill blindly
//
// Fill blindly with stars.
// If one space would be left, move a star to the next row
//
// Ex 5x4: 7 mines (13 spaces)
//
// ****
// ***.
// ....
// ....
// ...c no
//
// ****
// **..
// *...
// ....
// ...c ok
//
// If reached second to last row,
// If EVEN(spaces), fill half on each row
//
// Ex 4x4: 10 mines (6 spaces)
//
// ****
// ****
// **..
// ...c no
//
// ****
// ****
// *...
// *..c ok
//
// If reached 3rd to last row and ODD(spaces),
// Fill up to last three
// Do remainder half per last rows
// Ex 3x10: 17 mines (13 spaces)
//
// **********
// *******...
// .........c no
//
// *******...
// *****.....
// *****....c ok


#define EVEN(n) ((n)%2 == 0)
#define ODD(n) ((n)%2 == 1)

void Impossible()
{
    cout << "Impossible" << endl;
}

void PM(int M)
{
    for (int i = 0; i < M; ++i) cout << '*';
}

void PS(int S)
{
    for (int i = 0; i < S; ++i) cout << '.';
}

void DoRegularCase(int R, int C, int M)
{
    int S = R*C-M;
    int N = M; //remainder

    
    if ((EVEN(S) && S < 4) ||
        (ODD(S) && S < 9))
    {
        Impossible();
        return;
    }

    for (int row = 1; row <= R; ++row)
    {
        if (N > 0 && row >= R - 2 && ODD(S))
        {
            if (N <= C-3)
            {
                PM(N); PS(C-N);
                cout << endl;
                PS(C);
                cout << endl;
                PS(C-1);
                cout << 'c' << endl;
                return;
            }
            else
            {
                PM(C-3); PS(3);
                cout << endl;
                N -= C-3;
                PM(N/2); PS(C-N/2);
                cout << endl;
                PM(N/2); PS(C-N/2-1);
                cout << 'c' << endl;
                return;
            }
        }
        if (N > 0 && row >= R - 1) // S will be even
        {
            PM(N/2); PS(C-N/2);
            cout << endl;
            PM(N/2); PS(C-N/2-1);
            cout << 'c' << endl;
            return;
        }
        if (N >= C)
        {
            PM(C);
            cout << endl;
            N -= C;
            continue;
        }
        else
        {
            if (row == R)
            {
                PM(N);
                PS(C-N-1);
                cout << 'c' << endl;
                return;
            }
            else
            {
                if (N == C-1)
                {
                    PM(C-2); PS(2);
                    N -= C-2;
                    cout << endl;
                    continue;
                }
                else
                {
                    PM(N); PS(C-N);
                    N = 0;
                    cout << endl;
                    continue;
                }
            }
        }
    }

}

void DoREqualsOne(int C, int M)
{
    PM(M); PS(C-M-1);
    cout << 'c' << endl;
}

void DoCEqualsOne(int R, int M)
{
    for (int i = 1; i <= R; ++i)
    {
        if (i == R)
        {
            cout << 'c' << endl;
        }
        else if (i <= M)
        {
            cout << '*' << endl;
        }
        else
        {
            cout << '.' << endl;
        }
    }
}

void DoTrivialCase(int R, int C)
{
    for (int i = 1; i <= R; ++i)
    {
        if (i == R)
        {
            PM(C-1);
            cout << 'c' << endl;
        }
        else
        {
            PM(C);
            cout << endl;
        }
    }
}

main()
{
    int T;
    cin >> T;

    for (int X = 1; X <= T; ++X)
    {
        int R, C, M;
        cin >> R >> C >> M;

        cout << "Case #" << X << ":" << endl;

        if (M == R*C)
        {
            Impossible();
        }
        else if (R == 1)
        {
            DoREqualsOne(C, M);
        }
        else if (C == 1)
        {
            DoCEqualsOne(R, M);
        }
        else if (M == R*C - 1)
        {
            DoTrivialCase(R, C);
        }
        else if ((R == 2 || C == 2) && ODD(M))
        {
            Impossible();
        }
        else
        {
            DoRegularCase(R, C, M);
        }
    }
}
