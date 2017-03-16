#include "stdafx.h"

#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;
#define MAX 1010
#define SMALL
//#define LARGE


int flag[MAX];
bool result;
void dfs(vector<vector<int>>& gr,int start){
	vector<int> v = gr[start];
	if(v.size() == 0 )return;
	int s = v.size();
	rep(k,s){
		if(flag[v[k]] == 1){
			result = true;
			return;
		}
		flag[v[k]] = 1;
		dfs(gr,v[k]-1);
	}
	//result = false;
	return;
}
int main(){
	#ifdef SMALL
	freopen("A-small-attempt1.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
	#endif
	#ifdef LARGE
	freopen("A-large-practice.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
	#endif
	int T;
	cin>>T;
	
	int count[MAX];
	rep(i,T){
		int N;
		cin>>N;
		vector<vector<int>> graph;
		result = false;
		rep(j,MAX){
			flag[j] = 0;
			count[j] = 0;
		}
		rep(j,N){
			int m;
			cin>>m;
			vector<int> vec;
			rep(k,m){
				int mi;
				cin>>mi;
				vec.push_back(mi);
				count[mi]++;
			}
			graph.push_back(vec);
		}
		int ent = 0;
		rep2(j,1,N+1){
			if(count[j]==0){
				ent = j;
				rep(p,MAX)
					flag[p] = 0;
				dfs(graph,ent-1);
				if(result == true)
					break;
			}
		}
		//dfs(graph,ent-1);
		cout<<"Case #"<<i+1<<": ";
		if(result == true)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}