#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000000 + 100;
const int inf = 0x7fffffff;

/// a, e, i, o, and u
bool is_vowel(char c){
	if(c == 'a' || c == 'e' ||  c == 'i' ||  c == 'o' ||  c == 'u')
		return true;
	return false;
	}

int solve(string s, int g){
	int nextc[MAXN];
	
	int is_eiles = 0;
	for(int i = s.size()-1; i >= 0; i--){
		if(!is_vowel(s[i]))
			is_eiles++;
		else
			is_eiles = 0;
			
		if(is_eiles >= g)
			nextc[i] = i + g;
		else if(i + 1 != s.size())
			nextc[i] = nextc[i+1];
			else
				nextc[i] = -1;
		}
	
	int answ = 0;
	for(int i = 0; i < s.size(); i++){
		if(nextc[i] != -1)
			answ += s.size() - nextc[i] + 1;
		//~ cout << answ << endl;
		}
	return answ;
	}

int main(){
	int testcases;
	scanf("%d", &testcases);
	
	for(int testcase = 0; testcase < testcases; testcase++){
		string s;
		cin >> s;
		int cluster;
		scanf("%d", &cluster);
		
		printf("Case #%d: %d\n", testcase+1, solve(s, cluster));
		}
	
	
	return 0;
}
