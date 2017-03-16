#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <queue>

using namespace std;

map<set<char>, int> st;

void init(){
	set<char> s;
	s.insert('X');
	st.insert(make_pair(s, 2));
	s.insert('O');
	st.insert(make_pair(s, 1));
	s.erase('O');
	s.insert('T');
	st.insert(make_pair(s, 2));
	s.insert('O');
	st.insert(make_pair(s, 1));
	s.erase('X');
	st.insert(make_pair(s, 3));
	s.erase('T');
	st.insert(make_pair(s, 3));
}

int check(vector<vector<char> > mp){
	int res=0;
	for(int i=0; i<4; i++){
		set<char> s;
		int state=0;
		for(int j=0; j<4; j++){
			if(mp[i][j] == '.'){
				state=-1;
				break;
			}
			s.insert(mp[i][j]);
		}
		if(state == -1){
			res=0;
			continue;
		}
		else{
			res=st[s];
		}
		if(res == 2 || res == 3)
			return res;
	}

	for(int i=0; i<4; i++){
		set<char> s;
		int state=0;
		for(int j=0; j<4; j++){
			if(mp[j][i] == '.'){
				state=-1;
				break;
			}
			s.insert(mp[j][i]);
		}
		if(state == -1){
			res=0;
			continue;
		}
		else{
			res=st[s];
		}
		if(res == 2 || res == 3)
			return res;
	}

	set<char> s;
	int state=0;
	for(int i=0; i<4; i++){
		if(mp[i][i] == '.'){
			state=-1;
			break;
		}
		s.insert(mp[i][i]);
	}
	if(state == -1){
		res=0;
	}
	else{
		res=st[s];
	}
	if(res == 2 || res == 3)
		return res;

	state=0;
	s.clear();
	for(int i=0; i<4; i++){
		if(mp[i][3-i] == '.'){
			state=-1;
			break;
		}
		s.insert(mp[i][3-i]);
	}
	if(state == -1){
		res=0;
	}
	else{
		res=st[s];
	}
	if(res == 2 || res == 3)
		return res;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++)
			if(mp[i][j] == '.')
				res=0;
	}
	return res;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	int n;
	cin>>n;
	for(int t=0; t<n; t++){
		vector<vector<char> > arr(4, vector<char> (4));
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cin>>arr[i][j];
			}
		}
		int res=check(arr);
		cout<<"Case #"<<t+1<<": ";
		if(res == 0)
			cout<<"Game has not completed\n";
		if(res == 1)
			cout<<"Draw\n";
		if(res == 2)
			cout<<"X won\n";
		if(res == 3)
			cout<<"O won\n";
	}
	return 0;
}