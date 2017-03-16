#include<bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}



int main(){
	int T;
	cin>>T;
	for(int k=1; k<=T; k++){
		int n;
		cin>>n;
		map<string, int> first, second;
		int s1=0, s2=0;
		set<pair<int, int> > points;
		for(int i=0; i<n; i++){
			string a, b;
			cin>>a;
			cin>>b;
			if(first.find(a)==first.end()){
				first[a]=s1;
				s1++;
			}
			if(second.find(b)==second.end()){
				second[b]=s2;
				s2++;
			}
			points.insert({first[a], second[b]});
			//cout<<first[a]<<" "<<second[b]<<endl;
		}
		
		int n1=first.size();
		int n2=second.size();
		
		vector<vector<int> > dp(n1, vector<int>(n2, 0));
		for(auto p:points){
			dp[p.first][p.second]=1;
		}
		
		vector<int> m1(n1), m2(n2);
		int ans = BipartiteMatching(dp, m1, m2);
		ans = n1 + n2 - ans;
		ans = n - ans;
		cout<<"Case #"<<k<<": "<<ans<<endl;
		
	}
	return 0;
}
