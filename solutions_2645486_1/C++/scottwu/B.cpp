#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

ifstream fin ("blah.in");
ofstream fout ("blah.out");

int N;
ll E, R;
ll val[10100];

int main()
{
    int T; fin >> T;
    
    for (int test = 1; test <= T; test++)
    {
        
    fin >> E >> R >> N;
    for (int i = 0; i < N; i++)
        fin >> val[i];
    
    ll ecur = E;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int next = -1;
        for (int j = i + 1; j < N; j++)
            if (val[j] > val[i])
            {
                next = j;
                break;
            }
        
        if (next == -1)
        {
            ans += ecur * val[i];
            ecur = R;
        }
        else
        {
            ll emin = max (0LL, (ll) E - R * (ll) (next - i));
            if (emin < ecur)
            {
                ans += (ecur - emin) * val[i];
                ecur = emin + R;
            }
            else
                ecur = min ((ll) E, ecur + R);
        }
    }
    
    fout << "Case #" << test << ": " << ans << "\n";
    }
    
    return 0;
}
