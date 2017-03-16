#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

#define PRINT(var) cout << #var << " = " << var << " _________ line no : " << __LINE__ << "__________ TC : " << TC << endl;
#define PRINTin(a, in) cout << #a << "[" << in << "]" <<  " = " << a[in] << " _________ line no : " << __LINE__ << "__________ TC : " << TC << endl;

#define ForIt(i, a, b) for(i = (int)(a); i <= (int)(b); ++i)
#define ForItInt(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
int TC;
#define SMALL 1
//#define DEBUG 1


template <class X> void printArray(X a[], int len);

int done[11][11][11];
int num12[11][11];
int num13[11][11];
int num23[11][11];


void solve(fstream& fin , fstream& fout)
{
    int i, j, k;
    int J, P, S, K;
    fin >> J >> P >> S >> K;

    memset(done, 0, sizeof(done) );
    memset(num12, 0, sizeof(num12) );
    memset(num13, 0, sizeof(num13) );
    memset(num23, 0, sizeof(num23) );

    bool swap13 = false;
    bool swap23 = false;
    bool swap12 = false;


    if(J > S && J > P)//J max
        swap13 = true;

    if(swap13)
    {
        int temp = S;
        S = J;
        J= temp;
    }

    if(P > S && P > J)//J max
        swap23 = true;

    if(swap23)
    {
        int temp = S;
        S = P;
        P = temp;
    }

    if(J > S)
        swap12 = true;

    if(swap12)
    {
        int temp = J;
        J = P;
        P = temp;
    }

    int C = 0;
    ForIt(i, 1, J )
    {
        ForIt(j, 1, P )
        {
            ForIt(k, 1, S )
                if(num12[i][j] < K && num13[i][k] < K && num23[j][k] < K )
                {
                    num12[i][j]++;
                    num13[i][k]++;
                    num23[j][k]++;
                    C++;
                    done[i][j][k] = true;
                }
        }
    }

    fout << C << endl;

    ForIt(i, 1, J )
    {
        ForIt(j, 1, P )
        {
            ForIt(k, 1, S )
            {
                int one, two, three;
                one = i;
                two = j;
                three = k;
                if(swap12)
                {
                int temp = J;
                J = P;
                P = temp;
                }

                if(swap13)
                {
                int temp = J;
                J = S;
                S = temp;
                }
                if(swap23)
                {
                int temp = S;
                S = P;
                P = temp;
                }
                fout << one << " " << two << " " << three << endl;
            }
        }
    }
}


int main()
{
#ifdef DEBUG
    fstream fin("Ztest.in", ios::in);
#endif

#ifndef DEBUG
    #ifdef SMALL
        fstream fin("C-small-attempt2.in", ios::in);
    #endif
    #ifndef SMALL
        fstream fin("C-large-practice.in", ios::in);
    #endif
#endif

    fstream fout("Output.out", ios:: out);

    int T;
    fin >> T;

    ForIt( TC, 1, T )
    {
        fout << "Case #" << TC << ": ";
        solve(fin, fout);
    }

    fout.close();
    fin.close();

    return 0;
}


template <class X>
void printArray(X a[], int len)
{
    for(int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout <<  endl;
}
