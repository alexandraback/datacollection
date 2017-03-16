#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Linklist
{
	int val;
	Linklist* next;
	Linklist(int x): val(x), next(NULL) {}
};

int dfs(unordered_map<int, Linklist* >& friends, unordered_map<int, vector<int> >& friends2, int f, unordered_map<int, int>& iteral) {
	if(iteral.find(f) != iteral.end()) {
		// cout<<"hello"<<" "<<f<<endl;
		return iteral[f];
	}
	// cout<<f<<endl;
	if (friends2[f].size() == 0)
	{
		// cout<<"h"<<endl;
		iteral.insert(pair<int, int>(f, 0));
		return 0;
	}
	else {
		int result = 0;
		// cout<<f<<" "<<friends2[f].size()<<endl;
		for (int i = 0; i < friends2[f].size(); ++i)
		{
			
			if(friends[f]->next->val != friends2[f][i]){
				cout<<"friends "<<f<<" "<<i<<" "<<friends2[f][i]<<endl;
				result = max(result, 1+dfs(friends, friends2, friends2[f][i], iteral));
			}
				
			// cout<<result<<endl;
		}
		iteral.insert(pair<int, int>(f, result));
		// cout<<result<<endl;
		return result;
	}
}

int main() {
	ifstream in("in.txt");
	ofstream out("out2.txt");

	int T = 0;
	in >> T;
	for (int i = 1; i <= T; ++i)
	{
		int N = 0;
		in >> N;
		
		unordered_map<int, Linklist*> friends;
		unordered_map<int, vector<int> > friends2;
		for (int j = 0; j < N; ++j)
		{
			Linklist* tmp = new Linklist(j+1);
			vector<int> tmp2;
			friends2.insert(pair<int, vector<int> >(j+1, tmp2));
			friends.insert(pair<int, Linklist*>(j+1, tmp));
		}
		int f = 0;
		for (int j = 0; j < N; ++j)
		{
			in >> f;
			friends2[f].push_back(j+1);
			friends[j+1]->next = friends[f];
		}
		int result = 0;
		unordered_map<int, int> iteral;
		for (int j = 0; j < N; ++j)
		{
			if (friends[j+1]->val == friends[j+1]->next->next->val)
			{
				int right = dfs(friends, friends2, friends[j+1]->val, iteral);
				int left = dfs(friends, friends2, friends[j+1]->next->val, iteral);
				// if(left > 0) right++;
				// if(right > 1) left++;
				result = max(result, left+right+2);
			}
		}
		cout<<result<<endl;
		while(!friends.empty()) {
			Linklist* head = friends.begin()->second;
			Linklist* fast = head;
			Linklist* slow = head;
			if(friends.find(slow->val)!=friends.end())friends.erase(slow->val);
			int flag = 0;
			while(fast && fast->next) {
				fast = fast->next->next;
				slow = slow->next;
				if(friends.find(slow->val)!=friends.end())friends.erase(slow->val);
				
				if(slow == fast) {
					Linklist* slow2 = head;
					while(slow2 != slow) {
						slow2 = slow2->next;
						slow = slow->next;
					}
					slow2 = slow;
					int result2 = 1;
					slow = slow->next;
					while(slow != slow2) {
						result2++;
						slow = slow->next;
					}
					result = max(result, result2);
					flag = 1;
					break;
				}
			}
			if(flag == 0) break;
		}
		out<<"Case #"<<i<<": "<<result<<endl;

	}
}