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

const int MAXN = 1000;

long long int A[MAXN];
double O[MAXN];

int main(void){
    int t = 0; cin >> t;
    
    for(int c = 1; c <= t; c++){
    
        int n = 0; cin >> n;
        double x = 0;
        for(int i = 0; i < n; i++){
            cin >> A[i];
            x += A[i];
        }
         
        int count = 0;      
        for(int i = 0; i < n; i++){
            if(A[i] >= 2.*x/n){
                count++;
                O[i] = 0;
            }
        }

        count = n-count;
        double x2 = 0;
        for(int j = 0; j < n; j++) if(A[j] < 2.*x/n) x2 += A[j]; 

        for(int i = 0; i < n; i++){
            double r = x+x2;
            if(!(A[i] >= 2.*x/n)){
                r /= count;
                r -= A[i];
                if(r < 0) r = 0;
                r /= x;
                O[i] = r;
            }
        }

        cout << "Case #" << c << ": ";
        for(int i = 0; i < n; i++) printf("%.7lf ",100.*O[i]);
        cout << endl;
    
    }
    
    return 0;
}
