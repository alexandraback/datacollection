#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;
const double eps = 1e-10;

vector<string> arr;

bool check(vector<int> pr){
	string str;
	for(int i=0; i<pr.size(); i++){
		int ind = pr[i];
		str += arr[ind];
	}
	vector<char> used(26, false);
	char ch = -1;
	for(int i=0; i<str.size(); i++){
		int j = str[i] - 'a';
		if(!used[j]){
			used[j] = true;
			ch = str[i];
		}
		else{
			if(ch != str[i])
				return false;
		}
	}
	return true;
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test_count;
	cin>>test_count;
	for(int test = 0; test < test_count; test++){
		arr.clear();
		int n;
		cin>>n;
		arr.resize(n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		vector<int> pr(n);
		for(int i=0; i<n; i++){
			pr[i] = i;
		}
		ll res = 0;
		if(check(pr))
			res++;

		while(next_permutation(pr.begin(), pr.end())){
			if(check(pr))
				res++;
		}

		cout<<"Case #"<<test+1<<": ";
		cout<<res;
		cout<<"\n";
	}

	return 0;
}