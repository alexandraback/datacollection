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

bool check(char a){
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
		return false;
	return true;
}

int main(){		
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int t, n;
	vector<int> start;
	string name;
	cin>>t;
	for(int j=1; j<=t; j++){
		start.clear();
		long long res = 0;
		cin>>name>>n;
		int counter = 0;
		int len = name.size();
		for(int i=0; i<len; i++){
			if(check(name[i])==false)
				counter = 0;
			else
				counter++;
			if(counter>=n)
				start.push_back(i);
		}
		for(int i=0; i<start.size(); i++){
			int left, right;
			if(i==0)
				left = start[i]-n+1+1;
			else
				left = start[i]-start[i-1];
			if(i==start.size()-1)
				right = len - start[i];
			else
				right = len-start[i];
			//cout<<left<<" "<<right<<endl;
			res += left*right;
		}
		cout<<"Case #"<<j<<": "<<res<<endl;
	}
	
	return 0;
}
