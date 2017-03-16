// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,a,n) for(int i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

int arr[100];
int N;

map<pair<int,ll>, ll> dp;
map<ll,vector<int> > brute;
int solve(int mask) {
	ll s1=0;
	ll s2=0;
	FOR(i,N) {
		if ( (mask&(1ll<<i))) {
			s1+=arr[i];
		}
		else s2+=arr[i];
	}
	if ( s1==s2)return 1;
	return 0;
}

void output(int mask1) {
	int f = 0;
	FOR(i,N) {
		if ( (mask1&(1<<i))) {
			if (!f) {
				f=1;
				cout<<arr[i];
			}
			else cout<<" "<<arr[i];
		}
	}
	cout<<endl;
}

int main(int argc,char** args) {
	int T;
	scanf("%d", &T);
	int kases=0;
	int ans;
	FOR(t,T){
		brute.clear();
		ans=-1;
		kases++;
		scanf("%d",&N);
		FOR(i,N)scanf("%d", &arr[i]);
		int mx = (1<<N);
		for(int i = 1;i<mx;i++) {
			ll s = 0;
			FOR(j,N) {
				if ( (i&(1<<j))>0) {
					s+=arr[j];
				}
			}
			if ( brute.find(s)!=brute.end())brute[s].pb(i);
			else {
				brute[s]=vector<int>();
				brute[s].pb(i);
			}

		}
		int ans1=-1,ans2=-1;
		for(map<ll,vector<int> >::iterator it = brute.begin();it!=brute.end();it++) {
			if ( it->second.size()>1) {
				vector<int> msks = it->second;
				FOR(i,msks.size()) {
					for(int j=i+1;j<msks.size();j++) {
						if ( (msks[i] & msks[j])==0) {
							ans1=msks[i];
							ans2=msks[j];
							goto FOUND;
						}
					}
				}
			
			}
		}
		FOUND:
		cout<<"Case #"<<kases<<":\n";
		if ( ans1!=-1) {
			output(ans1);
			output(ans2);
		}
		else cout<<"Impossible"<<endl;
	}
}
