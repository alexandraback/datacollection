

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


typedef unsigned long long ULL;

using namespace std;

#define geti(x) scanf("%d", &x)
#define getc(x) scanf("%c", &x)

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


int H[5][5] =
{
    {0, 0,  0,  0,  0},
    {0, 1,  2,  3,  4},
    {0, 2, -1,  4, -3},
    {0, 3, -4, -1,  2},
    {0, 4,  3, -2, -1},
};


#define MAXL 10005

int A[MAXL];

int S[MAXL];
int S4[MAXL*4];

int RS[MAXL];
int RS4[MAXL*4];

int MS[MAXL][MAXL];

vector<ULL> Front;
vector<ULL> End;

int calc(int a, int b) {
    
    int ans = H[abs(a)][abs(b)];
    if(a * b < 0)
        ans = -ans;
    return ans;
}


int sum(ULL st, ULL ed, int L, ULL X) {
    
    
    ULL n1 = st / L;
    ULL n2 = ed / L;
    ULL rst = st % L;
    ULL red = ed % L;
    if(n1 == n2) {
        return MS[rst][red];
    
    }
    if(n2 - n1 == 1) {
        
        return calc(RS[rst], S[red]);
    }
    
    ULL k = n2 - n1 - 1;
    
    
    int ans = RS[rst];
    
    int r = k % 4;
    
    if(r > 0)
        ans = calc(ans, S4[r*L-1]);

    return calc(ans, S[red]);
    
}


bool solve(int L, ULL X) {
    
    S[0] = A[0];
    for(int i=1;i<L;i++) {
        S[i] = calc(S[i-1], A[i]);
    }
    

    RS[L-1] = A[L-1];
    for(int i=L-2;i>=0;i--) {
        RS[i] = calc(A[i], RS[i+1]);
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
    
    int L4 = 4*L;
    S4[0] = A[0];
    for(int i=1;i<L4;i++) {
        S4[i] = calc(S4[i-1], A[i%L]);
    }
    
    
    RS4[L4-1] = A[L-1];
    for(int i=L4-2;i>=0;i--) {
        RS4[i] = calc(A[i%L], RS4[i+1]);
    }
    
    
    
    Front.clear();
    End.clear();

    if(X >= 4) {
        
        
        for(int i=0;i<L4;i++) {
            if(S4[i] == 2) {
                Front.push_back(i);
            }
        }
        
        for(int i=L4-1;i>=0;i--) {
            if(RS4[i] == 4) {
                End.push_back(i+X*L-L4);
            }
        }
    }
    else {
        
        int N = (int)X*L;
        for(int i=0;i<N-2;i++) {
            if(sum(0, i, L, X) == 2) {
                Front.push_back(i);
            }
        }
        
        for(int i=N-1;i>=2;i--) {
            if(sum(i, N-1, L, X) == 4) {
                End.push_back(i);
            }
        }
        
    }
    
    
    for(int i=0,ei=(int)Front.size();i<ei;i++) {
        
        for(int j=0,ej=(int)End.size();j<ej;j++) {
            
            ULL st = Front[i]+1;
            ULL ed = End[j]-1;
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

	freopen("C:\\Users\\weihaoc\\ACM\\cc.in", "r", stdin);
    freopen("C:\\Users\\weihaoc\\ACM\\cc.out", "w+", stdout);
    
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        
        int L;
        ULL X;
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

