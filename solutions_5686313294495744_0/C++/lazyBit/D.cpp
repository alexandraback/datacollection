#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
 
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <random>
 
using namespace std;
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <string> vs;
 
typedef long long LL; //NOTES:int64
typedef unsigned long long ULL; //NOTES:uint64
typedef unsigned uint;
 
const double pi = acos(-1.0); //NOTES:pi
const double eps = 1e-11; //NOTES:eps
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "SENW";
 
#define rep(i,n)        for (int i=0;i<n;i++)
#define loop(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define rloop(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define Reset(a,b)      memset((a),(b),sizeof(a))
 
#define endline         putchar('\n')
#define space           putchar(' ')
#define EXIT(x)         {cout << x;return 0;}
 
#define fi              first
#define se              second
#define pb              push_back
 
#define S(x)            scanf("%d",&x);
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define deb(i,a,n) for(i=0;i<n;i++){cout<<a[i]<<" ";}
#define db(x,y)          printf("%d %d\n",x,y);
#define debug(args...)	{dbg,args; cerr<<endl;}
#define dline			cerr<<endl	
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define maX(a,b)		((a)>(b)?(a):(b))
#define miN(a,b)		((a)<(b)?(a):(b))
#define abS(x)			((x)<0?-(x):(x))
#define mod             1000000007
 
struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;
 
void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}
 
int a[100010];
bool vis1[1010];
string str1,str2;
vector<string> v1,v2;
vector<int> vv1;
map < string,int> mp1,mp2;
map < string,vector<int> >mmp1,mmp2;
vector <int> v[1010];
int dfs(int m,int l) {
	if(vis1[m]) return l-1;
	vis1[m]=true;
	int ans=l;
	for(int i=0;i<v[m].size();i++) {
		cout<<v[m][i];
		if(!vis1[v[m][i]])
		ans=max(ans,dfs(v[m][i],l+1));
	}
	vis1[m]=false;

	return ans;
}


int main()
{
	#ifndef ONLINE_JUDGE
        input;
        output;
    #endif
	int n,i,j,k,l,m,t,s=0,d;
	S(t)
	l=1;
	while(t--){
		Reset(vis1,0);
		mp1.clear();
		mp2.clear();
		mmp1.clear();
		mmp2.clear();
		v1.clear();
		v2.clear();
		for(i=0;i<50;i++) {
			v[i].clear();
		}
		S(n);
		for(i=0;i<n;i++) {
			cin>>str1>>str2;
			v1.push_back(str1);
			mp1[str1]++;
			mmp1[str1].push_back(i);
			v2.push_back(str2);
			mp2[str2]++;
			mmp2[str2].push_back(i);
			// mmp1

		}

		for(i=0;i<n;i++) {
			if(mp1[v1[i]]==1||mp2[v2[i]]==1) {
				vv1.push_back(i);
			}
		}
bool vis[1010];
		for(i=0;i<n;i++) {
			string s= v1[i];
			vector<int> vv = mmp1[s];
			s= v2[i];
			vector<int> v2 = mmp2[s];
			
			// if(i==1) {
			// 	cout<<vv.size();
			// }
			for(j=0;j<vv.size();j++) {
				if(vv[j]==i) continue;
				// cout<<vv[j]<<"hi"<<i<<endl;
				v[i].push_back(vv[j]);
				vis[vv[j]]=true;
			}
			for(j=0;j<v2.size();j++) {
				if(v2[j]==i) continue;
				if(!vis[v2[j]]) {
					v[i].push_back(v2[j]);
					vis[v2[j]]=true;
				} 

			}

			// Reset(vis,0);

		}
		// for(i=0;i<v[0].size();i++) {
		// 	printf("%d\n",v[0][i]);
		// }

		// for(i=0;i<vv1.size();i++) {
		// 	printf("%d\n",vv1[i]);
		// }
		int ans=0;
		// for(i=0;i<vv1.size();i++) {
		// 	vis1[vv1[i]]=true;
		// 	// cout<<vv1[i]<<' '<<v[vv1[i]].size()<<endl;
		// 	for(int j=0;j<v[vv1[i]].size();j++) {
		// 		// cout<<i<<endl;
		// 		// cout<<v[vv1[i]][j]<<"hi"<<endl;
		// 		ans=max(ans,dfs(v[vv1[i]][j],1));
		// 	}
		// 	vis1[vv1[i]]=false;
		// }

		queue< pair<int,int> > q;
		for(i=0;i<vv1.size();i++) {	
			q.push(make_pair(vv1[i],0));
			vis1[vv1[i]]=true;
		}

		while(!q.empty()) {
			pair<int,int> p = q.front();
			q.pop();

			ans = max(ans,p.second);
			for(i=0;i<v[p.first].size();i++) {
					if(!vis1[v[p.first][i]]) {
						q.push(make_pair(v[p.first][i],p.second+1));
						vis1[v[p.first][i]]=true;
					}
				}

		}

		printf("Case #%d: %d\n",l,ans);
		l++;
 		
	}
	return (0);
} 
