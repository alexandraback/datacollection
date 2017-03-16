#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <utility>
#include <deque>
#include <list>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define forl(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<=int(b); ++i)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define ll long long
#define pii pair <int,int>
#define sz(a) a.size()
#define np next_permutation

const int INF = (int)1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
bool ineedoutputfile = true;

int main () {
#ifndef ONLINE_JUDGE
		freopen("input.txt","rt",stdin);
	if (ineedoutputfile)
		freopen("output.txt","wt",stdout);
#endif
	int testcases;
	cin >> testcases;
	for(int r = 1; r <=testcases; r++) {
		printf("Case #%d: ",r);
		int N, M;
		scanf("%d%d",&N,&M);
		vector < pair<ll,int> > box(N), toys;
		set <int> types;
		forn(i,N) {
			cin >> box[i].ft >> box[i].sd;
			types.insert(box[i].sd);
		}
		forn(i,M) {
			ll first; int second;
			cin >> first >> second;
			if (types.count(second)>0) {
					toys.pb(mp(first,second));
			}
		}
		ll ans = 0;
		forn(i,N) {
			ll cnt = 0;
			forn(j,toys.size())
				if (toys[j].sd == box[i].sd)
					cnt+=toys[j].ft;
			ans = max(ans, min(cnt,box[i].ft));
		}
		if (N <=1)  {
			cout << ans <<endl;
			continue;
		}
		forn(i,(1<<N)) {;
			ll cntCase = 0;
			vector < pair<ll,int> > p;
			forn(j,N)
				if((1<<j)&i)
					p.pb(box[j]);
			if (p.size()==0 || p.size()==1 || p.size()==3)
				continue;
			if (p[0].sd == p[1].sd) {
				p[0].ft += p[1].ft;
				ll cnt = 0;
				forn(j,toys.size())
					if (toys[j].sd == p[0].sd)
						cnt+=toys[j].ft;
				ans = max(ans, min(cnt,p[0].ft));
				continue;
			}
			forn(j,toys.size()) {
				ll cnt = 0;
				ll cnt1 = 0;
				for(int k=0; k<j; k++)
					if (toys[k].sd == p[0].sd)
						cnt1+=toys[k].ft;
				cnt+=min(p[0].ft,cnt1);
				cnt1 = 0;
				for(int k=j; k<toys.size(); k++)
					if (toys[k].sd == p[1].sd)
						cnt1+=toys[k].ft;
				cnt+=min(p[1].ft,cnt1);
				cntCase=max(cntCase, cnt);
			}
			ans=max(ans,cntCase);
		}
		if (N <=2)  {
			cout << ans <<endl;
			continue;
		}
		ll cnt3  = 0;
		if (box[0].sd == box[1].sd && box[1].sd == box[2].sd) {
			box[0].ft += box[1].ft + box[2].ft;
			ll cnt = 0;
				forn(j,toys.size())
					if (toys[j].sd == box[0].sd)
						cnt+=toys[j].ft;
			ans = max(ans, min(cnt,box[0].ft));
			cout << ans <<endl;
			continue;
		}
		for(int i=0; i<toys.size(); i++) {
			for(int j=i; j<toys.size(); j++) {
				ll cnt = 0; ll cnt1 = 0;
				for(int k=0; k<i; k++) {
					if (toys[k].sd==box[0].sd)
						cnt1+=toys[k].ft;
				}
				cnt+=min(cnt1,box[0].ft);
				cnt1 = 0;
				for(int k=i; k<j; k++) {
					if (toys[k].sd==box[1].sd)
						cnt1+=toys[k].ft;
				}
				cnt+=min(cnt1,box[1].ft);
				cnt1 = 0;
				for(int k=j; k<toys.size(); k++) {
					if (toys[k].sd==box[2].sd)
						cnt1+=toys[k].ft;
				}
				cnt+=min(cnt1,box[2].ft);
				cnt3 = max(cnt3, cnt);
			}
		}
		if (box[0].sd == box[1].sd) {
			box[0].ft += box[1].ft;
			ll cntCase = 0;
			forn(j,toys.size()) {
				ll cnt = 0;
				ll cnt1 = 0;
				for(int k=0; k<j; k++)
					if (toys[k].sd == box[0].sd)
						cnt1+=toys[k].ft;
				cnt+=min(box[0].ft,cnt1);
				cnt1 = 0;
				for(int k=j; k<toys.size(); k++)
					if (toys[k].sd == box[2].sd)
						cnt1+=toys[k].ft;
				cnt+=min(box[2].ft,cnt1);
				cntCase=max(cntCase, cnt);
			}
			ans=max(ans,cntCase);
			cout << ans <<endl;
			continue;
		}
		if (box[1].sd == box[2].sd) {
			box[2].ft += box[1].ft;
			ll cntCase = 0;
			forn(j,toys.size()) {
				ll cnt = 0;
				ll cnt1 = 0;
				for(int k=0; k<j; k++)
					if (toys[k].sd == box[0].sd)
						cnt1+=toys[k].ft;
				cnt+=min(box[0].ft,cnt1);
				cnt1 = 0;
				for(int k=j; k<toys.size(); k++)
					if (toys[k].sd == box[2].sd)
						cnt1+=toys[k].ft;
				cnt+=min(box[2].ft,cnt1);
				cntCase=max(cntCase, cnt);
			}
			ans=max(ans,cntCase);
			cout << ans <<endl;
			continue;
		}
		ans = max (ans,cnt3);
		cout << ans <<endl;
	}
}
