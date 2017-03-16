#include <iostream>

using namespace std;

string t1[16], t2[16];
int fake[16];

int main()
{
    int z;
    cin >> z;
    for(int t = 1; t <= z; ++t)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> t1[i] >> t2[i];
        int maxi = 0;
        for(int i = 0; i < (1<<n); ++i)
        {
            int cp = i;
            for(int j = 0; j < n; ++j)
            {
                fake[j] = cp&1;
                cp >>= 1;
            }
            bool flag = true;
            for(int j = 0; j < n; ++j)
            {
                if(!fake[j]) continue;
                bool ok1 = false, ok2 = false;
                for(int k = 0; k < n; ++k)
                {
                    if(fake[k]) continue;
                    if(t1[k] == t1[j]) ok1 = true;
                    if(t2[k] == t2[j]) ok2 = true;
                }
                if(!ok1 || !ok2) flag = false;
            }
            if(!flag) continue;
            int ct = 0;
            for(int j = 0; j < n; ++j)
                ct += fake[j];
            maxi = max(maxi, ct);
        }
        cout << "Case #" << t << ": " << maxi << endl;
    }
    return 0;
}
