#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


struct KeySet {
	map<int, int> numKeys;
	
	KeySet(){}
	
	KeySet(const KeySet& otherSet){
		numKeys = otherSet.numKeys;
	}
	
	bool contains(int key){
		return numKeys.find(key) != numKeys.end();
	}
	
	int size(){
		return numKeys.size();
	}
	
	void clear(){
		numKeys.clear();
	}
	
	void addKey(int key){
		map<int,int>::iterator iter = numKeys.find(key);
		if (iter == numKeys.end()){
			numKeys.insert(pair<int,int>(key, 1));
		} else {
			iter->second++;
		}
	}
	
	void addKeys(vector<int> keys){
		for(int i = 0; i < keys.size(); i++)
			addKey(keys[i]);
	}
	
	void removeKey(int key){
		map<int,int>::iterator iter = numKeys.find(key);
		if (iter == numKeys.end()){
			cerr << "ERROR: Key set does not contain key. EXITING..." << endl;
			exit(1);
		}
		
		if(iter->second == 1)
			numKeys.erase(iter);
		else
			iter->second--;
	}
	
	void print(){
		for(map<int, int>::iterator iter = numKeys.begin(); iter != numKeys.end(); iter++)
			cout << "(" << iter->first << "," << iter->second << ") ";
		cout << endl;
	}
	
};

int K, N;
vector<int> neededKeys;
vector< vector<int> > gainedKeys;
vector<int>    from;
vector<int>    added;
vector<bool> proc;
KeySet startKeys;


vector<int> trace(){
	vector<int> res;
	int seed = (1 << N) - 1;
	
	int n = 0;
	while(n < N){
		res.push_back(added[seed]);
		seed = from[seed];
		n++;
	}
	
	reverse(res.begin(), res.end());
	return res;
}

vector<int> solve(){
	int done = (1 << N) - 1;
	proc.clear();
	from.clear();
	added.clear();
	for(int i = 0; i <= done; i++){
		proc.push_back(false);
		from.push_back(-1);
		added.push_back(-1);
	}
	
	proc[0]  = true;
	queue< pair<int, KeySet> > curSets;
	curSets.push(pair<int, KeySet>(0, startKeys));
	
	while(curSets.size() != 0){
		pair<int, KeySet> best = curSets.front(); curSets.pop();
		if(best.first == done)
			return trace();
		
		int mask = 1;
		for(int i = 0; i < N; i++){
			int newVal = (mask | best.first);
			if(((mask & best.first) == 0) && !proc[newVal] && best.second.contains(neededKeys[i])){
				KeySet newSet = KeySet(best.second);
				newSet.addKeys(gainedKeys[i]);
				newSet.removeKey(neededKeys[i]);
				curSets.push(pair<int, KeySet>(newVal, newSet));		
				proc[newVal]  = true;
				from[newVal]  = best.first;
				added[newVal] = i+1;
			}
			mask = mask << 1;
		}
	}
	return vector<int>();
}

int main(){
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		cin >> K; cin >> N;
		
		startKeys.clear();
		for(int j = 0; j < K; j++){
			int key; cin >> key; startKeys.addKey(key);
		}
	
		neededKeys.clear();
		gainedKeys.clear();
		for(int j = 0; j < N; j++){
			int needed; cin >> needed; neededKeys.push_back(needed);
			int nKeys;  cin >> nKeys; 
			
			vector<int> gains;
			for(int k = 0; k < nKeys; k++){
				int key; cin >> key;
				gains.push_back(key);
			}
			gainedKeys.push_back(gains);
		}
		
		vector<int> order = solve();
		if (order.size() == 0)
			cout << "Case #" << (i+1) << ": IMPOSSIBLE" << endl;
		else {
			cout << "Case #" << (i+1) << ": ";
			for(int n = 0; n < order.size(); n++)
				cout << order[n] << " ";
			cout << endl;
		}
	}
}
