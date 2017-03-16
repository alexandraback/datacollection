#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin>>test;
	for(int t=0; t<test; t++){
		string str;
		int n;
		cin>>str>>n;
		vector<ll> coords;
		coords.reserve(100000);
		int res=0, count=0, coord=0;
		for(int i=0; i<str.size(); i++){
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
				count = 0;
				continue;
			}
			if(count == 0)
				coord = i;
			count++;
			if(count >=n){
				coords.push_back(coord+count-n);
			}
		}
		ll pr=0;
		for(int i=0; i<coords.size(); ++i){
			res+=(coords[i]+1-pr)*(str.size()-(coords[i]+n)+1);
			pr=coords[i]+1;
		}
		printf("Case #%d: %d\n", t+1, res);
		
	}
	return 0;
}
