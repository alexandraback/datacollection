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

int n;
vector<double> A,B;

int ries1() {
    For(i,n+1) {
        bool t=true;
        for(int j=i; j<n; j++) if(A[j]<B[j-i]) t=false;
        if(t) return n-i;
    }
    return 0;
}

int ries2() {
    int res=0;
    set<double> S;
    For(i,B.size()) S.insert(B[i]);
    For(i,A.size()) {
        if(S.upper_bound(A[i])==S.end()) {res++; S.erase(S.begin());}
        else S.erase(S.upper_bound(A[i]));
    }
    return res;
}

void solve(int num) {
    scanf("%d",&n);
    A.clear(); B.clear();
    For(i,n) {
        double x;
        scanf(" %lf",&x);
        A.push_back(x);
    }
    sort(A.begin(),A.end());
    For(i,n) {
        double x;
        scanf(" %lf",&x);
        B.push_back(x);
    }
    sort(B.begin(),B.end());
    //For(i,A.size()) printf("%lf ",A[i]); printf("\n");
    //For(i,B.size()) printf("%lf ",B[i]); printf("\n");
    int res1=ries1(),res2=ries2();
    printf("Case #%d: %d %d\n",num,res1,res2);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
