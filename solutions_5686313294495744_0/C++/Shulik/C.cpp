#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> ii;


vector<ii> topics;
int n;

bool ok(int bm){
	set<int> first, second;
	REP(i, n)if((1<<i)&bm){
		first.insert(topics[i].first);
		second.insert(topics[i].second);
	}
	REP(i, n){
		if(first.find(topics[i].first) == first.end())return false;
		if(second.find(topics[i].second) == second.end())return false;
	}
	return true;
}

void testcase(int T){
	map<string, int> first, second;
	topics.clear();

	cin >> n;
	string s1, s2;
	REP(i, n){
		cin >> s1 >> s2;
		if(first.find(s1) == first.end())first[s1] = first.size();
		if(second.find(s2) == second.end())second[s2] = second.size();
		topics.push_back(ii(first[s1], second[s2]));
	}
	int bst = n;
	REP(i, (1<<n)){
		if(ok(i))bst = min(bst, __builtin_popcount(i));
	}

	cout << "Case #" << T <<": " << n-bst << endl;

}

int main(){
	int T;
	cin >> T;
	REP(i, T)testcase(i+1);


	return 0;
}
