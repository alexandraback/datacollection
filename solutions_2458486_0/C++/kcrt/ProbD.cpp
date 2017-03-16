
/*
 * 	FILENAME - FILEDESCRIPTION
 *		Programmed by kcrt <kcrt@kcrt.net>
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

template<class T, class U> T lexical_cast(const U& from){
    // Exam.:   string s = lexical_cast<string>(int_value);
    //          int i = lexical_cast<int>(str_value);
    //  require #include <sstream>
    T to;
    stringstream ss;
    ss << from; ss >> to;
    return to;
}


class Chest{
	public:
		Chest() : IsOpened(false) {};
		int LockKey;
		list<int> KeysInside;
		bool IsOpened;
		bool OpenWith(list<int> &Keys, vector<Chest> &Chests){
			if(this->IsOpened) return false;
			for(list<int>::iterator it = Keys.begin(); it != Keys.end(); it++){
				if(*it == this->LockKey){
					// CanOpen
					if(count(KeysInside.begin(), KeysInside.end(), this->LockKey) == 0){
						if(count(Keys.begin(), Keys.end(), this->LockKey) == 1){
							// this is the last key!
							int n = 0;
							for(vector<Chest>::iterator j = Chests.begin(); j != Chests.end(); j++){
								if(j->LockKey == this->LockKey &&
										&(*j) != this &&
										!j->IsOpened){
									return false;
								}
							}
						}
					}

					// use this key
					this->IsOpened = true;
					Keys.erase(it);
					// and get another key
					for(list<int>::iterator j = this->KeysInside.begin(); j != this->KeysInside.end(); j++){
						Keys.push_back(*j);
					}
					return true;
				}
			}
			return false;
		}
		bool RewindOpen(list<int> &Keys){
			// 鍵を使ってないことにする
			Keys.push_back(this->LockKey);
			// 手に入れた鍵も消す
			for(list<int>::iterator j = this->KeysInside.begin(); j != this->KeysInside.end(); j++){
				for(list<int>::iterator it = Keys.begin(); it != Keys.end(); it++){
					if(*it == *j){
						Keys.erase(it);
						break;
					}
				}
			}
			this->IsOpened = false;
			return true;
		}
};

int DebugPrint(list<int> ret){
	string s;
	for(list<int>::iterator it = ret.begin(); it != ret.end(); it++){
		s += lexical_cast<string>(*it + 1);
		s += ":";
	}
	printf("%s\n", s.c_str());
	return 1;
}
int DebugPrint(list<int> &Keys, vector<Chest> Chests, string message){

	printf("------\n");
	printf("You have %d key(s); \n ", (int) Keys.size());
	for(list<int>::iterator it = Keys.begin(); it != Keys.end(); it++){
		printf("%d ", *it);
	}
	printf("\n");

	printf("There are %d chest(s); \n", (int) Chests.size());
	for(int i = 0; i < Chests.size(); i++){
		printf(" %d%s[%d]( ", i+1, Chests[i].IsOpened ? "-" : "+", Chests[i].LockKey);
		for(list<int>::iterator it = Chests[i].KeysInside.begin(); it != Chests[i].KeysInside.end(); it++){
			printf("%d ", *it);
		}
		printf(")\n");
	}
	printf("\n");
	printf("%s\n", message.c_str());

	printf("------\n");

	return 0;
}

bool IsLockedOut(list<int>& Keys, vector<Chest>& Chests, int CheckKey){

	int numKeys = 0;
	numKeys = count(Keys.begin(), Keys.end(), CheckKey);



	return false;

}

list<int> Process(list<int>& Keys, vector<Chest>& Chests, int unopenedBox, list<int>& CurrentPass){

	if(unopenedBox == 0){
		return CurrentPass;
	}

	list<int> l;
	
	for(int i = 0; i < Chests.size(); i++){
		if(Chests[i].OpenWith(Keys, Chests)){
			// あいた
			/*string s = "You Opened ";
			s += lexical_cast<string>(i+1);
			s += "th Chest.";
			DebugPrint(Keys, Chests, s);*/
			CurrentPass.push_back(i);
			//DebugPrint(CurrentPass);
			l = Process(Keys, Chests, unopenedBox-1, CurrentPass);
			if(l.size() != 0) return l;
			// だめだった。鍵とか戻す
			Chests[i].RewindOpen(Keys);
			CurrentPass.pop_back();
		}
	}
	return l;

}
bool IsImpossible(list<int> Keys, vector<Chest> Chests){


	vector<int> numLocks(256);

	for(vector<Chest>::iterator it = Chests.begin(); it != Chests.end(); it++){
		numLocks[it->LockKey]++;
	}

	for(list<int>::iterator it = Keys.begin(); it != Keys.end(); it++){
		numLocks[*it]--;
	}
	for(vector<Chest>::iterator it = Chests.begin(); it != Chests.end(); it++){
		for(list<int>::iterator j = (it->KeysInside).begin(); j != (it->KeysInside).end(); j++){
			numLocks[*j]--;
		}
	}

	for(vector<int>::iterator it = numLocks.begin(); it != numLocks.end(); it++){
		if(*it > 0) return true;
	}
	return false;
	
}

int main(){

	int testcase;

	scanf("%d", &testcase);
	for(int i = 0; i < testcase; i++){
		int numKeys;
		int numChests;
		list<int> Keys;
		scanf("%d %d", &numKeys, &numChests);
		vector<Chest> Chests(numChests);
		for(int k = 0; k < numKeys; k++){
			int t;
			scanf("%d", &t);
			Keys.push_back(t);
		}
		for(int c = 0; c < numChests; c++){
			int l;
			int t;
			scanf("%d", &l);
			Chests[c].LockKey = l;
			scanf("%d", &t);
			for(int k = 0; k < t; k++){
				int u;
				scanf("%d", &u);
				Chests[c].KeysInside.push_back(u);
			}
		}
			
		// OK...
		//DebugPrint(Keys, Chests, "and going to check.");



		list<int> nulllist;
		list<int> ret;

		if(IsImpossible(Keys, Chests)){
			ret = nulllist;
		}else{
			ret = Process(Keys, Chests, Chests.size(), nulllist);
		}

		string s = "";
		if(ret.size() == 0){
			s = "IMPOSSIBLE\n";
		}else{
			for(list<int>::iterator it = ret.begin(); it != ret.end(); it++){
				s += lexical_cast<string>(*it + 1);
				s += " ";
			}
			s[s.size() - 1] = '\n'; 
		}

		printf("Case #%d: %s", i+1, s.c_str());
	}

}
