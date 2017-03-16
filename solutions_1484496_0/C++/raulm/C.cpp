#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>


using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef pair < int, int > II;

int A[100];
int D[(1<<20)+10];

int n = 0;


int main(void){

    int t = 0; cin >> t;
    
    for(int c = 1; c <= t; c++){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> A[i];
        int f = 0, s = 0;
        bool flag = false;

        for(int i = 1; i < (1<<n); i++){
            D[i] = 0;
            for(int j = 0; j < n; j++){

                if(i&(1<<j)){ D[i] += A[j]; }
            }
        }
        
        for(int i = 1; i < (1<<n); i++){
            int comp = i^((1<<n)-1);
            for(int m = comp; m > 0; m = (m-1)&comp){
                if(D[m] == D[i]){
                    flag = true;
                    f = i;
                    s = m;
                    break;
                }
            }
            if(flag) break;
        }

        cout << "Case #" << c << ":" << endl;
        if(flag){
            for(int i = 0; i < n; i++) if((1<<i)&f) cout << A[i] << " ";
            cout << endl;
            for(int i = 0; i < n; i++) if((1<<i)&s) cout << A[i] << " ";
            cout << endl;
        }else{
            cout << "Impossible" << endl;
        }
    }
    

    
    return 0;
}
