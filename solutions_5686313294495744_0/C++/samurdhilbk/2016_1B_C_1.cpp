#include<bits/stdc++.h>

using namespace std;

#define NIL 0
#define INF INT_MAX
typedef long long ll;
typedef pair<ll, ll> pr;
typedef pair<string, ll> prr;

int main(){
	ios_base::sync_with_stdio(false);
	int tt;
	cin>>tt;
	for(int t=0;t<tt;t++){
		ll n;
		cin>>n;
		vector<prr> firsts;
		vector<prr> seconds;
		for(int i=0;i<n;i++){
			string s1,s2;
			cin>>s1>>s2;
			firsts.push_back(make_pair(s1,i+1));
			seconds.push_back(make_pair(s2,i+1));
		}
        int ans=INT_MIN;
        for(int i=0;i<(1<<n);i++){
            vector<int> real;
            vector<int> fake;
            int count=0;
            for(int j=0;j<n;j++) {
                if((1<<j)&i) real.push_back(j);
                else fake.push_back(j);
            }
            for(int j=0;j<fake.size();j++){
                bool f=false,s=false;
                for(int k=0;k<real.size();k++){
                    if(firsts[fake[j]].first==firsts[real[k]].first){
                        f=true;
                    }
                    if(seconds[fake[j]].first==seconds[real[k]].first){
                        s=true;
                    }
                    if(f&&s) {
                        count++;
                        break;
                    }
                }
            }
            ans=max(ans,count);
        }

		printf("Case #%d: %lld\n",t+1,ans);
	}
}