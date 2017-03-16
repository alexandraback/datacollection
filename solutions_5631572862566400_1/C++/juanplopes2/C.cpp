#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int B[100];
int P[100];

int main() {
    int tests; cin >> tests;
    for(int test=1; test<=tests; test++) {
        int n; cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> B[i];
        }
        
        int maxx = 0;
        for(int i=0; i<(1<<n); i++) {
            int x = i;
            int w = 1;
            int count = 0; 
            
            while(x) {
                if (x&1)
                   P[count++] = w;
                x>>=1;
                w++;
            }

            if (count <= maxx) continue;

/*            cout <<  " * " << count;
            for(int j=0; j<count; j++) {
                cout << " " << P[j];
            }
            cout << endl;*/

            while(next_permutation(P, P+count)) {
                bool ok = true;
                for(int j=0; j<count; j++) {
                    int bff = B[P[j]];
                    int left = j > 0 ? P[j-1] : P[count-1];
                    int right = j < count-1 ? P[j+1] : P[0];
                    
                    if (bff != left && bff != right) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    maxx = max(maxx, count);
                    break;
                }
            }

        }
        
        cout << "Case #" << test << ": " << maxx << endl;
    }
}
