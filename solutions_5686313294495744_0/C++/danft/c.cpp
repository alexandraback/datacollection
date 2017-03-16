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

const int N=20;

string v[N][2];
int n;

int main(void) {
	ios::sync_with_stdio(false);
    int T;cin>>T;
    For(tt, 0, T) {
        cin>>n;
        For(i,0,n)
            cin>>v[i][0]>>v[i][1];

        int ans=0;
        for(int us=0;us<1<<n;us++) {
            set<string> fw, sw;
            for(int j=0;j<n;j++)if(!(us & (1<<j))){
                fw.insert(v[j][0]);
                sw.insert(v[j][1]);
            }
            bool ok=1;
            for(int j=0;j<n;j++)if(us & (1<<j)) {
                if(!sw.count(v[j][1]))
                    ok=0;
                if(!fw.count(v[j][0]))
                    ok=0;
            }
            if(ok)
                ans=max(ans, __builtin_popcount(us));
        }
        cout<<"Case #"<<tt+1<<": ";
        cout<<ans<<endl;
    }
	
	
	return 0;
}
