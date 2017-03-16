#include <iostream>
#include <vector>
#include <string>
using namespace std;

char f[200];

int main()
{
    freopen("a1.in", "r", stdin);
    freopen("a1.out", "w", stdout);

    string in[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                    "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    string ou[3] = {"our language is impossible to understand",
                    "there are twenty six factorial possibilities",
                    "so it is okay if you want to just give up"};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < in[i].size(); ++j)
            if (in[i][j] != ' ')
                f[in[i][j]] = ou[i][j];
    f['z'] = 'q';
    f['q'] = 'z';
    int t1, t2;
    scanf("%d\n", &t1);
    for (t2 = 1; t2 <= t1; ++t2) {
        string st;
        getline(cin, st);
        cout << "Case #" << t2 << ": ";
        for (int i = 0; i < st.size(); ++i)
            if (st[i] >= 'a' && st[i] <= 'z')
                cout << f[st[i]];
            else
                cout << st[i];
        cout << endl;
    }
    
    return 0;
}
