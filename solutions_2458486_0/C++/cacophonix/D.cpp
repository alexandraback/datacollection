#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
#include <valarray>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define inf 1061109567
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(x,a) memset(x,a,sizeof(x))
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repi(i,a,b) for(int i(a),_b(b);i<_b;++i)
#define repe(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define len(x) ((int)(x.size()))


#define chk(a,k) ((bool)(a&(1LL<<(k))))
#define off(a,k) (a&(~(1LL<<(k))))
#define on(a,k) (a|(1LL<<(k)))


int cnt[1<<20][40];
int dp[1<<20];
vi cur;
int need[40];
int box[20][40];


int n,k,t1,t2,t3;


void fun(int pos,int mask){
	
	
	
	if(pos==n)return;
	fun(pos+1,mask);
	
	rep(i,40){
		cur[i]+=box[pos][i];
		
	}
	cur[need[pos]]--;
	
	rep(i,40){
		//cout<<cur[i]<<endl;
		cnt[on(mask,pos)][i]=cur[i];
	}
	
	fun(pos+1,on(mask,pos));
	
	rep(i,40){
		cur[i]-=box[pos][i];
	}
	cur[need[pos]]++;
	
}


int fun1(int mask){
	
	//cout<<"hic"<<endl;
	
	if(mask==(1<<n)-1)return 1;
	
	int &ret=dp[mask];
	
	if(ret!=-1)return ret;
	
	ret=0;
	
	rep(i,n)if(!chk(mask,i)){
			//cout<<"hic"<<endl;
			//cout<<cnt[mask][need[i]]<<endl;
			if(cnt[mask][need[i]]>0){
			//cout<<"hic"<<endl;
			ret|=fun1(on(mask,i));
		}
	}
	
	//if(ret)cout<<"hic"<<endl;
	
	return ret;
	
}

void fun2(int mask,vi &v){
	
	if(mask==(1<<n)-1)return ;
	
	
	rep(i,n)if(!chk(mask,i)&&cnt[mask][need[i]]>0&&fun1(on(mask,i))){
		
		
		v.pb(i+1);
		
		fun2(on(mask,i),v);
		
		return;
		
	}
	
}



int main(){
	ios_base::sync_with_stdio(0);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		
		
		
		cin>>k>>n;
		cur.resize(0);
		cur.resize(40);
		mem(box,0);
		
		rep(i,k){
			cin>>t1;
			t1--;
			cur[t1]++;
		}
		
		rep(i,n){
			cin>>k>>t2;
			need[i]=k-1;
			rep(j,t2){
				cin>>t1;
				t1--;
				box[i][t1]+=1;
			}
		}
		
		mem(cnt,0);
		mem(dp,-1);
		
		rep(i,40)cnt[0][i]=cur[i];
		
		fun(0,0);
		
		t1=fun1(0);
		
		if(!t1)cout<<"IMPOSSIBLE"<<endl;
		else{
			vi v;
			fun2(0,v);
			rep(i,n){
				cout<<v[i];
				if(i==n-1)cout<<endl;
				else cout<<" ";
			}
			
		}
		
		
	}
	
	
	
}









