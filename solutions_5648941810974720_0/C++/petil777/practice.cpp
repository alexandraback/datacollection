#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
string str;
int test;
int al[26];
vector<int> ans;
void out(char tt)
{
	--al[tt - 'A'];
}
int main(){
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A1.txt", "w", stdout);

	cin >> test;
	int lev = 0;
	while (test--){
		++lev;
		cin >> str;
		ans.clear();
		for (int i = 0; i < 26; i++)al[i] = 0;
		for (int i = 0; i < str.size(); i++){
			al[str[i] - 'A']++;
		}
		//
		while (al['X' - 'A']){
			out('S'); out('I'); out('X');
		 ans.push_back(6);
			
		}
		//
		while (al['G' - 'A']){
			out('E'); out('I'); out('G'); out('H'); out('T');
			ans.push_back(8);
		}
		//
		while (al['Z' - 'A']){
			out('Z'); out('E'); out('R'); out('O');
			ans.push_back(0);
		}
		//
		while (al['W' - 'A']){
			out('T'); out('W'); out('O');
			ans.push_back(2);
		}
		while ( al['U' - 'A']){
			out('F'); out('O'); out('U'); out('R');
			ans.push_back(4);
		}

			///////////////////////////////////////////////////////
		while (al['O' - 'A']){
			out('O'); out('N'); out('E');
			ans.push_back(1);
		}
		while (al['F' - 'A']){
			out('F'); out('I'); out('V'); out('E');
			ans.push_back(5);
		}

		while (al['S' - 'A']){
			out('S'); out('E'); out('V'); out('E'); out('N');
			ans.push_back(7);
		}

		while (al['H' - 'A']){
			out('T'); out('H'); out('R'); out('E'); out('E');
			ans.push_back(3);
		}
		while (al['N' - 'A'] && al['I' - 'A']){
			out('N'); out('I'); out('N'); out('E');
			ans.push_back(9);
		}
		
		
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", lev);
		for (int i = 0; i < ans.size(); i++)cout << ans[i];
		cout << endl;
	}


}