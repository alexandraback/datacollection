#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <utility>
#include <list>
#include <functional>

#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	all(v)					(v).begin(),(v).end()

typedef	long long				LL;
typedef	vector<int>				VI;
typedef	vector<LL>				VLL;
typedef	vector<vector<int> >	VVI;
typedef	vector<bool>			VB;
typedef	vector<string>			VS;
typedef	pair<int,int>			PII;

struct RECV_R {

	int index;
	int count;
	int num;

	RECV_R(int i, int c, int n) :
		index(i), count(c), num(n)
	{}
};

RECV_R recv(int num, vector<int> &BFF, vector<int> &BFF_num, int index)
{
	if(BFF_num[index] != -1) {
		if(BFF[BFF[index]] == index)
			return RECV_R(-2, 0, BFF_num[index]);
		return RECV_R(index, 0, BFF_num[index]);
	}
	BFF_num[index] = num;
	RECV_R r = recv(num, BFF, BFF_num, BFF[index]);
	if(r.index != -1)
		r.count++;
	if(r.index == index)
		r.index = -1;
	BFF_num[index] = r.num;
	return r;
}

pair<int,int> rcount(const vector<int> &BFF, int index)
{
	if(BFF[BFF[index]] == index)
		return mp(BFF[index], 1);
	auto r = rcount(BFF, BFF[index]);
	return mp(r.first, r.second + 1);
}

int len_count(const vector<int> &BFF, const vector<int> &BFF_num, int num)
{
	map<int, int> result;
	rep(i, BFF.size()) {
		if(BFF_num[i] == num) {
			auto r = rcount(BFF, i);
			result[r.first] = max(result[r.first], r.second);
		}
	}

	int r = 0;
	for(auto it = result.begin() ; it != result.end() ; ++it)
		r += it->second;
	return r;
}

int solve()
{
	int N;
	map<int, pair<bool,int>> s;

	cin >> N;

	vector<int> BFF;
	vector<int> BFF_num(N, -1);
	rep(i, N) {
		int tmp;
		cin >> tmp;
		BFF.pb(tmp - 1);
	}

	rep(i, N) {
		if(BFF_num[i] != -1)
			continue;
		RECV_R r = recv(i, BFF, BFF_num, i);
		if(r.index == -1 || r.index == -2) {
			auto it = s.find(r.num);
			if(it == s.end() || it->second.second < r.count)
				s[r.num] = mp(r.index == -1, r.count);
		}
	}

	int result = -1;
	int sum = 0;

	for(auto it = s.begin() ; it != s.end() ; ++it) {
		if(it->second.first)
			result = max(result, it->second.second);
		else
			sum += len_count(BFF, BFF_num, it->first);
	}

	return max(result, sum);
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}

