#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;

    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        int n,s,p;
        cin >> n >> s >> p;
        vector <int> t(n);
        
        for (int i=0; i<n; i++) cin >> t[i];
        sort(t.begin(), t.end(), greater <int> ());

        int cur;
        for (cur=0; cur<n && s>=0; cur++)
        {
            if (t[cur] == 0 && p != 0) break;

            if ((t[cur]/3 + bool(t[cur]%3)) >= p) continue;
            else if (t[cur]/3 + max(1, t[cur]%3) == p && s) s--;
            else break;
        }
        cout << cur << endl;
    }
    return 0;
}
