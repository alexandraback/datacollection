#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

void solve(int por) {
    int n;
    scanf(" %d",&n);
    char C[100],D[100];
    vector<string> A,B;
    For(i,n) {
        scanf(" %s %s",C,D);
        string s1=C,s2=D;
        A.push_back(s1); B.push_back(s2);
    }
    set<string> F,S;
    int res=0;
    For(i,1<<n) {
        F.clear(); S.clear();
        int poc=n;
        For(j,n) {
            if(i&(1<<j)) {
                poc--;
                F.insert(A[j]); S.insert(B[j]);
            }
        }
        bool t=true;
        For(j,n) {
            if((i&(1<<j)) == 0) {
                if(F.find(A[j])==F.end() || S.find(B[j])==S.end()) t=false;
            }
        }
        if(t) res=max(res,poc);
    }
    printf("Case #%d: %d\n",por,res);
}

int main() {
    int n;
    scanf("%d",&n);
    For(i,n) solve(i+1);
}
