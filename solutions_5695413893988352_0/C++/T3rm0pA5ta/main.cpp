#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <cmath>

using namespace std;


int main()
{
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int dif = INT32_MAX;

        int besti = 0, bestj = 0;

        int limit1 = pow(10, s1.size());
        for (int i = 0; i < limit1; i++) {
            
            stringstream ss;
            ss << setfill('0') << setw(s1.size())  << i;
            string a= ss.str();
            bool fail = false;
            for (int j = 0; j < s1.size(); j++)
            {
                if (s1[j] != '?' && s1[j] != a[j]) {
                    fail = true;
                }
            }

            if (fail)
                continue;

            int limit2 = pow(10, s2.size());
            for (int j = 0; j < limit2; j++) {
                stringstream ss;
                ss  << setfill('0') << setw(s2.size()) << j;
                string b = ss.str();

                fail = false;
                for (int k = 0; k < s2.size(); k++)
                {
                    if (s2[k] != '?' && s2[k] != b[k])
                        fail = true;
                }
                if (fail)
                    continue;

    
                if (dif > abs(i - j)) {
                    besti = i;
                    bestj = j;
                    dif = abs(i - j);
                }
            }
        }

        cout << "case #" << i + 1 << ": ";
        cout << setfill('0') << setw(s1.size()) << besti << " " << setfill('0') << setw(s2.size()) <<bestj;
        cout << "\n";
    }
    return 0;
}
