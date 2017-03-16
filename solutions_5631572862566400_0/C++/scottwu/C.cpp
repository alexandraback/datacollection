#include <iostream>
#include <fstream>

using namespace std;
const int MAXN = 1010;

ifstream fin ("A.in");
ofstream fout ("C.txt");

int N;
int bff[MAXN];
int nlen[MAXN];
int ans;

bool cool (int x)
{
    return bff[bff[x]] == x;
}

void run (int x)
{
    int cdist = 0;
    int ox = x;
    while (!cool (x) && cdist < 1100)
    {
        cdist++;
        x = bff[x];
        
        if (x == ox)
        {
            ans = max (ans, cdist);
            break;
        }
    }
    
    if (cool (x))
        nlen[x] = max (nlen[x], cdist);
}

int main()
{
    int T; fin >> T;
    for (int test = 1; test <= T; test++)
    {
    fout << "Case #" << test << ": ";
    
    ans = 0;
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        nlen[i] = 0;
        fin >> bff[i];
        bff[i]--;
    }
    
    for (int i = 0; i < N; i++)
        run (i);
    
    int res = 0;
    for (int i = 0; i < N; i++)
        if (cool (i))
            res += nlen[i] + 1;
    fout << max (res, ans) << "\n";
    
    }
}
