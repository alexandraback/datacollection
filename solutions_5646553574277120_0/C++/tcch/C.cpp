#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> value;

bool check(vector<int> money, int V){
	//set<int> value;
	value.insert(0);
	set<int>::iterator it;
	vector<int> inc;
	for(int i=0; i<money.size(); i++){
		int next = money[i];
		//cout<<money[i];
		for(it=value.begin();it!=value.end();it++){
			if(*it+next<=V) inc.push_back(*it+next);
		}
		for(int i=0; i<inc.size();i++) value.insert(inc[i]);
	}
	//cout<<value.size()<<' ';
	return value.size()==V+1;
}

void solve(){
	int C,D,V,next;
	cin>>C>>D>>V;
	//cout<<C<<D<<V;
	vector<int> money(D,0);
	for(int i=0; i<D; i++){
		cin>>money[i];
		//cout<<money[i];
	}
	int res = 0;
	BE:
	if(check(money,V)){
		cout<<res<<endl;
		return;
	}
	for(int i=1; i<=V; i++){
		if(value.find(i)==value.end()){
			//cout<<i<<endl;
			res++;
			money.push_back(i);
			value.clear();
			goto BE;
		}
	}
	return;
	
}

int main(){
	int T;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("outs","w",stdout);
	cin>>T;
	for(int t=0; t<T; t++){
		printf("Case #%d: ",t+1);
		solve();
		value.clear();
	}
	return 0;
}