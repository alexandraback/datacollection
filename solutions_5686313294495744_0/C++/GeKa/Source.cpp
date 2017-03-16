#pragma warning(disable : 4996)
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

int N;
map<string, int> mp;

int mapstring(string s){
	if (mp.find(s) != mp.end())
		return mp[s];
	int r = mp.size();
	mp[s] = r;
	return r;
}

void process(int t){
	cout << "Case #" << t << ": ";
	cin >> N;
	vector<pair<int, int> > v;
	mp.clear();
	for (int i = 0; i < N; i++){
		string a, b;
		cin >> a >> b;
		int aa = mapstring(a);
		int bb = mapstring(b);
		v.push_back(make_pair(aa, bb));
	}
	int res = 0;
	int NN = (1 << N);
	for (int i = 0; i < NN; i++){
		vector<bool> v1(mp.size(), false);
		vector<bool> v2(mp.size(), false);
		int cnt = 0;
		for (int j = 0; j < N; j++){
			if (i & (1 << j)){
				cnt++;
				v1[v[j].first] = true;
				v2[v[j].second] = true;
			}
		}
		bool ok = true;
		for (int j = 0; j < N; j++){
			if ((i & (1 << j))==0){
				if (!v1[v[j].first] || !v2[v[j].second])
				{
					ok = false;
					break;
				}
			}
		}
		cnt = N - cnt;
		if (ok && cnt > res)
			res = cnt;
	}
	cout << res;


	cout << "\n";

}

int main()
{
	freopen("d:\\acm\\CodeJam\\2016\\Round1B\\C\\C.in", "r", stdin);
	freopen("d:\\acm\\CodeJam\\2016\\Round1B\\C\\C.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		process(t + 1);
	}
	return 0;
}