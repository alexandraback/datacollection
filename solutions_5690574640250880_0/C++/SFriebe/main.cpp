#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory.h>

using namespace std;

ifstream in;
ofstream out;


/*

Possible cases:
- There is just one "no mine" field
- The clicked field is a 0 and...
  - the area at least
    ***
    *..
    *.c


Impossible:
 ****
 **..
 *..c

 Conclusion:
 - All "corridors" (shown lines/columns) have to be at least 2 field if on the border or 3 fields in the middle


Generator:
- Return "Impossble" if R*C - M is less than 4 and not 1 and it is no 1xC / Rx1 field
- Fill the field with mines
- Set the empty-counter to R*C - M
- Place the click in the lower right corner
- If there can be at least 2 empty lines at the bottom, leave them empty and substract their field count
- Try to leave as much lines as possible empty, starting from the bottom


*/

/// "Does" the click given in the last two coordinates
// CC = Column-Cursor
void resolve(char **field, const int C, const int R, const int CC, const int RC)
{
    //cout << "Resolving " << CC << ":" << RC << "\n";

    if (CC >= C || CC < 0 || RC >= R || RC < 0 || field[CC][RC] != '.')
        return;
    // Count mines around click position
    char sum = '0';
    if (CC > 0 && field[CC-1][RC] == '*')
        sum++;
    if (CC < C-1 && field[CC+1][RC] == '*')
        sum++;
    for (int c = CC-1; c <= CC+1 && RC > 0; c++)
        if (c >= 0 && c <= C-1 && field[c][RC - 1] == '*')
            sum++;
    for (int c = CC-1; c <= CC+1 && RC < R-1; c++)
        if (c >= 0 && c <= C-1 && field[c][RC + 1] == '*')
            sum++;
    field[CC][RC] = sum;

    // If 0, continue
    if (sum == '0')
    {
        resolve(field, C, R, CC-1, RC);
        resolve(field, C, R, CC+1, RC);
        for (int c = CC-1; c <= CC+1 && RC > 0; c++)
            resolve(field, C, R, c, RC-1);
        for (int c = CC-1; c <= CC+1 && RC < R-1; c++)
            resolve(field, C, R, c, RC+1);
    }
}

/// Checks if the field is valid
bool check(char **fieldIn, const int C, const int R)
{

    char **field = new char*[C];
    // Fill with mines
    for (int x = 0; x < C; x++)
        field[x] = new char[R];

    for (int x = 0; x < C; x++)
        for (int y = 0; y < R; y++)
            field[x][y] = fieldIn[x][y];
    field[C-1][R-1] = '.';

    // Resolve the click
    resolve(field, C, R, C-1, R-1);


    // Check if there are any '.' left
    for (int x = 0; x < C; x++)
        for (int y = 0; y < R; y++)
            if (field[x][y] == '.')
            {
//*
    cout << "==================\n";
    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cout << (char)field[x][y];
        }
        cout << "\n";
    }
    cout << "==================\n";
//*/

                for (int x = 0; x < C; x++)
                    delete [] field[x];
                delete [] field;
                return false;
            }

    for (int x = 0; x < C; x++)
        delete [] field[x];
    delete [] field;

    return true;
}


/// Reads a line from the input and creates a field
void run_case()
{
    int M, R, C;
    in >> R >> C >> M;
    int F = R*C - M;

    cout << "Field of " << C << "x" << R << " with " << M << " mines and " << F << " free places.\n";

    // Check if possible
    // Okay, this list is not complete. So I added a check at the end
    // I admit: I am pretending that my clearing-algorithm is optimal
    if (F < 4 && F != 1 && R != 1 && C != 1 && F < C * 2)
    {
        cout << "Failed Pre-Check\n";
        cout << "Impossible\n";
        out << "Impossible\n";
        return;
    }

    // Special-case: Strips
    // Vertically:
    if (C == 1 && R > 1)
    {
        cout << "Vertically\n";
        R -= M;
        for (; M > 0; M--)
        {
            cout << "*\n";
            out << "*\n";
        }
        for (; R > 1; R--)
        {
            cout << ".\n";
            out << ".\n";
        }
        cout << "c\n";
        out << "c\n";
        return;
    }
    // Horizontal:
    if (R == 1 && C > 1)
    {
        cout << "Horizontal\n";
        C -= M;
        for (; M > 0; M--)
        {
            cout << "*";
            out << "*";
        }
        for (; C > 1; C--)
        {
            cout << ".";
            out << ".";
        }
        cout << "c\n";
        out << "c\n";
        return;
    }


    // Create a field
    char **field = new char*[C];
    // Fill with mines
    for (int x = 0; x < C; x++)
    {
        field[x] = new char[R];
        memset(field[x], '*', R);
    }

    // Start clearing
    // Create empty 2x2 in corner
    field[C-1][R-1] = 'c';
    F--;
    if (C > 1 && F > 0)
    {
        field[C-2][R-1] = '.';
        F--;
    }
    if (R > 1 && F > 0)
    {
        field[C-1][R-2] = '.';
        F--;
    }
    if (C > 1 && R > 1 && F > 0)
    {
        field[C-2][R-2] = '.';
        F--;
    }

    if (F == 1)
    {
        cout << "F != 1 failed\n";
        cout << "Impossible\n";
        out << "Impossible\n";
        return;
    }

    // Run a 2-level-way to the left
    for (int x = C - 3; x >= 0 && (F == 2 || F > 3); x--)
    {
        field[x][R - 1] = '.';
        F--;
        if (R > 1)
        {
            field[x][R - 2] = '.';
            F--;
        }
    }

    // Now every new line is "safe" and can be added without problems
    for (int y = R - 3; y >= 0; y--)
    {
        for (int x = C - 1; x >= 0 && F > 0 && !(x == 0 && F == 2); x--)
        {
            field[x][y] = '.';
            F--;
        }
    }

    if (F != 0)
    {
        cout << "F != 0 failed\n";
        cout << "Impossible\n";
        out << "Impossible\n";
        return;
    }

    if (!check(field, C, R))
    {
        cout << "Check failed\n";
        cout << "Impossible\n";
        out << "Impossible\n";
        return;
    }

    // Print out the result
    cout << "Modified field of " << C << "x" << R << " with " << M << " mines and " << F << " free places.\n";
    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cout << (char)field[x][y];
            out << (char)field[x][y];
        }
        cout << "\n";
        out << "\n";
    }

    for (int x = 0; x < C; x++)
        delete [] field[x];
    delete [] field;
}

int main()
{
    int n_cases = 0;
    int n_case  = 0;

    //in.open("C-small-attempt_sample.in");
    in.open("C-small-attempt4.in");
    //in.open("C-large.in");

    if (!in.is_open() || !in.good())
    {
        cerr << "Could not open input file!\n";
        return 1;
    }

    out.open("output.txt", ofstream::trunc);

    if (!out.is_open() || !out.good())
    {
        cerr << "Could not open output file!\n";
        return 2;
    }

    // Set precision
    out.precision(12);

    in >> n_cases;

    for (n_case = 1; n_case <= n_cases; n_case++)
    {
        cout << "\nCase #" << n_case << ":\n";
        out << "Case #" << n_case << ":\n";
        run_case();
    }

    in.close();

    return 0;
}
