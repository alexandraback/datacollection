#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    for (int k=0; k < tests; k++) {
        int p,d,v;
        cin >> p;
        cin >> d;
        cin >> v;
        int result = 0;
        //cout << "ok";
        vector<int> nums (d);
        bool tab [v+1] = {false};
        for (int i=0; i < d; i++) {
            cin >> nums[i];
            tab[nums[i]] = true;
        }
        while (true) {
             bool sums[v+1] = {false};
            int numSums[v+1];
            for (int i=0; i <= v; i++) {
                numSums[i] = 0;
            }

            for (int i=0; i < (1 << d); i++) {
                int c = i;
                int con = 0;
                int sum = 0;
                while ( c > 0) {
                    if ( c %2 == 1) {
                        sum += nums[con];
                    }
                    ++con;
                     c = c/2;
                }
                if ( sum <= v) {
                    sums[sum] = true;
                }
            }

            int toFind = 0;

            for (int i=0; i <= v; i++) {
                if (sums[i]) {
                    for (int j = i +1; j <= v; j++) {
                        if (!tab[j-i]) {
                            numSums[j-i] += 1;
                            //cout << numSums[j-i] << endl;
                        }
                    }
                }
                else
                    toFind++;
            }

            if ( toFind == 0) {
                break;
            }

            int max1= 0;
            int maxInd = -1;
            int max2= 0;
        //cout << "//" << endl;
            for (int i=0; i <= v; i++) {
            //cout << numSums[i] << endl;
                if (numSums[i] >= max1 && numSums[i] > 0) {
                    max1 = numSums[i];
                    maxInd = i;
                    max2 = max1;

                }
            }
            //cout << "//" << endl;


            if ( max1 <= 0) {
                break;
            }

            result += 1;
            nums.push_back(maxInd);
            tab[maxInd] = true;
            d = d+1;

        }

        cout << "Case #" << k+1 << ": " << result << endl;
    }

    return 0;
}
