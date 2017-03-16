#include <fstream>
using namespace std;

int main()
{
    ifstream fin("c.in");
    ofstream fout("c.out");
    
    int T, J, P, S, K, j, p, s, JP[10][10], JS[10][10], PS[10][10], c;
    bool JPS[10][10][10];
    fin >> T;
    for (unsigned int x = 1; x <= T; x++)
    {
        c = 0;
        fin >> J >> P >> S >> K;
        for (j = 0; j < S; j++) for (p = 0; p < S; p++)
        {
            JP[j][p] = 0;
            JS[j][p] = 0;
            PS[j][p] = 0;
        }
        for (j = 0; j < S; j++) for (p = 0; p < S; p++) for (s = 0; s < S; s++) JPS[j][p][s] = false;
        for (j = 0; j < J; j++) for (p = 0; p < P; p++) for (s = 0; s < S; s++)
        {
            if (JP[j][p] < K && JS[j][s] < K && PS[p][s] < K)
            {
                JP[j][p]++;
                JS[j][s]++;
                PS[p][s]++;
                JPS[j][p][s] = true;
                c++;
            }
        }
        fout << "Case #" << x << ": " << c << '\n';
        for (j = 0; j < S; j++) for (p = 0; p < S; p++) for (s = 0; s < S; s++) if (JPS[j][p][s]) fout << j + 1 << ' ' << p + 1 << ' ' << s + 1 << '\n';
    }
    
    fin.close();
    fout.close();
    return(0);
}
