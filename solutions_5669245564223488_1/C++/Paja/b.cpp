#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int MAXN = 100005;
const int MAXM = 205;
const long long MOD = 1000000007;

long long fakt[MAXM];

bool one_letter(const string & s){
	char let = s[0];
	for(int i = 0; i < s.size(); i++)
		if(s[i] != let)
			return false;
	return true;
	}

bool check(const string & s){
	//~ cout << s << endl;
	int last[MAXM];
	fill(last, last + MAXM, -1);
	
	for(int i = 0; i < s.size(); i++){
		if(last[s[i]-'a'] != -1 && last[s[i]-'a'] != i - 1)
				return false;
		last[s[i]-'a'] = i;
		}
	return true;
	}

void solve(int test){
	vector<string> eil;
	bool taken[MAXN];
	bool one[MAXN];
	
	int n;
	scanf("%d\n", &n);
	
	string st;
	for(int i = 0; i < n; i++)
		cin >> st, eil.push_back(st);
	
	for(int i = 0; i < n; i++)
		one[i] = one_letter(eil[i]), taken[i] = false;
	
	long long answ = 1;
	
	for(char c = 'a'; c <= 'z'; c++){
		int to = eil.size();
		string t = "";
		int same = 0;
		
		for(int j = 0; j < to; j++)
			if(!taken[j]){
				if(eil[j][0] != c && eil[j][eil[j].size()-1] == c)
					t = eil[j] + t, taken[j] = true;
				if(eil[j][0] == c && eil[j][eil[j].size()-1] != c)
					t = t+eil[j], taken[j] = true;
				if(eil[j][0] == c && eil[j][eil[j].size()-1] == c && one[j]){
					taken[j] = true, same++;
					if(t == "") t += eil[j];
					}
				}
		if(t != ""){
				answ *= fakt[same], answ %= MOD;
				
				one[eil.size()] = one_letter(t);
				taken[eil.size()] = false;
				eil.push_back(t);
				//~ cout << c << " " << t << endl;
			}
		}
	//~ cout << "--" << endl;
	//~ for(int i = 0; i < eil.size(); i++)
		//~ cout << eil[i] << " " << taken[i] << endl;
	
	int sm = 0;
	for(int i = 0; i < eil.size(); i++)
		sm += !taken[i];
	answ *= fakt[sm], answ %= MOD;
	
	string giant ="";
	for(int i = 0; i < eil.size(); i++)
		if(!taken[i])
			giant += eil[i];
	
	if(check(giant))
		printf("Case #%d: %lld\n", test, answ);
	else
		printf("Case #%d: %d\n", test, 0);
	}

int main(){	
	int testcases;
	scanf("%d", &testcases);
	
	fakt[0] = 1;
	for(int i = 1; i < MAXM; i++)
		fakt[i] = fakt[i-1]*i, fakt[i] %= MOD;
	
	for(int test = 0; test < testcases; test++)
		solve(test+1);
	
	return 0;
}
