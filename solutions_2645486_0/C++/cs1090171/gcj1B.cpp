#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cstring>

using namespace std;

int e,r,n,res;
vector<int> ve;

void preprocess(int i, int en,int v){
	if(i==n){
		res=max(res,v);
		return;
	}
	if(en>e)
		en=e;
	for(int j=0;j<=en;j++){
		preprocess(i+1,en-j+r,v+ve[i]*j);
	}
}

int main(){
	int l,T,temp;
	cin>>T;
	for(int l=1;l<=T;l++){
		res=0;
		ve.clear();
		cout<<"Case #"<<l<<": ";
		cin>>e>>r>>n;
		for(int i=0;i<n;i++){
			cin>>temp;
			ve.push_back(temp);
		}
		preprocess(0,e,0);
		cout<<res<<endl;
	}
	return 0;
}
