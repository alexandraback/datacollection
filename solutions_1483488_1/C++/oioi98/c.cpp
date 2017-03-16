#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#include <sstream>

using namespace std;
int A,B;

map<pair<int,int>,bool> X;
int calc(int val){
	X.clear();
	stringstream ss;ss.clear();
	string s;
	ss << val;
	ss >> s;
	int ret=0;
	for (int i=1;i<s.size();i++){
		string tmp="";
		for (int j=0;j<s.size();j++)
			tmp+=s[(i+j)%s.size()];
		int v2;
		ss.clear();ss << tmp;
		ss >> v2;
		if (v2>val&&v2<=B&&X.find(make_pair(val,v2))==X.end()) {
			//cout << val <<" "<< v2 <<endl;
			X[make_pair(val,v2)]=1;
			ret++;
		}
	}
	return ret;
	
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	cin >> t;
	for (int rt=1;rt<=t;rt++){
		printf("Case #%d: ",rt);
		cin >> A >> B;
		int ret=0;
		for (int i=A;i<=B;i++)
			ret+=calc(i);
		cout << ret <<endl;
	}
	return 0;
}
