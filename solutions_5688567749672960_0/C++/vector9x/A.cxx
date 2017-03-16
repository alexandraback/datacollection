#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
#define ALL(v) (v).begin(),(v).end()
#define DBG(x) cerr<<__LINE__<<": " #x " = "<<x<<endl
#define endl '\n'
using namespace std;
const int LIMIT=1000000+1;
int ans[LIMIT];

int rev(int x) {
	int res = 0;
	while(x) {
		int digit = x%10;
		x /= 10;
		res = res*10 + digit;
		
	}
	return res;
}

void solve() {
	
	fill(ans, ans+LIMIT, 1000000000);
	ans[1] = 1;
	for(int i=2; i<LIMIT; i++) {
		
		ans[i] = min(ans[i], 1+ans[i-1]);
		const int r = rev(i);
		if(r>i && r<LIMIT) ans[r] = min(ans[r], 1+ans[i]);
	}
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	solve();
    
    int T; cin>>T;
    REP(_t, T) {
        cout<<"Case #"<<_t+1<<": ";
        int inp; cin>>inp;
        //DBG(rev(inp));
        cout<<ans[inp]<<endl;
        
        
        
    }
}
