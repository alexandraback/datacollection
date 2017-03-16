#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;

int K, C, S;

ll KP[101];

ll kpow(int e)
{
    if (KP[e] != 0)
        return KP[e];
    else if (e == 0)
        return KP[e] = 1;
    else
        return KP[e] = K*kpow(e-1);
}

ll st(int start, int l)
{
   // cout << l << " digits starting from " << start << endl;
    ll res = 0;
    for (int i = 0; i < l; i++)
    {
        //cout << "level " << i << ", digit " << start+i << endl;
        if (start + i >= K)
            break;
        res += kpow(i)*(start+i);
      //  cout << "res so far: " << res << endl;
    }
    return res;
}

int main()
{
    string file;
    cin >> file;
    ifstream in(file);
    ofstream out(file.append("-out.txt"));
    int T;
    in >> T;
    for (int t = 1; t <= T; t++)
    {
        for (int i = 0; i <= 100; i++)
            KP[i] = 0;
        in >> K >> C >> S;
        if (S*C < K)
        {
            out << "Case #" << t << ": IMPOSSIBLE" << endl;
            continue;
        }
        out << "Case #" << t << ": ";
        for (int s = 0; s < K; s += C)
        {
            out << st(s, C)+1 << " ";
        }
        out << endl;
    }
}
