#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<list>
#include <set>
#include <iterator>
#include<queue>

using namespace std;

struct Chest{
	int keyType;
	int numKeys;
	list<int> keys;
	int index;
};

struct MaxKeyCountSelector {
	bool operator ()(const Chest &lhs, const Chest &rhs ) {
		return lhs.numKeys < rhs.numKeys;
	}
};

struct ChestFinder {
	int keyType;
	ChestFinder(int inKeyType)
		:keyType(inKeyType) {
	}

	bool operator ()(const Chest &inChest) {
		return inChest.keyType == keyType;
	}
};

struct ChestMatcher {
	int index;
	ChestMatcher(int inIndex)
		:index(inIndex) {
	}

	bool operator()(const Chest &rhs) {
		return rhs.index == index;
	}
};

struct IndexComparator {
	bool operator()(const Chest &lhs, const Chest &rhs) {
		return lhs.index > rhs.index;
	}
};

int main() {
	int numTests = 0;
	cin>>numTests;
	for(int currTest = 1; currTest <= numTests; currTest++) {
		int numKeys = 0, numChests=0;
		cin>>numKeys>>numChests;
		list<int> keys;
		for(int key = 0; key < numKeys; key++) {
			int keyVal = 0;
			cin>>keyVal;
			keys.push_back(keyVal);
			cin.clear();
			cin.ignore(1);
		}
		list<Chest> chests;
		for(int chestLine = 1; chestLine <= numChests; chestLine++) {
			Chest chest;
			cin>>chest.keyType>>chest.numKeys;
			if(chest.numKeys>0) {
				list<int> keys;
				for(int key = 0; key < chest.numKeys; key++) {
					int keyVal = 0;
					cin>>keyVal;
					keys.push_back(keyVal);
					cin.clear();
					cin.ignore(1);
				}
				chest.keys.swap(keys);
			}
			chest.index = chestLine;
			chests.push_back(chest);
		}
#ifdef PRINT_INPUT
		cout<<"TEST #"<<currTest<<endl;
		cout<<endl<<"Num chests:"<<numChests<<" Keys: "<<numKeys<<endl;
		cout<<"Keys: ";
		copy(keys.begin(), keys.end(), ostream_iterator<int>(cout, " "));
		cout<<endl;
		int i = 1;
		for(list<Chest>::iterator it = chests.begin(); it != chests.end(); ++it) {
			cout<<"Chest "<<i++<<": KT: "<<(*it).keyType<<" N: "<<(*it).numKeys<<" K: ";
			copy((*it).keys.begin(), (*it).keys.end(), ostream_iterator<int>(cout, " "));
			cout<<endl;
		}
#endif
		list<int> results;
		while(true) {
			list<Chest> validChests;
			for(list<Chest>::iterator it = chests.begin(); it != chests.end(); it++ ) {
				list<int>::iterator activeKey = find(keys.begin(), keys.end(), (*it).keyType);
				if(activeKey != keys.end()) {
					validChests.push_back(*it);
#ifdef DEBUG
					cout<<"Chest "<<(*it).index<<" is valid now"<<endl;
#endif
				}
			}
			list<Chest>::iterator chestWithMaxKeys = max_element(validChests.begin(), validChests.end(), MaxKeyCountSelector());
			if(chestWithMaxKeys == validChests.end()) {
				break;
			}
			int winningKeyCount = (*chestWithMaxKeys).numKeys;
			priority_queue<Chest, vector<Chest>, IndexComparator> openableMaxChests;
			for(list<Chest>::iterator it = chests.begin(); it != chests.end(); it++ ) {
				list<int>::iterator activeKey = find(keys.begin(), keys.end(), (*it).keyType);
				if(winningKeyCount == (*it).numKeys && activeKey != keys.end()) {
					openableMaxChests.push(*it);
					keys.erase(activeKey);
					//chests.erase(*it);
#ifdef DEBUG
					cout<<"Chest "<<(*it).index<<" is another max"<<endl;
#endif
				}
			}
			priority_queue<Chest, vector<Chest>, IndexComparator> openableChests;
			while(!openableMaxChests.empty()) {
				Chest currentChest = openableMaxChests.top();
				openableMaxChests.pop();
#ifdef DEBUG
				cout<<"Chest " <<currentChest.index<<" Is being opened"<<endl;
#endif
				chests.remove_if(ChestMatcher(currentChest.index));
				results.push_back(currentChest.index);
				keys.insert(keys.end(),currentChest.keys.begin(),currentChest.keys.end());
#ifdef DEBUG
				cout<<"Keys: ";
				copy(keys.begin(), keys.end(), ostream_iterator<int>(cout, " "));
				cout<<endl;
#endif
				list<int>::iterator otherKey = find(keys.begin(), keys.end(), currentChest.keyType);
				if(otherKey==keys.end()) {
					continue;
				}
				for(list<Chest>::iterator it = chests.begin(); it != chests.end(); it++ ) {
					list<int>::iterator activeKey = find(keys.begin(), keys.end(), (*it).keyType);
					if(activeKey != keys.end()) {
						openableChests.push(*it);
						keys.erase(activeKey);
						chests.remove_if(ChestMatcher((*it).index));
						//chests.erase(*it);
	#ifdef DEBUG
						cout<<"Chest "<<(*it).index<<" is openable now"<<endl;
	#endif
					}
				}
				while(!openableChests.empty()) {
				Chest currentChest = openableChests.top();
				openableChests.pop();
#ifdef DEBUG
				cout<<"Chest " <<currentChest.index<<" Is being opened"<<endl;
#endif
				results.push_back(currentChest.index);
				keys.insert(keys.end(),currentChest.keys.begin(),currentChest.keys.end());
			}
			}
			
#ifdef DEBUG
			cout<<"Keys: ";
			copy(keys.begin(), keys.end(), ostream_iterator<int>(cout, " "));
			cout<<endl;
#endif
			if(keys.empty() || chests.empty()) {
				break;
			}
			//cout<<openableChests.empty()<<" "<<keys.empty()<<" "<<chests.empty()<<endl;
		}
		cout<<"Case #"<<currTest<<":";
		if(!chests.empty())
		{
			cout<<" IMPOSSIBLE"<<endl;
		}
		else{
			for(list<int>::iterator it = results.begin(); it != results.end(); ++it) {
				cout<<" "<<*it;
			}
			cout<<endl;
		}
	}
	return 0;
}

