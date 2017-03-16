#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <hash_map>

using namespace std;
typedef long long ll;

int arr1[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};

int arr2[4][4] = {
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

bool slow(int n, int m, string str){
	string s;
	for(int i=0; i<m; i++)
		s += str;
	int sz = s.size();
	for(int i=0; i<sz; i++){
		if(s[i] == 'i')
			s[i] = '1';
		else{
			if(s[i] == 'j')
				s[i] = '2';
			else
				s[i] = '3';
		}
	}
	vector<vector<int> > arr(sz, vector<int> (sz, 0));
	for(int i=0; i<sz; i++){
		bool fl = true;
		int numb = 0;
		for(int j=i; j<sz; j++){
			int buf = s[j] - '0';
			int next = arr1[numb][buf];
			if(arr2[numb][buf])
				fl = !fl;
			numb = next;
			if(fl && numb != 0)
				arr[i][j] = numb;
		}
	}
	
	for(int i=0; i<sz; i++){
		if(arr[0][i] == 1){
			for(int j=i+1; j<sz-1; j++){
				if(arr[i+1][j] == 2 && arr[j+1][sz-1] == 3)
					return true;
			}
		}
	}

	return false;
}

void print(int test, bool res){
	cout<<"Case #"<<test + 1<<": ";
	if(res)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test_count;
	cin>>test_count;
	for(int test=0; test<test_count; test++){
		int n, m;
		string str;
		cin>>n>>m>>str;
		bool res = slow(n, m, str);
		print(test, res);
		cerr<<test+1<<endl;
	}
    return 0;
}
