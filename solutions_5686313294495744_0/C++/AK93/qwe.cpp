#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

int func(vector<pair<string, string> > arr, vector<int> pr){
	int res = 0;
	int n = arr.size();
	set<string> s1, s2;
	for(int i=0; i<n; i++){
		if(pr[i] == 1){
			s1.insert(arr[i].first);
			s2.insert(arr[i].second);
		}
	}
	for(int i=0; i<n; i++){
		if(pr[i] == 0){
			string a = arr[i].first, b = arr[i].second;
			if(s1.find(a) != s1.end() && s2.find(b) != s2.end()){
				res++;
			}
		}
	}

	return res;
}

void solveSlow(vector<pair<string, string> > arr, int test){
	int res = 0;
	int n = arr.size();
	vector<int> pr(n, 0);

	for(int i=0; i<(1 << n); i++){
		for(int j=0; j<n; j++){
			if(i & (1 << j)){
				pr[j] = 1;
			}
			else{
				pr[j] = 0;
			}
		}
		int cur = func(arr, pr);
		res = max(res, cur);
	}

	printf("Case #%d: %d\n", test, res);
}

void gen(){
	srand(time(0));
	cout<<"16\n";

	for(int i=0; i<16; i++){
		string a, b;
		for(int j=0; j<20; j++){
			int buf = rand() % 26;
			char ch = buf + 'A';
			a += ch;
		}

		for(int j=0; j<20; j++){
			int buf = rand() % 26;
			char ch = buf + 'A';
			b += ch;
		}
		cout<<a<<" "<<b<<"\n";
	}
	exit(0);
}

int main(){

#ifdef _CONSOLE
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int countTest;
	cin>>countTest;
	
	for(int test = 1; test <= countTest; test++){
		int n;
		cin>>n;
		vector<pair<string, string> > arr(n);
		for(int i=0; i<n; i++){
			cin>>arr[i].first>>arr[i].second;
		}

		solveSlow(arr, test);

		cerr<<test<<"\n";
	}
	
	return 0;
}

