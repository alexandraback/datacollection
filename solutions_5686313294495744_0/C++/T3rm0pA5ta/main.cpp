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
        int n;
        cin >> n;

        map<string, int> first;
        map<string, int> second;
        vector<string> f, s;
        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            first[a]++, second[b]++;
            f.push_back(a);
            s.push_back(b);
        }

        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (first[f[i]] > 1 && second[s[i]] > 1) {
                counter++;
            
                first[f[i]]--;
                second[s[i]]--;
            }
        }
        cout << "case #" << i + 1 << ": ";
        cout << counter;
        cout << "\n";
    }
    return 0;
}
