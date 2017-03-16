#include<string>
#include<sstream>
#include<map>
#include<vector>

#include<iostream>
#include<fstream>
using namespace std;
class TrieNode;

class TrieNode {
	public:
	vector<string> words;
	string prefix;
	TrieNode * child['z' + 1];
	TrieNode(){
		for(int c = 'a'; c <='z'; ++c)
			this->child[c] = 0;

	}
};

TrieNode *trie = new TrieNode();
vector<string> dict;
map<string,bool> dict_map;
string garb;
map<string,int> cache2;
int count_changes2(TrieNode* nd, string & word, int pos, int last_change){
	stringstream ss;
	ss << nd->prefix << "," << pos;

	string key = ss.str();
	if(cache2.find(key) != cache2.end())
		return cache2[key];
	if(pos == word.size()){
		for(int i = 0; i < nd->words.size(); ++i){
			if(nd->words[i].size() == word.size())
				return 0;
		}
		return word.size();
	}
	int ans = word.size();
	if(nd->child[word[pos]]){
		int subsol1 = count_changes2(nd->child[word[pos]], word, pos + 1, last_change);
		if(subsol1 < ans) ans = subsol1;
	}
	if(last_change == -1 || pos - last_change >= 5){
		for(char c = 'a'; c <= 'z'; ++c)
			if(c != word[pos] && nd->child[c]){
				int subsol = count_changes2(nd->child[c], word, pos + 1, pos);
				if(subsol + 1 < ans) ans = subsol + 1;
			}
	}
	cache2[key] = ans;
//	cout << nd->prefix << " " << pos << " " << last_change << " " << ans << endl;
	return ans;
}
int count_changes(string word){
	int last_change = -1;
	int ans = word.size();
	if(dict_map[word]) return 0;
	for(int i = 0; i < dict.size(); ++i){
		last_change = -1;
		int changes = 0, j;
		if(word.size() != dict[i].size()) continue;

		for(j = 0; j < word.size(); ++j){
			if(word[j] != dict[i][j]){
				changes++;
				if(last_change != -1) {
					if(j - last_change < 5) break;
				}
				last_change = j;
				if(changes > ans) break;
			}
		}
		if(j == word.size())
			if(changes < ans) ans = changes;
		if(ans == 0) return 0;
	}
	return ans;
}
map<int,int> cache;

int solve(int pos){
	if(pos == garb.size()){
		return 0;
	}
	if(cache.find(pos) != cache.end())
		return cache[pos];
	int ans = garb.size();
	for(int i = pos; i < garb.size(); ++i){
		string word = garb.substr(pos, i - pos + 1);
		cache2.clear();
		int changes = count_changes2(trie, word, 0, -1);
		int subsol = changes + solve(i + 1);
		if(subsol < ans) ans = subsol;
	}
	cache[pos] = ans;
	return ans;
}
int main(){
	ifstream fdict("dict.txt");
	string word;
	while(fdict >> word) {
		dict.push_back(word);
		dict_map[word] = 1;
		TrieNode *nd = trie;
		for(int i = 0; i < word.size(); ++i){
			if(!nd->child[word[i]]){
				nd->child[word[i]] = new TrieNode;			
				nd->child[word[i]]->prefix = nd->prefix + word[i];
			}
			nd = nd->child[word[i]];
		}
		nd->words.push_back(word);
	}
	int T;
	cin >> T;
	for(int c = 1; c <= T; ++c){
		cin >> garb;
		cache.clear();
		cout << "Case #" << c << ": " << solve(0) << endl;
	}
	return 0;
}
