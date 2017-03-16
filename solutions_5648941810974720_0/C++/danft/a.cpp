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

string nn[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; 

int main(void) {
	ios::sync_with_stdio(false);
    int T;cin>>T;
    for(int tt=0;tt<T;tt++) {
        vi ans;
        string s;
        cin>>s;
        vi cnt(256, 0);
        For(i,0,s.size())
            cnt[s[i]]++;
        cout<<"Case #"<<tt+1<<": ";

        int ord[]={0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        for(int k=0;k<10;k++) {
            int j=ord[k];
            while(1) {
                bool ok=1;
                map<int, int>  cnt2;
                for(int i=0;i<nn[j].size();i++) {
                    cnt2[nn[j][i]]++;
                }
                for( map<int,int>::iterator it=cnt2.begin();it!=cnt2.end();it++) {
                    ok&=it->se <= cnt[it->fi];
                }
                if(!ok)break;
                for(int i=0;i<nn[j].size();i++)
                    cnt[nn[j][i]]--;
                ans.pb(j);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];
        cout<<endl;
    }

	
	
	return 0;
}
