#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#define ll long long

using namespace std;

vector<string> getAll(string s)
{
	int p1, p2, p3;
	p1 = p2 = p3 = 0;
	if(s[0] == '?')
		p1 = 1;
	if(s[1] == '?')
		p2 = 1;
	if(s[2] == '?')
		p3 = 1;
	int cnt = p1 + p2 + p3;
	vector<string> ans;
	if(cnt == 1){
		for(int i = 0; i < 10; ++i){
			string st(s);
			if(p1)
				st[0] = '0' + i;
			else if(p2)
				st[1] = '0' + i;
			else
				st[2] = '0' +i;
			ans.push_back(st);
		}
	}
	else if(cnt == 2){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				string st(s);
				if(p1 && p2){
					st[0] = '0' +i; st[1] = '0' +j;
				}
				else if(p1 && p3){
					st[0] = '0' +i; st[2] = '0' +j;
				}
				else{
					st[1] = '0' +i; st[2] = '0' +j;
				}
				ans.push_back(st);
			}
		}

	}
	else if(cnt == 3){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				for(int k = 0; k < 10; ++k){
					string st(s);
					st[0] = '0' +i; st[1] = '0' +j; st[2] = '0' +k;
					ans.push_back(st);
				}
			}
		}
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		string s1, s2;
		cin >> s1;
		cin >> s2;
		vector<string> coll_s1, coll_s2;
		coll_s1 = getAll(s1);
		coll_s2 = getAll(s2);
		/*for(int i = 0; i < coll_s1.size(); ++i)
			cout << coll_s1[i] << endl;
		for(int i = 0; i < coll_s2.size(); ++i)
			cout << coll_s2[i] << endl;*/
		vector<pair<int,string> > num_1, num_2;
		for(int i = 0; i < coll_s1.size(); ++i){
			string s = coll_s1[i];
			int t = 0, sz = s.size();
			while(t < sz && s[t] == '0')
				++t;
			if(t == sz)
				num_1.push_back(make_pair(0,s));
			else{
				string tmp(s.begin()+t, s.end());
				int num = stoi(tmp);
				num_1.push_back(make_pair(num,s));
			}
			//cout << "i = " << i << endl;
		}
		for(int i = 0; i < coll_s2.size(); ++i){
			string s = coll_s2[i];
			int t = 0, sz = s.size();
			while(t < sz && s[t] == '0')
				++t;
			
			if(t == sz)
				num_2.push_back(make_pair(0,s));
			else{
				string tmp(s.begin()+t, s.end());
				int num = stoi(tmp);
				num_2.push_back(make_pair(num,s));
			}
		}
		if(num_1.size() == 0){
			num_1.push_back(make_pair(stoi(s1),s1));
		}
		if(num_2.size() == 0)
			num_2.push_back(make_pair(stoi(s2),s2));
		/*for(int i = 0; i < num_1.size(); ++i)
			cout << num_1[i].first << endl;
		for(int i = 0; i < num_2.size(); ++i)
			cout << num_2[i].first << endl;*/
		int min_diff = 10000, min_idx_i, min_idx_j;
		for(int i = 0; i < num_1.size(); ++i){
			for(int j = 0; j < num_2.size(); ++j){
				int diff = num_1[i].first - num_2[j].first;
				if(diff < 0)
					diff *= -1;
				if(diff < min_diff){
					//cout << diff << " " << num_1[i].first << " " << num_2[j].first << endl;
					min_diff = diff;
					min_idx_i = i;
					min_idx_j = j;
				}
			}
		}
		if(num_1.size() == 0){
			if(num_2.size() == 0){
				cout << "Case #" << t << ": " << s1 << " " << s2 << endl;
			}
			else{
				cout << "Case #" << t << ": " << s1 << " " << s1 << endl;
			}
		}
		else if(num_2.size() == 0){
			cout << "Case #" << t << ": " << s2 << " " << s2 << endl;
		}
		else
			cout << "Case #" << t << ": " << num_1[min_idx_i].second << " " << num_2[min_idx_j].second << endl;
	}
	return 0;
}