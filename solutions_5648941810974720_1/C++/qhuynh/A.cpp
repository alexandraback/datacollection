#include <bits/stdc++.h>

using namespace std;

string models[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int sl[256];
int tmpSl[10][256];
std::vector<char> a;

bool stillHave(int id){
	int carry = tmpSl[id][models[id][0]];

	for (int i=0; i< models[id].length(); i++){
		if (sl[models[id][i]] < tmpSl[id][models[id][i]])
			return 0;
	}

	for (int i=0; i< models[id].length(); i++){
		sl[models[id][i]] --;
	}

	return 1;
}

int main(){
	
	freopen("A-large.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int test;
	string s;

	for (int i=0; i <= 9; i++){
		for (int j = 0; j < models[i].length(); j++)
			tmpSl[i][models[i][j]] ++;
	}

	scanf("%d\n", &test);

	for (int t= 0; t < test; t++){
		string res = "";
		getline(cin, s);

		for (char c = 'A'; c <= 'Z'; c++)
			sl[c] = 0;

		for (int i =0; i < s.length(); i++){
			sl[s[i]]++;
			//cout << s[i] << " " << sl[s[i]] << endl;
		}
		
		a.clear();
		
		for (int i=0; i <= 9; i = i + 2){
			while (stillHave(i)){
				a.push_back((char) (i + '0'));
			}
			
		}
		
		for (int i=1; i <= 9; i = i + 2){
			while (stillHave(i)){
				a.push_back((char) (i + '0'));
			}
		}
		res = "";
		sort(a.begin(), a.end());
		for (int i=0; i < a.size(); i++)
			res +=a[i];
		printf("Case #%d: %s\n", t+1, res.c_str());
	}
}