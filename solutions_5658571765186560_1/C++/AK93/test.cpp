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

bool small(int x, int n, int m){
	bool res = false;
	if(x == 1){
		res = true;
	}
	if(x == 2){
		int k = n * m;
		res = !(k % 2);
	}
	if(x == 3){
		int k = n * m;
		if(k == 6 || k == 9 || k == 12)
			res = true;
	}
	if(x == 4){
		int k = n * m;
		if(k == 12 || k == 16)
			res = true;
	}
	return res;
}

void print(int test, bool res){
	cout<<"Case #"<<test + 1<<": ";
	if(res)
		cout<<"GABRIEL\n";
	else
		cout<<"RICHARD\n";
}

int main(){
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test_count;
	cin>>test_count;
	for(int test=0; test<test_count; test++){
		int x, n, m;
		cin>>x>>n>>m;
		bool res = false;
		if(x <= 4 && n <= 4 && m <= 4){
			res = small(x, n, m);
		}
		else{
			if(x <= 6){
				int k = n * m;
				if(n >= x && m >= x && (k % x == 0)){
					res = true;
				}
			}
		}
		print(test, res);
	}
    return 0;
}
