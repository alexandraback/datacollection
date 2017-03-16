#include<iostream>
#include<complex>
#include<cstring>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<vector>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<functional>
#include<algorithm>
#define INF 1000000000
#define all(c) c.begin(),c.end()
#define uni(c) c.erase(unique(all(c)),c.end())
#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,k) for(int i=0;i<k;i++)
#define PB push_back
using namespace std;
typedef pair<int,int> P;
typedef __int64 ll;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

int main(){
	int t;
	cin>>t;
	int now=0;
	while(t--){
		int n,a;
		cin>>a>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(all(v));
		int ans=n;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(v[i]<a){
				a+=v[i];
			}else{
				if(a==1){
					ans=n-i;
					break;
				}
				while(v[i]>=a){
					a+=a-1;
					cnt++;
				}
				a+=v[i];
			}
			ans=min(ans,cnt+n-i-1);
		}
		cout<<"Case #"<<++now<<": "<<ans<<endl;
	}
	
	
	
	return 0;
}




