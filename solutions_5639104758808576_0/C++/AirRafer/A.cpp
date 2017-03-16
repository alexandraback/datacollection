

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

//int P[];
//int find_ds(int x) {
//   return ((P[x] == x) ? x : (P[x] = find_ds(P[x])));
//}

int dx8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[] = {-1, -1, -1, 0, 1, 1, 1, 0};


int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, -1, 0, 1};

int dxB[] = {-1, 1, 1, -1};
int dyB[] = {-1, -1, 1, 1};


int dxK[] = {-1,  1,  2, 2, 1, -1, -2, -2};
int dyK[] = {-2, -2, -1, 1, 2,  2,  1, -1};

#define MAXN 1005

int A[MAXN];
int Sum[MAXN];

char L[MAXN];

int main() {

	freopen("/Users/cheng/Google/ACM/env/a.in", "r", stdin);
    freopen("/Users/cheng/Google/ACM/env/a.out", "w+", stdout);
    
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

