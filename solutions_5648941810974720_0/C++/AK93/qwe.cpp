#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

string arr[10] = {
	"ZERO", "SIX", "EIGHT", "FOUR", "FIVE", "TWO", "SEVEN", "ONE", "THREE", "NINE"
};

char arr2[10] = {
	'Z', 'X', 'G', 'U', 'F', 'W', 'S', 'O', 'T', 'I'
};

int numb[10] = {
	0, 6, 8, 4, 5, 2, 7, 1, 3, 9
};

int main(){

#ifdef _CONSOLE
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int countTest;
	cin>>countTest;


	for(int test = 1; test <= countTest; test++){
		string str;
		vector<int> res;
		cin>>str;
		map<char, int> mp;

		for(int i=0; i<str.size(); i++){
			char ch = str[i];
			mp[ch]++;
		}

		for(int i=0; i<10; i++){
			char ch = arr2[i];
			int cnt = mp[ch];
			for(int j=0; j<cnt; j++){
				res.push_back(numb[i]);
			}
			for(int j=0; j<arr[i].size(); j++){
				char ch2 = arr[i][j];
				int cnt2 = mp[ch2];
				cnt2 -= cnt;
				if(cnt2 != 0)
					mp[ch2] = cnt2;
				else{
					mp.erase(ch2);
				}
			}
		}

		sort(res.begin(), res.end());
		printf("Case #%d: ", test);
		for(int i=0; i<res.size(); i++){
			printf("%d", res[i]);
		}
		printf("\n");
	}
	

	
	return 0;
}

