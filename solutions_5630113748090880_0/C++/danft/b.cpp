#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<bool> vb;

int n, cnt[2505];

int main(void) {
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int tt=0;tt<T;tt++) {
        memset(cnt, 0, sizeof cnt);
        cin>>n;
        for(int i=0;i<2*n-1;i++)
            for(int j=0;j<n;j++) {
                int x;cin>>x;
                cnt[x]++;
            }
        vi ans;
        for(int i=1;i<=2500;i++)
            if(cnt[i]%2!=0)
                ans.pb(i);
        cout<<"Case #" << tt+1<<": ";
        for(int j=0;j<ans.size();j++)
            cout<<ans[j]<<" ";
        cout<<endl;
    }
	
	
	return 0;
}
