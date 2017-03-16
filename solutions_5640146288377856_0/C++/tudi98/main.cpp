#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input");
    ofstream fout("output");

    int T;
    fin >> T;
    for(int t = 1; t <= T; t++) {
        int Ans,R,C,W;
        fin >> R >> C >> W;
        Ans = C/W*(R-1);
        Ans += C/W-1;
        C = C - Ans*W;
        if(C%W == 0) Ans += W;
        else Ans += W+1;
        fout << "Case #" << t << ": " << Ans << "\n";
    }

}
