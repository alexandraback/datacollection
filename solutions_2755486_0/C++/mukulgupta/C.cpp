#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>
#include <sstream>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream SS;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a) MAX(a,-(a))

#define SS(a) scanf("%d",&a)
#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define INF 2147483647

struct node{
	int d;
	int w,e;
	int s;
};

bool cmp(node i, node j){
	return (i.d<j.d);
}

int wall[8000];
int tempwall[8000];

int main(){
	freopen("C-small-attempt3.in","r",stdin);
	freopen("c2.out","w",stdout);
    int t;
    cin>>t;
    FOR(tt,1,t){
		int N;
		cin>>N;
		vector <node> attack;
		REP(i,N){
			int d,n,w,e,s,deltad,deltap,deltas;
			cin>>d>>n>>w>>e>>s>>deltad>>deltap>>deltas;
			w += 2000;
			e += 2000;
			REP(j,n){
				node temp;
				temp.d = d;
				temp.w = w;
				temp.e = e;
				temp.s = s;
				attack.PB(temp);

				d += deltad;
				s += deltas;
				e += deltap;
				w += deltap;
			}
		}
		memset(wall,0,sizeof(wall));

		sort(attack.begin(),attack.end(),cmp);
		int cnt = 0;
		REP(i,SZ(attack)){
			int curday = attack[i].d;
			int j = i;
			while(j<SZ(attack) && attack[j].d == curday) {
					bool flag = false;
					for (int k=2*attack[j].w;k<=2*attack[j].e;k++){
						if (wall[k] < attack[j].s){
							flag = true;
							break;
						}
					}
					if (flag) {
							//cout<<curday<<" "<<attack[j].w<<" "<<attack[j].e<<" "<<attack[j].s<<endl;
							cnt++;
					}
					j++;
			}
			memset(tempwall,0,sizeof(tempwall));
			for (int k=i;k<j;k++){
				for (int l=2*attack[k].w;l<=2*attack[k].e;l++){
					wall[l] = MAX(wall[l],attack[k].s);
				}
			}
			/*
			for (int k=i;k<j;k++){
				int mx = -1;
				for (int l=2*attack[k].w;l<=2*attack[k].e;l++){
					mx = MAX(mx, tempwall[l]);
				}
				for (int l=2*attack[k].w;l<=2*attack[k].e;l++) wall[l] = MAX(wall[l],mx);
			}
			*/
			i = j - 1;
		}

		cout<<"Case #"<<tt<<": "<<cnt<<endl;
    }
    return 0;
}
