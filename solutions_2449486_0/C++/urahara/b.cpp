#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<climits>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<complex>
#include<set>
#include<bitset>
#include<utility>
#include<valarray>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;

#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define all(a) (a).begin(),(a).end()
#define len(a) ((int)(a).size())
#define mem(a,n) memset(a,n,sizeof(a))
#define eps 1e-9
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)

int ary[120][120],tmp[102][110];
bool vt[120][120];
int main(void){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	rep(k,t){
		int n,m;
		cin>>n>>m;
		priority_queue<pair<int,pii > >pq;
		rep(i,n)rep(j,m){
			cin>>ary[i][j];
			pq.push(mp(-ary[i][j],mp(i,j)));
			tmp[i][j]=100;
		}
		bool hoise=true;
		mem(vt,0);
		
		while(len(pq)){
			pair<int,pii >pp=pq.top();
			pq.pop();
			int x=pp.second.first,y=pp.second.second,a=-pp.first;
			if(vt[x][y])continue;
			int cc=0;
			rep(i,n)if(ary[i][y]<=a)cc++;
			if(cc==n){
				rep(i,n)tmp[i][y]=min(tmp[i][y],ary[x][y]);
			}else{
				cc=0;
				rep(j,m)if(ary[x][j]<=a)cc++;
				if(cc!=m){hoise=false;break;}
				rep(j,m)tmp[x][j]=min(tmp[x][j],ary[x][y]);
			}
		}
		
		cout<<"Case #"<<k+1<<": ";
		if(hoise)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
