#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const LL INF = 2e18;
string A, B;
string ansA, ansB;
LL ans;
LL C[19];
LL toLL(string &a,string &b, int n) {
    LL res = 0;
    for(int j = 0; j < n; j++) {
        if(a[j]!='?'&&b[j]!='?') res += C[n - j - 1] * (a[j] - '0');
    }
    return res;
}
void dfs(int x, int y) {
    LL a = toLL(A,B,y + 1), b = toLL(B,A, y + 1);
    //if(x>y) printf("a = %lld b = %lld\n",a,b);
    LL t = abs(a - b) - C[y - x + 1];
    if(x > 0 && t >= ans) return;
    if(x > y) {
        if(abs(a - b) < ans) {
            ans = abs(a - b);
            ansA = A; ansB = B;
        }
        return;
    }
    if(A[x] == '?' && B[x] == '?') {
        A[x] = '0'; B[x] = '0';
        dfs(x + 1, y);
        if(a > b) {
            A[x] = '0'; B[x] = '1';
            dfs(x + 1, y);
            A[x] = '0'; B[x] = '9';
            dfs(x + 1, y);
        }
        if(a < b) {
            //if(x==0) printf("1111\n");
            A[x] = '1'; B[x] = '0';
            dfs(x + 1, y);
            A[x] = '9'; B[x] = '0';
            dfs(x + 1, y);
        }
        A[x] = B[x] = '?';
    }
    if(A[x] == '?' && B[x] != '?') {
        //if(x==1) printf("%lld %lld\n",a,b);
        if(a > b) {
            A[x] = '0';
            dfs(x + 1, y);
            if(B[x] - 1 > '0') {
                A[x] = B[x] - 1;
                dfs(x + 1, y);
            }
        }

        A[x] = B[x];
        dfs(x + 1, y);
        if(a < b) {
            if(B[x] + 1 < '9') {
                A[x] = B[x] + 1;
                dfs(x + 1, y);
            }
            A[x] = '9';
            dfs(x + 1, y);
        }
        A[x] = '?';
    }
    if(A[x] != '?' && B[x] == '?') {
        if(b > a) {
            B[x] = '0';
            dfs(x + 1, y);
            if(A[x] - 1 > '0') {
                B[x] = A[x] - 1;
                dfs(x + 1, y);
            }
        }
        B[x] = A[x];
        dfs(x + 1, y);
        if(b < a) {
            if(A[x] + 1 < '9') {
                B[x] = A[x] + 1;
                dfs(x + 1, y);
            }
            B[x] = '9';
            dfs(x + 1, y);
        }
        B[x] = '?';
    }
    if(A[x] != '?' && B[x] != '?') dfs(x + 1, y);
}
int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    C[0] = 1;
    for(int j = 1; j <= 18; j++) C[j] = C[j - 1] * 10;
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        cin >> A >> B;
        int n = A.size();
        ans = INF;
        dfs(0, n - 1);
        printf("Case #%d: ", cas++);
        //cout<<A<<" "<<B<<" ";
        cout << ansA << " " << ansB << endl;
    }
    return 0;
}
