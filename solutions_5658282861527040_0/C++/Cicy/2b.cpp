#include "2b.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        
        int A, B, K;
        cin >> A >> B >> K;
        
        int total = 0;
        for (int i=0; i<A; i++) {
            for (int j=0; j< B; j++) {
                if ((i&j) < K) {
                    total++;
                }
            }
        }

        cout << "Case #" << i+1 << ": "<< total << endl;
        
        
    }
    
    
}