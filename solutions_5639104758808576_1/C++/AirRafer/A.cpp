

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

#define geti(x) scanf("%d", &x)
#define getc(x) scanf("%c", &x)

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


#define MAXN 1005

int A[MAXN];
int Sum[MAXN];

char L[MAXN];

int main() {

	freopen("/Users/cheng/Google/ACM/env/aa.in", "r", stdin);
    freopen("/Users/cheng/Google/ACM/env/aa.out", "w+", stdout);
    
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        
        int Smax;
        cin >> Smax;
        
        int ans = 0;
        int sum = 0;
        
        //memset(Sum, 0, sizeof(Sum));
        
        cin >> L;
        for(int i=0;i<=Smax;i++) {
            
            int n = L[i] - '0';
            A[i] = n;
        }
        
        if(A[0] == 0) {
            A[0]++;
            ans++;
        }
        sum = A[0];
        
        for(int i=1;i<=Smax;i++) {
            
            if(sum < i) {
                int add = i-sum;
                sum += add;
                ans += add;
            }
            sum += A[i];
        }
        
        cout<<"Case #"<<t<<": "<<ans<<endl;
        
        
        
    }
    return 0;
}

