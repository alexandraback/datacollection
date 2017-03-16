#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int testcase = 0;
int N;
vector < pair <string, string> > topics;

int max_poss(int bmdp){
	int cnt = 0;
	set <string> f;
	set <string> s;
	for(int i = 0; i<N; i++){
		if(bmdp & (1<<i)){
			f.insert(topics[i].first);
			s.insert(topics[i].second);
		}
	}
	bool isPoss = true;
	for(int i = 0; i<N; i++){
		if(!(bmdp & (1<<i))){
			if(f.find(topics[i].first)==f.end() || s.find(topics[i].second)==s.end()){
				isPoss = false;
				break;
			}else cnt++;
		}
	}
	if(isPoss) return cnt;
	else return 0;
}

void solve(){
	testcase++;
	int ans = 0;
	cin>>N;
	topics.clear();
	string a,b;
	for(int i = 0; i<N; i++){
		cin>>a>>b;
		topics.push_back(make_pair(a,b));
	}
	for(int i = 0; i<(1<<N); i++){
		ans = max(ans,max_poss(i));
	}
	cout<<"Case #"<<testcase<<": "<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}