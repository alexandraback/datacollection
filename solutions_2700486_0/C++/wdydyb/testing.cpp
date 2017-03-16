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
int n,x,y;
double ans;
void cal(map<int,int>,int,double);
bool check(map<int,int> mp){
	//cout<<"    "<<mp[0]<<endl;
	if(abs(x)%2==0){
		if(mp[x]*2-1>=y){
			return true;
		}
		return false;
	}else{
		if(mp[x]*2>=y){
			return true;
		}
		return false;
	}
}
void search(map<int,int> mp,int ax,int now,double p){
	if(abs(ax)%2==0){
		if(mp[ax]<=mp[ax+1]&&mp[ax]<=mp[ax-1]){
			mp[ax]++;
			cal(mp,now+1,p);
		}else if(mp[ax]<=mp[ax+1]){
			search(mp,ax-1,now,p);
		}else if(mp[ax]<=mp[ax-1]){
			search(mp,ax+1,now,p);
		}else{
			double ret=0;
			search(mp,ax-1,now,p/2);
			search(mp,ax+1,now,p/2);
			//cout<<"hoge"<<ret<<endl;
			//return ret;
		}
	}else{
		if(mp[ax]<mp[ax+1]&&mp[ax]<mp[ax-1]){
			mp[ax]++;
			cal(mp,now+1,p);
		}else if(mp[ax]<mp[ax+1]){
			search(mp,ax-1,now,p);
		}else if(mp[ax]<mp[ax-1]){
			search(mp,ax+1,now,p);
		}else{
			double ret=0;
			search(mp,ax-1,now,p/2);
			search(mp,ax+1,now,p/2);
			ret;
		}
	}
}
void cal(map<int,int> mp,int now,double p){
	if(now==n){
		if(check(mp)){
			//cout<<"YES"<<mp[-2]<<mp[-1]<<mp[0]<<mp[1]<<mp[2]<<endl;
			//cout<<p<<endl;
			ans+=p;
			
		}
		return;
	}
	//cout<<now<<endl;
	search(mp,0,now,p);
}

int main(){
	int t;
	cin>>t;
	int now=0;
	while(t--){
		ans=0.0;
		map<int,int> mp;
		cin>>n>>x>>y;
		mp[0]=1;
		cal(mp,1,1.0);
		printf("Case #%d: %.7lf\n",++now,ans);
		//cout<<"Case #"<<++now<<": "<<ans<<endl;
	}
	
	
	
	return 0;
}




