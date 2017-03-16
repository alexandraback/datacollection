#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>
#include <map>
#include <cstdio>
#include <queue>


using namespace std;

const int inf = 1000*1000*1000;

string strs[113];

int solve(int a,int b, int k){
	int ans = 0;
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			if((i&j) < k){
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int a,b,k;
		cin>>a>>b>>k;
		cout<<"Case #"<<i<<": "<<solve(a,b,k)<<endl;
		
	}
    return 0;
}