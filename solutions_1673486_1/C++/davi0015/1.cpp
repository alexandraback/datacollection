/*
ID: dhxav
PROG: password_problem
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)

int main() {
    ifstream fin ("A-large.in");
    ofstream fout ("A-large.out");
    int T;
    fin >> T;

    forn (i,T)
    {
         int A, B;
         fin >> A >> B;

         vector <double> p(A);
         vector <double> ptrue(A);
         forn (i,A)
         {
             fin >> p[i];
             if (i>0) ptrue[i] = ptrue[i-1]*p[i];
             else ptrue[i] = p[i];
         }

         double best = 300000;
         fornd (i, A)
         {
             if (B-A+2*(A-i-1)+1 + (1-ptrue[i])*(B+1)<best) best = B-A+2*(A-i-1)+1 + (1-ptrue[i])*(B+1);
         }

         if (best>B+2) best = B+2;

         fout << "Case #" << i+1 << ": " << setprecision (6) << best << endl;
    }

    system("PAUSE");
}


