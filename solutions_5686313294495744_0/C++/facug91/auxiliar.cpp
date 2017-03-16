/*
	By: facug91
	From: 
	Name: 
	Date: 30/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000000ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, ctr, topicIdx[1005][2];
string topic[2];
map<string, int> to_idx;
set<int> in[2];
bool used[1005];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		ctr = 0;
		to_idx.clear();
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>topic[0]>>topic[1];
			for (j=0; j<2; j++) {
				if (to_idx.find(topic[j]) == to_idx.end())
					to_idx[topic[j]] = ctr++;
				topicIdx[i][j] = to_idx[topic[j]];
			}
		}
		in[0].clear(); in[1].clear();
		memset(used, 0, sizeof used);
		while (true) {
			int notRepeated = -1;
			//cerr<<endl;
			for (i=0; i<n; i++) if (!used[i]) {
				//cerr<<"i "<<i<<" topics "<<topicIdx[i][0]<<" "<<topicIdx[i][1]<<endl;
				if (in[0].find(topicIdx[i][0]) == in[0].end()) {
					notRepeated = i;
					if (in[1].find(topicIdx[i][1]) == in[1].end()) {
						break;
					}
				}
			}
			//cerr<<"in "<<in[0].size()<<" "<<in[1].size()<<endl;
			//cerr<<"notRepeated "<<notRepeated<<endl;
			if (notRepeated != -1) {
				used[notRepeated] = true;
				in[0].insert(topicIdx[notRepeated][0]);
				in[1].insert(topicIdx[notRepeated][1]);
			}
			else break;
		}
		
		while (true) {
			int notRepeated = -1;
			for (i=0; i<n; i++) if (!used[i]) {
				if (in[1].find(topicIdx[i][1]) == in[1].end()) {
					notRepeated = i;
				}
			}
			if (notRepeated != -1) {
				used[notRepeated] = true;
				in[0].insert(topicIdx[notRepeated][0]);
				in[1].insert(topicIdx[notRepeated][1]);
			}
			else break;
		}
		int ans1 = 0;
		for (i=0; i<n; i++) if (!used[i]) ans1++;
		
		
		in[0].clear(); in[1].clear();
		memset(used, 0, sizeof used);
		while (true) {
			int notRepeated = -1;
			//cerr<<endl;
			for (i=0; i<n; i++) if (!used[i]) {
				//cerr<<"i "<<i<<" topics "<<topicIdx[i][0]<<" "<<topicIdx[i][1]<<endl;
				if (in[1].find(topicIdx[i][1]) == in[1].end()) {
					notRepeated = i;
					if (in[0].find(topicIdx[i][0]) == in[0].end()) {
						break;
					}
				}
			}
			//cerr<<"in "<<in[0].size()<<" "<<in[1].size()<<endl;
			//cerr<<"notRepeated "<<notRepeated<<endl;
			if (notRepeated != -1) {
				used[notRepeated] = true;
				in[0].insert(topicIdx[notRepeated][0]);
				in[1].insert(topicIdx[notRepeated][1]);
			}
			else break;
		}
		
		while (true) {
			int notRepeated = -1;
			for (i=0; i<n; i++) if (!used[i]) {
				if (in[0].find(topicIdx[i][0]) == in[0].end()) {
					notRepeated = i;
				}
			}
			if (notRepeated != -1) {
				used[notRepeated] = true;
				in[0].insert(topicIdx[notRepeated][0]);
				in[1].insert(topicIdx[notRepeated][1]);
			}
			else break;
		}
		int ans2 = 0;
		for (i=0; i<n; i++) if (!used[i]) ans2++;
		
		cout<<"Case #"<<it<<": "<<max(ans1, ans2)<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
