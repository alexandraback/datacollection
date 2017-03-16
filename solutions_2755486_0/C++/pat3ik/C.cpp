#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
#define OFF 100000
using namespace std;
typedef long long ll;

struct attack{
	int l;
	int r;
	int day;
	int s;
	
};
vector<attack> vv;
bool cmpx(attack a,attack b){
	return a.day < b.day;
}

class segm{
	int arr[maxn * 20],mm[maxn * 20];

	public:
	segm(){ memset(arr,0,sizeof arr); }
		
	void build(int l,int r,int x){
		cout<<l<<" "<<r<<" "<<x<<"\n";
		if(x < 0 || x > maxn){ cout<<x<<"\n"; }
		
		arr[x]=0;
		if(l > r) return;
		if(l == r){ mm[l]=x; return;  }
		build(l,(r + l) / 2,2 * x + 1);
		build((r + l) / 2 + 1,r,2 * x + 2);
	}
	
	int find(int L,int R,int l,int r,int x){
		if(l > R || r < L) return INT_MAX;
		if(l >= L && r <= R) return arr[x];
		
		int mid=(r + l) / 2;
		return min(find(L,R,l,mid,2 * x + 1),find(L,R,mid + 1,r,2 * x + 2));
	}
	void update(int L,int R,int l,int r,int x,int S){
		if(l > R || r < L) return;
		if(l >= L && r <= R){ arr[x]=max(arr[x],S); return; }
		
		int mid=(r + l) / 2;
		update(L,R,l,mid,2 * x + 1,S);
		update(L,R,mid + 1,r,2 * x + 2,S);
	}
};
segm tree;

struct inter{
	int l;
	int r;
	int h;
};		

vector<inter> irr;
int main(){
	int t,N;
	cin>>t;
	FOR(ttt,t){
		cin>>N;
		
		irr.clear(); vv.clear();
		int minv=INT_MAX, maxv=-1000000000;
		while(N--){
			int d0,n,l,r,s0,dd,ddd,ds;
			cin>>d0>>n>>l>>r>>s0>>dd>>ddd>>ds;
		
			FOR(i,n){
				vv.pb((attack){l + i * ddd,r + i * ddd,d0 + i * dd,s0 + i * ds});
				maxv=max(maxv,r + i * ddd);
				minv=min(minv,l + i * ddd);
			}
		}
		sort(vv.begin(),vv.end(),&cmpx);
		int ans=0,lp,rp;
		for(int i=0;i<vv.size();){
			int day=vv[i].day;
			int si=i;
			for(;i < vv.size() && (vv[i].day==day);i++){
				bool has=false;
				FOR(j,irr.size()){
					if(irr[j].l <= vv[i].l && irr[j].r >= vv[i].r && irr[j].h >= vv[i].s){
						has=true;
						break;
					}
				}
				if(!has) ans++;
			}
			
			FORR(j,si,i){
				irr.pb((inter){vv[j].l,vv[j].r,vv[j].s});
			}
		}
		
		/*tree.build(0,maxv - minv + 1,0);
	
		int ans=0,lp,rp;
		for(int i=0;i<vv.size();){
			int day=vv[i].day;
			int si=i;
			for(;i < vv.size() && (vv[i].day==day);i++){
				lp=vv[i].l - minv;
				rp=maxv - vv[i].r;
				if(tree.find(lp,rp,0,maxv - minv + 1,0) < vv[i].s) ans++;
			}
			FORR(j,si,i){
				lp=vv[j].l - minv;
				rp=maxv - vv[j].r;
				
				tree.update(lp,rp,0,maxv - minv + 1,0,vv[j].s);
			}
		}*/
		cout<<"Case #"<<ttt+1<<": "<<ans<<"\n";
	}

	return 0;
}
