#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int n,m;
        int a[100][100];
        char good1[100], good2[100];
        int todo1, todo2;
        cout << "Case #" << i << ": ";
        memset(good1, -1, sizeof(good1));
        memset(good2, -1, sizeof(good2));
        cin >> n >> m;
        todo1 = n;
        todo2 = m;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                cin >> a[j][k];
        while (todo1 && todo2) {
            int mn = 101, mnj, mnk;
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (!good1[j])
                    continue;
                for (int k = 0; k < m; k++) {
                    if (!good2[k])
                        continue;
                    if (a[j][k] < mn) {
                        mn = a[j][k];
                        mnj = j;
                        mnk = k;
                    }
                }
            }

            {
                bool okay = true;
                for (int k = 0; k < m && okay; k++)
                    if (a[mnj][k] > mn)
                        okay = false;
                if (okay) {
                    found = true;
                    good1[mnj] = 0;
                    todo1--;
                }
            }

            {
                bool okay = true;
                for (int j = 0; j < n && okay; j++)
                    if (a[j][mnk] > mn)
                        okay = false;
                if (okay) {
                    found = true;
                    good2[mnk] = 0;
                    todo2--;
                }
            }
            if (!found) {
                cout << "NO" << endl;
                break;
            }
        }
        if (!todo1 || !todo2)
            cout << "YES" << endl;
    }
    return 0;
}
