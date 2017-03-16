/* Code Jam 2014
 * Task: Deceitful War
 * User: SmBe19 (Benjamin Schmid)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVec(vector<double>& vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    int tcn;
    cin >> tcn;
    for(int tc = 1; tc <= tcn; tc++)
    {
        int wpnts = 0;
        int dwpnts = 0;
        int n;
        cin >> n;
        vector<double> wk(n);
        vector<double> wn(n);

        for(int i = 0; i < n; i++)
            cin >> wn[i];
        for(int i = 0; i < n; i++)
            cin >> wk[i];

        sort(wn.rbegin(), wn.rend());
        sort(wk.rbegin(), wk.rend());

        int offset = 0;
        for(int i = 0; i < n; i++)
        {
            if(wn[i] > wk[offset])
                wpnts++;
            else
                offset++;
        }

        for(int aoff = 0; aoff < n; aoff++)
        {
            int apnts = 0;
            for(int i = aoff; i < n; i++)
                if(wk[i] < wn[i - aoff])
                    apnts++;
            dwpnts = max(dwpnts, apnts);
        }

        cout << "Case #" << tc << ": " << dwpnts << " " << wpnts << endl;
    }
    return 0;
}
