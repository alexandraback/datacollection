#include <bits/stdc++.h>
using namespace std;
#define FREP(b) for(int i=0;i<b;i++)
#define REP(a,b,c) for(int a=b;a<c;a++)
#define asd(x) cout << "Here for " << #x << " :" <<x << endl;
#define asdf(x, y)  cout << "Here FOR " << #x << " :" << x << " " << #y  << " :" << y << endl;
typedef pair<int,int> ii;
typedef long long LL;
int solve(){
    int A,B,K;
    int ans = 0;
    cin >> A >> B >> K;
    REP(a,0,A) REP(b,0,B){
        if((a & b) < K) ans ++;
    }
    return ans;
}
int main()
{
    int test;
    cin >> test;
    REP(t,0,test){
        printf("Case #%d: %d\n",t+1,solve());
    }
    return 0;
}

