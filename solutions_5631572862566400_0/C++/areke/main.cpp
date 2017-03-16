/*
 ID: areke
 PROG: cf
 LANG: C++
 */

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

int main() {

    ifstream fin("C-small-attempt0.in");
    ofstream fout("output.out");
    int tests;
    fin >> tests;
    for (int test = 0; test < tests; test++) {
        cout << test << endl;
        int n;
        fin >> n;
        int b[100];
        for (int i = 0; i < n; i++) {
            fin >> b[i];
            b[i]--;
        }
        int maxi = 0;
        int arr[11] = {0,1,2,3,4,5,6,7,8,9,10};
        do {
            
            for (int j = 2; j <= n; j++) {
                int curr = 0;
                for (int i = 0; i < j; i++) {
                    if (arr[(i-1+j)%j] == b[arr[i]] || arr[(i+1)%j] == b[arr[i]]) curr++;
                }
                //cout << j << " " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << curr << endl;
                if (j == curr) maxi = max(maxi, curr);
            }

        }
        while (next_permutation(arr, arr+n));
        fout << "Case #" << test+1 << ": " << maxi << endl;
        
    }
    
}
