#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<utility>
#include<fstream>
using namespace std;
class unionFind{
	public:
		vector<int> pset;
		unionFind(int N) { pset.assign(N, 0);
		for (int i = 0; i < N; i++) pset[i] = i; }
		int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
};
void getCombinations(int ind, vector<int>& counts, vector<vector<int>>& result, vector<int>& builder){

	if(ind >= counts.size()){
		result.push_back(builder);
		return;
	}

	//cout << ind << ' ' << counts[ind] << endl;
	builder.push_back(0);
	for(int i = 1; i <= counts[ind]; ++ i){
		builder[ind] = i;
		getCombinations(ind + 1, counts, result, builder);
	}
	builder.pop_back();
}
bool shareMoreThanTwo(vector<int>& first, vector<int>& second){
	if(first[0] == second[0] && first[2] == second[2])
		return true;
	return false;
}
int main()
{
	int t;
	cin >> t;
	for(int z = 1; z <= t; ++ z){
		cout << "Case #" << z << ": ";
		int j,p,s,k;
		cin >> j >> p >> s >> k;
		vector<int> counts;
		counts.push_back(j);
		counts.push_back(p);
		counts.push_back(s);
		vector<vector<int>> combs;
		vector<int> builder, ret;
		getCombinations(0, counts, combs, builder);
		unionFind uf(combs.size());
		int mxDays = 0;
		int jp[4][4];
		int js[4][4];
		int ps[4][4];
		memset(jp, 0, sizeof jp);
		memset(ps, 0, sizeof ps);
		memset(js, 0, sizeof js);
		for(int i = 0; i < combs.size(); ++ i){
			bool can = true;
			if(jp[combs[i][0]][combs[i][1]] >= k || ps[combs[i][1]][combs[i][2]] >= k || js[combs[i][0]][combs[i][2]] >= k){
				continue;
			}
			mxDays ++;
			jp[combs[i][0]][combs[i][1]]++;
			ps[combs[i][1]][combs[i][2]]++;
			js[combs[i][0]][combs[i][2]]++;
			ret.push_back(i);
		}
		cout << mxDays << endl;
		for(int i = 0; i < ret.size(); ++ i){
			for(int j = 0; j < 3; ++ j){
				if(j) cout << ' ';
				cout << combs[ret[i]][j];
			}
			cout << endl;
		}
	}
	return 0;
}