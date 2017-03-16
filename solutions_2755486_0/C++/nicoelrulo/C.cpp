#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int)(s); i<(int)(n); i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define dbg(x) //cout<<#x<<' '<<x<<endl
typedef long long tint;
const int MAXN = 1000;
map<int, int>dayPos;
int n2[MAXN], d2[MAXN], w2[MAXN], e2[MAXN], s2[MAXN];

const int PINI = 210;
const int MAXL = 2*PINI;
int mur[MAXL];
int newMur[MAXL];

int main(){
	int t; cin>>t;
	int caso=0;
	while(t>0){
		t--;
		caso++;
		int N; cin>>N; int pos = 0;
		vector<pair<int, int> >v;
		forn(i,N){
			int d, n, w, e, s, dd, dp, ds;
			cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
			forn(j,n){
				d2[pos]=d; w2[pos]=w; e2[pos]=e; s2[pos]=s;
				v.pb(mp(d, pos));
				d+=dd; w+=dp; e+=dp; s+=ds;
				pos++;
			}	
		}
		sort(v.begin(), v.end());
		memset(mur, 0, sizeof(mur));
		memset(newMur, 0, sizeof(newMur));
		//int ult = -1;
		int res = 0;
		forn(i,v.size()){
			int day = v[i].x;
			int pos = v[i].y;
			bool flag = false;
			forsn(j,w2[pos]+PINI, e2[pos]+PINI){
				if(s2[pos]>mur[j])flag=true;
				newMur[j]=max(s2[pos], newMur[j]);
			}
			if(flag)res++;
			dbg(day);
			if(i+1==(int)v.size() || day!=v[i+1].x){
				forn(i,MAXL)mur[i]=max(mur[i], newMur[i]);
				memset(newMur,0, sizeof(newMur));
			}
		}
		printf("Case #%d: %d\n", caso, res);
	}
}
