//============================================================================
// Name        : codejamA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iterator>

using namespace std;


multiset<int> mykeys;
map<int, multiset<int> > chestTypes;


bool isSafe(int type, multiset<int> keys){
	set<int> mykeysuniq(mykeys.begin(), mykeys.end());
	mykeysuniq.erase(type);
	mykeysuniq.insert(keys.begin(), keys.end());
	set<int> newKeys = mykeysuniq;
	set<int> newit;
	bool isNew = false;
	do{
		isNew = false;
		newit.clear();
		for(set<int>::iterator setit = newKeys.begin(); setit!= newKeys.end(); ++setit){
			multiset<int> adj = chestTypes[*setit];
			for(multiset<int>::iterator typeKey = adj.begin(); typeKey != adj.end(); ++typeKey){
				if(*typeKey == type){
				//	cout<<"is Save: "<<type<<endl;
					return true;
				}else if(mykeysuniq.find(*typeKey) == mykeysuniq.end() ){
					newit.insert(*typeKey);
					mykeysuniq.insert(*typeKey);
					isNew = true;
				}
			}
		}
		newKeys = newit;
	}while(isNew);

	return false;
}


string solve(){
	mykeys.clear();
	chestTypes.clear();
	vector<int> result;
	int K,N;
	cin>>K>>N;
	multiset<int> chestCount;
	vector< pair<int, multiset<int> > > chests;
	bool isOpened[N];
	memset(isOpened, 0, sizeof(bool)*N);
	for(int i=0; i<K; ++i){
		int key;
		cin>>key;
		mykeys.insert(key);
		//cout<<"inserting key: "<<key<<endl;
	}
	for(int i=0; i<N; ++i){
		int chestType, chestKeyCount;
		cin>>chestType>>chestKeyCount;
		pair<int, multiset<int> > chest;
		chest.first = chestType;
		chestCount.insert(chestType);
		//cout<<"chest number: "<<i<<" type: "<<chestType<<endl;
		for(int j=0; j<chestKeyCount; ++j){
			int key;
			cin>>key;
			chest.second.insert(key);
			chestTypes[chestType].insert(key);
		//	cout<<"chest number: "<<i+1<<" key in type: "<<chestType<<" - "<<key<<endl;

		}
		chests.push_back(chest);
	}
	for(int i=0; i<N; ++i){
		bool opened = false;
		for(size_t j=0; j<chests.size(); ++j){
			if(isOpened[j]){
				//cout<<"already opened"<<endl;
				continue;
			}
			int type = chests[j].first;
			multiset<int> keys = chests[j].second;
		//	cout<<"type = "<<type<<" keys count = "<<mykeys.count(type)<<" chest count: "<<chestCount.count(type)<<endl;
			if(mykeys.count(type) > 1 || ( mykeys.count(type)>0 && ( chestCount.count(type) == 1 || isSafe(type, keys) ) ) ){//to otwieramy
			//	cout<<j+1<<" opened"<<endl;
				isOpened[j] = true;
				opened = true;
				result.push_back(j+1);
				multiset<int>::iterator it = mykeys.find(type);
				mykeys.erase(it);
				mykeys.insert(keys.begin(), keys.end());
				for(it = keys.begin(); it!=keys.end(); ++it){
					multiset<int>::iterator it2 = chestTypes[type].find(*it);
					chestTypes[type].erase(it2);
				}
				it = chestCount.find(type);
				chestCount.erase(it);
				break;
			}
		}
		if(!opened){
			return "IMPOSSIBLE";
		}
	}

	ostringstream oss;
	copy(result.begin(), result.end()-1, ostream_iterator<int>(oss, " "));
	oss << result.back();
	return oss.str();
}

int main() {
	int T;
	cin>>T;
	for(int i=0; i<T; ++i){
		string ans = solve();
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}
