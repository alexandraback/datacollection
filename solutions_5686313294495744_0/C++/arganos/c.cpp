#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;

string s[20][2];


bool possible(int j) {
    for (int i = 0; i < n; i++) {
        if (j & (1<<i)) {
            //cout << i << endl;
            int ok1 = false, ok2 = false;
            for (int k = 0; k < n; k++) {
                //cout << s[k][0] << " " << s[i][0] <<" " <<endl;
                if (!(j & (1<<k)) && (s[k][0] == s[i][0]))
                    ok1 = true;
            }
            //cout << ok1 << endl;
             for (int k = 0; k < n; k++)
                if (!(j & (1<<k)) && s[k][1] == s[i][1])
                    ok2 = true;
            if (ok1*ok2 == 0)
                return false;
        }  
    }
    return true;
}

int su(int j) {
    int sm = 0;

    while (j > 0) {
        sm += j%2;
        j /= 2;
    }
    return sm;
}

int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #"<<i<<": ";
        
        cin >> n;
        

        
        for (int j = 0; j < n; j++)
            cin >> s[j][0] >> s[j][1];
           
            
        int l = 0;
        for (int j = 0; j <= (1<<n)-1; j++) { 
       //     cout << j << " ";
            if (possible(j)) {
                l = max(su(j), l);
         //       cout << "fu";
            }
          //  cout << endl;
                  
        }
        cout << l<<endl;
    }

    return 0;
}
