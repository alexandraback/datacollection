#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){		
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int t, x, y;
	vector<char> res;
	cin>>t;
	for(int i=1; i<=t; i++){
		cin>>x>>y;
		res.clear();
		if(x>0){
			for(int j=0; j<x; j++){
				res.push_back('W');
				res.push_back('E');
			}
		}
		else{
			for(int j=0; j<-x; j++){
				res.push_back('E');
				res.push_back('W');
			}
		}
		if(y>0){
			for(int j=0; j<y; j++){
				res.push_back('S');
				res.push_back('N');
			}
		}
		else{
			for(int j=0; j<-y; j++){
				res.push_back('N');
				res.push_back('S');
			}
		}
		cout<<"Case #"<<i<<": ";
		for(int j=0; j<res.size(); j++)
			cout<<res[j];
		cout<<endl;
	}
	return 0;
}
