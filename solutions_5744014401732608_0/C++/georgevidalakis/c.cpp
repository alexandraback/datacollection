#include <fstream>
using namespace std;

int V[48], P[50][50];

void mV(int B, int cv)
{
     if (V[cv] == B - cv - 1)
     {
         mV(B, cv - 1);
         V[cv] = V[cv - 1] + 1;
     }
     else V[cv]++;
}

void cP(int v, int B)
{
     int p = 0;
     for (int i = 0; i < v; i++) { P[p][V[i]] = 1; p = V[i]; }
     P[p][B - 1] = 1;
}

int main()
{
    ifstream fin("c.in");
    ofstream fout("c.out");
    
    int T, B, M, l, i, j, c, v, cv;
    fin >> T;
    for (unsigned int x = 1; x <= T; x++)
    {
        fout << "Case #" << x << ": ";
        fin >> B >> M;
        l = 1;
        for (i = 2; i < B; i++) l *= 2;
        if (M > l || (B >= 5 && M == l - 1)) fout << "IMPOSSIBLE\n";
        else
        {
            fout << "POSSIBLE\n";
            for (i = 0; i < B; i++) for (j = 0; j < B; j++) P[i][j] = 0;
            v = 0;
            while (M > 0)
            {
                  for (cv = 0; cv < v; cv++) V[cv] = cv + 1;
                  cP(v, B);
                  M--;
                  while (v > 0 && M > 0 && V[0] < B - v - 1)
                  {
                        mV(B, v - 1);
                        cP(v, B);
                        M--;
                  }
                  v++;
            }
            for (i = 0; i < B; i++) { for (j = 0; j < B; j++) fout << P[i][j]; fout << '\n'; }
        }
    }
    
    fin.close();
    fout.close();
    return(0);
}
