#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;


int main() {
    int T;
    cin >> T;
    
    for (int t=0; t<T; t++) {
        int N;
        cin >> N;
        int Ns[N];
        for (int n=0; n<N; n++)
            cin >> Ns[n];
        
        int NN = 1<<N;
        int sum[NN];
        
        for (int i=1; i<NN; i++) {
            int k=0;
            int s=0;
            int j=i;
            while (j) {
                if (j&1)
                    s += Ns[k];
                j = j >> 1;
                k++;
            }
            sum[i] = s;
            int l;
            for (l=0; l<i; l++) {
                if (sum[l] == s)
                    break;
            }
            if (l==i)
                continue;
                
            cout << "Case #" << t+1 << ":" << endl;
            j=l;
            k=0;
            bool out=false;
            while (j) {
                if (j&1) {
                    if (out)
                        cout << " " << Ns[k];
                    else {
                        cout << Ns[k];
                        out = true;
                    }
                }
                j = j >> 1;
                k++;
            }
            cout << endl;
            j=i;
            k=0;
            out=false;
            while (j) {
                if (j&1) {
                    if (out)
                        cout << " " << Ns[k];
                    else {
                        cout << Ns[k];
                        out = true;
                    }
                }
                j = j >> 1;
                k++;
            }
            cout << endl;
            break;
        }
    
    }

    return 0;
}
