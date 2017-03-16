#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        vector<int> v(26, 0);
        vector<int> cnt(10, 0);
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++)
        {
            v[s[j] - 'A']++;
        }
        cnt[0] = v['Z'-'A'];
        v['E'-'A'] -= cnt[0];
        v['R'-'A'] -= cnt[0];
        v['O'-'A'] -= cnt[0];
        v['Z' - 'A'] = 0;
        cnt[2] = v['W' - 'A'];
        v['T'-'A'] -= cnt[2];
        v['O'-'A'] -= cnt[2];
        v['W'-'A'] = 0;
        cnt[4] = v['U'-'A'];
        v['F'-'A'] -= cnt[4];
        v['O'-'A'] -= cnt[4];
        v['R'-'A'] -= cnt[4];
        v['U'-'A'] = 0;
        cnt[5] = v['F'-'A'];
        v['I'-'A'] -= cnt[5];
        v['V'-'A'] -= cnt[5];
        v['E'-'A'] -= cnt[5];
        v['F'-'A'] = 0;
        cnt[6] = v['X' - 'A'];
        v['S' - 'A'] -= cnt[6];
        v['I'-'A'] -= cnt[6];
        cnt[7] = v['S'-'A'];
        cnt[8] = v['G'-'A'];
        v['I'-'A'] -= cnt[8];
        v['H'-'A'] -= cnt[8];
        cnt[3] = v['H'-'A'];
        cnt[9] = v['I'-'A'];
        cnt[1] = v['O'-'A'];
        cout << "Case #" << i << ": ";
        for(int i=0; i<10; i++)
            for(int j=0; j<cnt[i]; j++)
                cout<<i;
        cout << endl;
    }
    return 0;
}
