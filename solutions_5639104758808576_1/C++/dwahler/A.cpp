#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define D(x)

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
        int smax;
        string digits;

        cin >> smax >> digits;

        int people = 0, added = 0;

        for (int i = 0; i < digits.length(); i++) {
            const int addedHere = max(i-people, 0);
            D(cerr << "i=" << i << " addedHere=" << addedHere << " people=" << people << " added=" << added << endl);
            people += addedHere;
            added += addedHere;
            
            people += digits[i] - '0';
        }

        cout << "Case #" << testCase << ": " << added << endl;
    }
}
