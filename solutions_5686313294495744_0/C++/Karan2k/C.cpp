#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 100005
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

string s[MAX][2];

bool cmp(set<string> one, set<string> two){
	vector<string> a, b;

	for(set<string>::iterator i = one.begin() ; i != one.end() ; i++)
		a.pb(*i);// cout<<*i<<" ";
// // 
// 	cout<<endl;

	for(set<string>::iterator i = two.begin() ; i != two.end() ; i++)
		b.pb(*i);//cout<<*i<<"_";
	// cout<<endl;

	for(int i=0 ; i<b.size() ; i++){
		if(!binary_search(a.begin(), a.end(), b[i]))
			return false;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t, T=1;
	cin>>t;

	while(t--){
		int n, ans = 0;
		cin>>n;

		for(int i=0 ; i<n ; i++)
			cin>>s[i][0]>>s[i][1];

		for(int mask = 0 ; mask < (1<<n) ; mask++){
			set<string> real, fake;
			for(int i=0 ; i<n ; i++){
				if((mask & (1 << i)) == 0)
					fake.insert(s[i][0]);
				else
					real.insert(s[i][0]);
			}

			if(!cmp(real, fake)){
				continue;
			}

			set<string> Real, Fake;
			for(int i=0 ; i<n ; i++){
				if((mask & (1 << i)) == 0)
					Fake.insert(s[i][1]);
				else
					Real.insert(s[i][1]);
			}

			if(!cmp(Real, Fake))
				continue;

			map<pair<string, string>, bool> Map;

			for(int i=0 ; i<n ; i++)
				if(mask & (1 << i))
					Map[mp(s[i][0], s[i][1])] = true;
		
			bool flag = true;
			int cnt = 0;

			for(int i=0 ; i<n ; i++)
				if((mask & (1<< i)) == 0){
					if(Map[mp(s[i][0], s[i][1])]){
						flag = false;
						break;
					}
					cnt++;
				}

			if(!flag)
				continue;
		
			ans = max(ans, cnt);
		}

		cout<<"Case #"<<T++<<": "<<ans<<"\n";
	}

	return 0;
}