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
		
		int n;
		cin>>n;
		vector<int>input;
		for(int a=0; a<n; a++) {
			int p;
			cin>>p;
			input.push_back(p);
		}
		
		vector<PII>data;
		
		for(int a=0; a<(1<<n); a++) {
			int sum = 0;
			for(int b=0; b<n; b++ ) if((a/(1<<b))&1) sum += input[b];
			data.push_back(MP(sum,a));
			
		}
		
		sort(data.begin(),data.end());
		
		
		bool ok = true;
		for(int a=0; a<(1<<n)-1; a++) {
			if(data[a].first == data[a+1].first) {
				int p = data[a].second;
				int q = data[a+1].second;
				
				for(int b=0; b<n; b++) {
					if((p/(1<<b))&1 && (q/(1<<b))&1 ) {
						p -= input[b];
						q -= input[b];
						
					}
 					
				}
				cout<<"Case #"<<T-t+1<<":"<<endl;
				vector<int>ans;
				for(int b=0; b<n; b++) if((p/(1<<b))&1) ans.push_back(input[b]);
				for(int b=0; b<ans.size(); b++) {
					cout<<ans[b];
					if(b==ans.size()-1) cout<<endl;
					else cout<<" "; 
				}
				
				ans.clear();
				for(int b=0; b<n; b++) if((q/(1<<b))&1) ans.push_back(input[b]);
				for(int b=0; b<ans.size(); b++) {
					cout<<ans[b];
					if(b==ans.size()-1) cout<<endl;
					else cout<<" "; 
				}
				
				ok = false;
				break;
			}
		}
		
		
		if(ok ) cout<<"Case #"<<T-t+1<<": "<<"Impossible"<<endl;;
		
//		if(cleared) cout<<"Case #"<<T-t+1<<": "<<counting<<endl;
//		else cout<<"Case #"<<T-t+1<<": "<<"Too Bad"<<endl;
		
	}
	return 0;
	
}


