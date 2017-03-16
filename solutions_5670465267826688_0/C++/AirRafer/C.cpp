

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

int H[5][5] =
{
    {0, 0,  0,  0,  0},
    {0, 1,  2,  3,  4},
    {0, 2, -1,  4, -3},
    {0, 3, -4, -1,  2},
    {0, 4,  3, -2, -1},
};


#define MAXL 10005
#define MAXX 10005

int A[MAXL];

int S[MAXL];
int SX[MAXX];

int RS[MAXL];
int RSX[MAXX];

int MS[MAXL][MAXL];

vector<int> Front;
vector<int> End;

int calc(int a, int b) {
    
    int ans = H[abs(a)][abs(b)];
    if(a * b < 0)
        ans = -ans;
    return ans;
}


int sum(int st, int ed, int L, int X) {
    
    
    int n1 = st / L;
    int n2 = ed / L;
    int rst = st % L;
    int red = ed % L;
    if(n1 == n2) {
        return MS[rst][red];
    
    }
    if(n2 - n1 == 1) {
        
        return calc(RS[rst], S[red]);
    }
    
    int k = n2 - n1 - 1;
    
    
    int ans = RS[rst];
    ans = calc(ans, SX[k-1]);

    return calc(ans, S[red]);
    
}


bool solve(int L, int X) {
    
    S[0] = A[0];
    for(int i=1;i<L;i++) {
        S[i] = calc(S[i-1], A[i]);
    }
    
    SX[0] = S[L-1];
    for(int i=1;i<X;i++) {
        SX[i] = calc(SX[i-1], S[L-1]);
    }
    
    RS[L-1] = A[L-1];
    for(int i=L-2;i>=0;i--) {
        RS[i] = calc(A[i], RS[i+1]);
    }
    
    RSX[X-1] = RS[L-1];
    for(int i=X-2;i>=0;i--) {
        RSX[i] = calc(RS[0], RSX[i+1]);
    }
    
    
    for(int i=0;i<L;i++) {
        MS[i][i] = A[i];
    }
    
    for(int st=0;st<L;st++) {
        for(int l=2;st+l<=L;l++) {
            int ed = st+l-1;
            MS[st][ed] = calc(MS[st][ed-1], MS[ed][ed]);
        }
    }
    
    int N = L*X;
    
    Front.clear();
    End.clear();
    
    for(int i=0;i<N-2;i++) {
        
        int a = sum(0, i, L, X);
        if(a == 2) {
            Front.push_back(i);
        }
    }
    for(int j=2;j<N;j++) {
        int c = sum(j, N-1, L, X);
        if(c == 4) {
            End.push_back(j);
        }
    }
    
    for(int i=0,ei=(int)Front.size();i<ei;i++) {
        
        for(int j=(int)End.size()-1;j>=0;j--) {
            
            int st = Front[i]+1;
            int ed = End[j]-1;
            if(st > ed)
                break;
            
            int b = sum(st, ed, L, X);
            if( b == 3)
                return true;
        }
        
    }
    
    
    return false;
}


int main() {

	freopen("/Users/cheng/Google/ACM/env/c.in", "r", stdin);
    freopen("/Users/cheng/Google/ACM/env/c.out", "w+", stdout);
    
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        
        int L, X;
        cin >> L >> X;
        for(int i=0;i<L;i++) {
            char c;
            cin >> c;
            if(c == '1')
                A[i] = 1;
            if(c == 'i')
                A[i] = 2;
            if(c == 'j')
                A[i] = 3;
            if(c == 'k')
                A[i] = 4;
        }
        
        bool ans = solve(L, X);
        
        cout<<"Case #"<<t<<": "<< (ans ? "YES" : "NO")<<endl;
    }
    
    return 0;
}

