#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
using namespace std;
const int N = 51, M = 2501;
int D[N][N];
bool DP[M];
main(){
    ios_base::sync_with_stdio(false);
    int t,n,a;
    cin>>t;
    Fl(_,1,t+1){
        cin>>n;
        F(2*n-1)Fi(j,n)cin>>a,DP[a] = !DP[a];
        vector<int> ans;
        F(M)if(DP[i])ans.push_back(i), DP[i] = 0;
        sort(ans.begin(),ans.end());
        cout<<"Case #"<<_<<":";
        F(n)cout<<' '<<ans[i];cout<<endl;
    }
}