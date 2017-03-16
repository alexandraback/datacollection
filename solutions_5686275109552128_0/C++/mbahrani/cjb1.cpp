#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <set>
#include <map>

#define show(x) cerr << "# " << #x << " = " << (x) << endl

#define FOR(i, a, b) for(__typeof(a) i = a; i != b; i++)
#define FR(i, a) FOR(i, 0, a)
#define FOREACH(i, t) FOR(i, t.begin(), t.end())
#define ALL(x) (x).begin(), (x).end()
#define SZ(a) int(a.size())
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define F first
#define S second

using namespace std;

inline bool ascending (int i, int j) { return (i < j); }
inline bool descending (int i, int j) { return (i > j); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


#define cin fin
#define cout fout


const int MN = 1000 + 10;
map<int, int> m;
vector<int> p;
int t, len, temp, delay;


ifstream fin("B-small-attempt2.in");
ofstream fout("B-small.out");


int bt(vector<int> v, map<int, int> mm)
{
	sort(v.begin(), v.end(), descending);
	//cout << "\n# ";
	//FR(i, SZ(v)) cout << v[i] << " ";
	
	//FR(i, 10) cout << mm[i] << " ";
	//cout << SZ(v);
	//cout << endl;
	if(v[0] < 4) return v[0];
	if(v.size() == 0) return 0;
	
	vector<int> vv = v;
	map<int, int> am = mm;
	
	int tmp = vv[0];
	vv.erase(vv.begin());
	int delay = mm[tmp];
	sort(vv.begin(), vv.end(), descending);
	am[tmp] = 0;
	if(tmp % 2)
	{
		if(am[(tmp+1)/2] == 0) vv.PB((tmp+1) / 2);
		if(am[tmp / 2] == 0) vv.PB(tmp / 2);
		am[tmp / 2] += mm[tmp];
		am[(tmp+1) / 2] += mm[tmp];
	}
	else
	{
		if(am[tmp / 2] == 0) vv.PB(tmp / 2);
		am[tmp / 2] += mm[tmp] * 2;
	}
	
	vector<int> vvv = v;
	map<int, int> mmm = mm;
	FR(i, SZ(vvv))
	{
		//show(vvv[i]);
		if(vvv[i] == 1) {vvv.erase(vvv.begin() + i); mmm[1] = 0; break; }
		else { mmm[vvv[i]] -= mm[vvv[i]]; mmm[vvv[i]-1] += mm[vvv[i]]; vvv[i]--; }
		/*show(i);
		show(vvv[i]);
		show(mmm[vvv[i]]);*/
	}
	/*
	//if(min(delay + bt(vv, am), 1 + bt(vvv, mm)) == 3)
		FR(i, SZ(v)) show(i), show(v[i]), show(mm[v[i]]);
		cout << endl;
		FR(i, SZ(vv)) show(i), show(vv[i]), show(am[vv[i]]);
		cout << endl;
		FR(i, SZ(vvv)) show(i), show(vvv[i]), show(mmm[vvv[i]]);
		cout << endl;
		show(tmp);
		show(delay);
	*/
	return(min(delay + bt(vv, am), 1 + bt(vvv, mmm)));
	
}

int main()
{
	cin >> t;
	FR(q, t)
	{
		p = vector<int>();
		FR(i, MN) m[i] = 0;
		cin >> len;
		FR(i, len){
			cin >> temp;
			if(!m[temp]) p.PB(temp);
			m[temp]++;
		}
		//FR(i, SZ(p)) show(m[p[i]]);
		cout << "Case #" << q + 1 << ": " << bt(p, m) << endl;
	}
	
	return 0;
}
