#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define D(x) cout << #x << " = " << (x) << endl;
#define all(x) (x).begin(),(x).end()
int n;
int cnt[2501];

int main()
{
    freopen("/home/khaled/file.in","r",stdin);
    freopen("/home/khaled/file.out","w",stdout);
    int T,tc(1);
    cin >> T;
    while(T--){
		cin >> n;
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				int a;
				cin >> a;
				cnt[a]++;
			}
		}
		vector<int> ans;
		for(int i=0;i<2501;i++)
			if(cnt[i] > 0 && cnt[i]%2 == 1)
				ans.push_back(i);
		cout << "Case #" << tc++ << ":";
		for(int i=0;i<(int)ans.size();i++)
			cout << " " << ans[i];
		cout << endl;
    }
    return 0;
}



