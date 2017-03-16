#include<iostream>
#include<cstdio>
#include<sstream>
#include<fstream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<complex>
#include<bitset>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
#include<utility>

#define pb push_back
#define pp pop_back
#define xx first
#define yy second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int f[20];
int n;

bool check(int mask){
	if(__builtin_popcount(mask)<4)return true;
	vi per;
	int x,y;
	for(int i=0;i<n;i++){
		if((mask&(1<<i))!=0){
			per.pb(i);
			per.pb(f[i]);
			x=i;
			y=f[i];
			break;
		}
	}
	for(int i=0;i<n;i++){
		if((mask&(1<<i))!=0 && i!=x && i!=y){
			per.pb(i);
		}
	}
	int sz=per.size();
	vector<int>::iterator it=per.begin();
	it++;
	it++;
	do{
		bool flag=true;
		for(int i=1;i<sz;i++){
			if(f[per[i]]==per[(i+1)%sz] || f[per[i]]==per[(i-1+sz)%sz])continue;
			flag=false;
			break;
		}
		if(flag)return true;
	}while(next_permutation(it,per.end()));
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		memset(f,0,sizeof(f));
		int ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>f[i];
			f[i]--;
		}
		for(int mask=0;mask<(1<<n);mask++){
			bool flag=true;
			for(int i=0;i<n;i++){
				if((mask&(1<<i))!=0){
					if((mask&(1<<f[i]))==0){
						flag=false;
					}
				}
			}
			if(flag){
				if(check(mask)){
					ans=max(ans,__builtin_popcount(mask));
				}
			}
		}
		cout<<"Case #"<<l<<": "<<ans<<endl;
	}
	return 0;
}
