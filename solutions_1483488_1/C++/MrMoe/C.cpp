#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    
    for (int t=0; t<T; t++) {
        int A, B;
        cin >> A; cin >> B;
        
        int n_pairs=0;
        
        for (int i=A; i<=B; i++) {
            char n[8];
            sprintf(n, "%d", i);
            int l = strlen(n);
            set<int> pairs;
            for (int c=1; c<l; c++) {
                char m[8];
                strncpy(m, n+c, l-c);
                strncpy(m+(l-c), n, c);
                m[l] = 0;
                if (m[0] == '0')
                    continue;
                int j = atoi(m);
                if (i >= j)
                    continue;
                if (j > B)
                    continue;
                if (pairs.find(j) != pairs.end())
                    continue;
                pairs.insert(j);
                n_pairs++;
            }
        }
        cout << "Case #"<<t+1<<": "<<n_pairs<<endl;
        
        
    }

    return 0;
}
