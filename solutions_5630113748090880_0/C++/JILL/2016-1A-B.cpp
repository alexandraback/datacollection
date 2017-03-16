#include<bits/stdc++.h>
using namespace std;
int cnt[2510];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	for(int ks=1;ks<=T;ks++)
    {
        memset(cnt,0,sizeof(cnt));
        int N;cin>>N;
        for(int i=1;i<2*N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int a;cin>>a;
                cnt[a]++;
            }
        }
        vector<int> ans;
        for(int i=0;i<2510;i++) if(cnt[i]&1) ans.push_back(i);
        cout<<"Case #"<<ks<<": ";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if(i==ans.size()-1) cout<<'\n';
            else cout<<' ';
        }
    }
	return 0;
}
