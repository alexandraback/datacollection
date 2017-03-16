#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define UNIQUE(x) (x).resize(distance((x).begin(),unique(all(x))))
int rev(int x) {
    int a=0;
    while(x>0) {
        a*=10;
        a+=(x%10);
        x/=10;
    }
    return a;
}
int mem[1000005];
int main() {
    int tc;
    cin>>tc;
    for (int kk=0;kk<tc;kk++) {
        int n;
        cin>>n;
        for (int i=0;i<=n;i++) mem[i]=INF;
        mem[1]=1;
        for (int i=2;i<=n;i++) {
            int r=rev(i);
            mem[i]=min(mem[i],mem[i-1]+1);
            mem[r]=min(mem[r],mem[i]+1);
        }
        printf("Case #%d: %d\n", kk+1,mem[n]);
    }
}