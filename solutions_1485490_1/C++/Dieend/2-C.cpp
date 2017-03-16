#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,long long> item;
typedef pair<item, item> state;

long long LCS(int n,int m, long long tn, long long tm,
			const vector<pair<int,long long> >& s1,
			const vector<pair<int,long long> >& s2, 
			map<state, long long > &cek){
	
	if (n < 0 || m < 0) return 0LL;
	if (tn == 0LL) tn = s1[n].second;
	if (tm == 0LL) tm = s2[m].second;
	pair<map<state, long long>::iterator,bool > coba = cek.insert(make_pair(
																	make_pair(
																		make_pair(n,tn),
																		make_pair(m,tm)),
																	0LL) );
	if (coba.second == false) {
		return (coba.first)->second;
	}
	long long& ret = (coba.first)->second;
//	cout << "param: " << n << "(" << s1[n].first << ") " << m << "(" << s2[m].first << ") " << tn << " " << tm << endl;
	if (s1[n].first != s2[m].first) {
//		cout << "non\n";
		long long a = LCS(n-1,m,0,tm,s1,s2,cek);
		long long b = LCS(n,m-1,tn,0,s1,s2,cek);
		ret += max(a,b);
	} else {
//		cout << "same\n";
		long long sub = 0LL;
		if (tn < tm) {
			sub += tn;
			tm -= tn;
			n -= 1;
			tn = 0LL;
		} else if(tn > tm) {
			sub += tm;
			tn -= tm;
			m -= 1;
			tm = 0LL;
		} else {
			sub += tm;
			m -= 1;
			n -= 1;
			tm = 0LL;
			tn = 0LL;
		}
		ret += sub;
		ret += LCS(n,m,tn,tm,s1,s2,cek);
	}
	return ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	for (int tt=1; tt <= tc; tt++) {
		int n,m;
		scanf("%d %d",&n, &m);
		vector<item> s1(n);
		vector<item> s2(m);
		map<state, long long> cek;
		for (int i=0; i<n; i++) {
			cin >> s1[i].second;
			cin >> s1[i].first;
		}
		for (int i=0; i<m; i++) {
			cin >> s2[i].second;
			cin >> s2[i].first;
		}
		
		cout << "Case #" << tt << ": ";
		printf ("%lld\n",LCS(n-1,m-1,0LL, 0LL, s1,s2,cek));
	}
}
