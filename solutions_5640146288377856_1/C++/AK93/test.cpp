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

void print(int test, int res){
	cout<<"Case #"<<test<<": "<<res<<"\n";
}

int main(){
	freopen("A-large(1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int count_test;
	cin>>count_test;
	for(int test = 1; test <= count_test; test++){
		int r, c, w;
		cin>>r>>c>>w;
		int cnt = 0;
		int l = c % w;
		if(l != 0)
			cnt++;
		while(l < c){
			l += w;
			cnt++;
		}
		int res = cnt * r;
		res += (w - 1);
		print(test, res);
 	}

    return 0;
}