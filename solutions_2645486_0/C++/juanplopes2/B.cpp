#include <iostream>
#include <string>
#include <cstring>
#define MAX 10010
#define ull unsigned long long
using namespace std;

int V[MAX];
int T[MAX];

int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        int e, r, n;
        cin >> e >> r >> n;
        for(int i=0; i<n; i++) {
            cin >> V[i];
            T[i] = r;
        }
        T[0] = e;
        
        r = min(r, e);
        for(int i=n-1; i>=0; i--) {
            for(int j=i-1; j>=0; j--) {      
                if (V[j] >= V[i]) break;   
                int much = min(e-T[i], T[j]);
                if (much == 0) break;
                T[j] -= much;
                T[i] += much;
            }
        }
        
        ull answer = 0;
        for(int i=0; i<n; i++) {
            //cout << " " << T[i] ;
            answer += T[i] * V[i];
        }
        //cout << endl;
        
        
        
        cout << "Case #" << cc << ": " << answer << endl;
    }
}
