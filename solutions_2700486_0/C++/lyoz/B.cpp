#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

vector<pair<vvi,double>> get_states()
{
	queue<tuple<vvi,int,double>> q; // (state,#diamond,probability);
	q.emplace(vvi(20,vi(20)),1,1);
	
	vector<pair<vvi,double>> states;
	while(!q.empty()){
		auto cur=q.front(); q.pop();
		if(get<1>(cur)>20){
			states.emplace_back(get<0>(cur),get<2>(cur));
			continue;
		}
		
		vvi cs=get<0>(cur);
		int ct=get<1>(cur);
		double cp=get<2>(cur);
		
		int cx=0,cy;
		for(cy=20;cy-2>=0&&!cs[cy-2][10];cy-=2);
		if(cy>0 && !cs[cy-1][10+cx-1] && !cs[cy-1][10+cx+1]){
			int cx1=cx-1,cy1=cy-1;
			while(cy1>0 && (!cs[cy1-1][10+cx1-1] || !cs[cy1-1][10+cx1+1])){
				if(!cs[cy1-1][10+cx1-1]) cx1--;
				else                     cx1++;
				cy1--;
			}
			cs[cy1][10+cx1]=ct;
			q.emplace(cs,ct+1,cp/2);
			cs[cy1][10+cx1]=0;
			
			int cx2=cx+1,cy2=cy-1;
			while(cy2>0 && (!cs[cy2-1][10+cx2-1] || !cs[cy2-1][10+cx2+1])){
				if(!cs[cy2-1][10+cx2-1]) cx2--;
				else                     cx2++;
				cy2--;
			}
			cs[cy2][10+cx2]=ct;
			q.emplace(cs,ct+1,cp/2);
			cs[cy2][10+cx2]=0;
			continue;
		}
		for(;;){
			if(cy==0 || cs[cy-1][10+cx-1] && cs[cy-1][10+cx+1]){
				cs[cy][10+cx]=ct;
				q.emplace(cs,ct+1,cp);
				break;
			}
			else if(!cs[cy-1][10+cx-1])
				cy--,cx--;
			else if(!cs[cy-1][10+cx+1])
				cy--,cx++;
		}
	}
	
	return states;
}

void solve(const vector<pair<vvi,double>>& states)
{
	int n,x,y; cin>>n>>x>>y;
	if(x<-10 || 10<=x || 10<=y){
		printf("%f\n",0.);
		return;
	}
	double res=0;
	for(auto s:states){
		if(s.first[y][10+x]>0 && s.first[y][10+x]<=n)
			res+=s.second;
	}
	printf("%f\n",res);
}

int main()
{
	vector<pair<vvi,double>> states=get_states();
	
	int T; scanf("%d",&T);
	rep(i,T){
		printf("Case #%d: ",i+1);
		solve(states);
	}
	
	return 0;
}
