#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <hash_map>

using namespace std;
typedef long long ll;

int solve(vector<int> arr){
	int res = 1e9;
	for(int i=1; i<=1000; i++){
		int sum = 0;
		for(int j=0; j<arr.size(); j++){
			int numb = arr[j];
			int buf = numb / i;
			if(numb % i != 0)
				buf++;
			sum += (buf - 1);
		}
		res = min(res, sum + i);
	}
	return res;
}

int main(){
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test_count;
	cin>>test_count;
	for(int test=0; test<test_count; test++){
		int n;
		cin>>n;
		vector<int> arr(n);
		int res = 0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		res = solve(arr);
		cout<<"Case #"<<test + 1<<": "<<res<<"\n";
	}
    return 0;
}
