#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef pair<string,string> Tpair;
int Q;
int N;
vector<Tpair>topics;

bool check(int mask){
	set<string>first,second;
	for (int i=0;i<N;i++){
		if (mask&(1<<i)) continue;
		first.insert(topics[i].first);
		second.insert(topics[i].second);
	}
	for (int i=0;i<N;i++){
		if (mask&(1<<i)){
			if (!first.count(topics[i].first) || !second.count(topics[i].second))
				return false;
		}
	}
	return true;
}
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cout<<"Case #"<<testcase<<": ";
		cin>>N;
		topics.clear();
		for (int i=0;i<N;i++){
			string x,y;
			cin>>x>>y;
			topics.push_back(make_pair(x,y));
		}
		int best=-1;
		int bestmask;
		for (int i=0;i<1<<N;i++){
			int len=0;
			for (int j=0;j<N;j++)
				len+=((i&(1<<j))>0);
			if (best!=-1 && len<=best)
				continue;
			if (!check(i))
				continue;
			best=len;
			bestmask=i;
		}
		cout<<best<<endl;
		//cout<<bestmask<<endl;
	}
	return 0;
}
