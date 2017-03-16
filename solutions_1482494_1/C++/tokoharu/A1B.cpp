#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;


int main() {
	int t;
	int T;
	cin>>t;
	T=t;
	for(;t;t--) {
		vector<PII>input;
		int n;
		cin>>n;
		for(int a=0; a<n; a++) {
			int p,q;
			cin>>p>>q;
			input.push_back(MP(q,p));
		}
		sort(input.begin(),input.end());
		
		int now = 0;
		int iter = 0;
		int counting = 0;
		int amari[2010];
		for(int a=0; a<2010; a++) amari[a] = 0;
		
		bool cleared = true;
		
		while(1) {
			
		//	for(int a=0; a<n; a++) cout<<"   "<<input[a].first<<" "<<input[a].second<<endl;
			
			
			bool henka = false;
			while(iter<input.size() && input[iter].first==-1 && input[iter].second==-1){
				iter++;
			}
			if(iter!=input.size()) if(now>=input[iter].first) {
				now+=2;
				counting++;
		//		cout<<input[iter].first<<" "<<input[iter].second<<endl;
				input[iter].first = -1;
				input[iter].second = -1;
				henka = true;
			}
			
			
			if(!henka) for(int a=0; a<=now; a++) {
				if(amari[a]>0) {
		//			cout<<now<<" "<<a<<endl;
					amari[a]--;
					now++;
					counting++;
					henka = true;
					break;
				}
			}
			
			
			if(!henka) for(int a=n-1; a>=0; a--) {
		//		cout<<" "<<input[a].second<<endl;
				if(now>=input[a].second && input[a].second!=-1) {
	//				cout<<input[a].first<<" "<<input[a].second<<"  akan"<<endl;
					now++;
					counting++;
					amari[input[a].first]++;
					input[a].first = -1;
					input[a].second = -1;
					henka = true;
					break;
				}
			}
			if(!henka) {
				cleared = false;
				break;
			}
			if(now==2*n) break;
			
			
		}
		
		if(cleared) cout<<"Case #"<<T-t+1<<": "<<counting<<endl;
 		else cout<<"Case #"<<T-t+1<<": "<<"Too Bad"<<endl;
		
	}
	return 0;
	
}



