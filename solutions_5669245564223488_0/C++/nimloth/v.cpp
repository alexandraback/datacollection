#pragma comment(linker, "/STACK:65777216")
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stdio.h>
#include <deque>
#include <map>
#include <set>
#include <stack>
  
using namespace std;
  
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
  
typedef long long li;
typedef unsigned long long uli;

li P = 1e9 + 7;

string s[105];
li l[105];
li cnt[105];
li fak[105];
multiset <string> S;
bool used[105];

bool check(string g){
	memset(used, 0, sizeof(used));
	li len = g.length();
	li i;
	for(i = 0; i < len; i++)
		if(!used[g[i] - 'a'])
			used[g[i] - 'a'] = true;
		else{
			if(g[i - 1] != g[i])
				return false;
		}
	return true;
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	//cout.setf(ios::fixed);
	//cout.precision(7);
	li op;
	fak[0] = 1;
	for(op = 1; op < 104; op++)
		fak[op] = (fak[op - 1] * op) % P;
	li t;
	cin >> t;
	li z;
	for(z = 0; z < t; z++){
		memset(cnt, 0, sizeof(0));
		memset(l, 0, sizeof(l));
		li n;
		cin >> n;
		li i, j;
		for(i = 0; i < n; i++){
			cin >> s[i];
			S.insert(s[i]);
			l[i] = s[i].length();
			char fl = s[i][0];
			char help = 0;
			for(j = 0; j < l[i]; j++){
				if(s[i][j] != fl)
					help = 1;
			}
			if(help == 0)
				cnt[fl - 'a']++;
		}
		string cur = *(S.begin());
		string w = cur;
		char curletter = cur[cur.length() - 1];
		S.erase(S.begin());
		li k = 0;
		while(!S.empty()){
			string cop = *(S.begin());
			if(curletter != cop[0])
				k++;
			cur = cop;
			curletter = cur[cur.length() - 1];
			w += cur;
			S.erase(S.begin());
		}
		//cout << w << " " << k << "\n";
		li ans = 1;
		if(!check(w))
			cout << "Case #" << z + 1 << ": " << 0 << "\n";
		else{
			for(i = 0; i < 103; i++)
				ans = (ans * fak[cnt[i]]) % P;
			ans = (ans * fak[k + 1]) % P;
			cout << "Case #" << z + 1 << ": " << ans << "\n";
		}
	}
	return 0;
}
/*

*/