#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int n;
map<int, int> M;

int main() {
    int tests; cin >> tests;
    for(int test=1; test<=tests; test++) {
        cin >> n;
        M = map<int, int>();
        for(int i=0; i<n*2-1; i++) {
            for(int j=0; j<n; j++) {
                int temp; cin >> temp; M[temp]++;
            }
        }


        cout << "Case #" << test << ":";
        for(int i=0; i<6000; i++) {
            if(M[i]%2 == 1) {
                cout << " " << i;
            }
        }
        cout << endl;
    }
}
