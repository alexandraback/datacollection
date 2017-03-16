#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int, int>
using namespace std;
string s,p;
int T,n,k;

string split(string s, char ch){
	string res = "";
	char p = s[0];
	if(s[0] == '-'){
		res += s[0];
		p = s[1];
	}
	if(p == '1'){
		res += ch;
	}
	else if(p == 'i'){
		if(ch == '1') res += 'i';
		if(ch == 'i'){
			if(res.size() == 0){
				res = "-1";
			}
			else{
				res = "1";
			}
		}
		if(ch == 'j'){
			res += 'k';
		}
		if(ch == 'k'){
			if(res.size() == 0) res = "-j";
			else res = "j";
		}
	}
	else if(p == 'j'){
		if(ch == '1') res += 'j';
		if(ch == 'j'){
			if(res.size() == 0){
				res = "-1";
			}
			else{
				res = "1";
			}
		}
		if(ch == 'i'){
			if(res.size() == 0) res = "-k";
			else res = "k";	
		}
		if(ch == 'k'){
			res += 'i';
		}
	}
	else if(p == 'k'){
		if(ch == '1') res += 'k';
		if(ch == 'k'){
			if(res.size() == 0){
				res = "-1";
			}
			else{
				res = "1";
			}
		}
		if(ch == 'i'){
			res += 'j';
		}
		if(ch == 'j'){
			if(res.size() == 0) res = "-i";
			else res = "i";
		}
	}
	return res;
}     

int main () {
	freopen ("C-small-attempt0.in","r",stdin);
	freopen ("output.txt","w",stdout);
	cin >> T;
	for(int t=1;t<=T;t++){
		cin >> n >> k;
		printf("Case #%d: ",t);
		n = n * k;
		cin >> p;
		s = p;
		for(int i=1;i<k;i++){
			s += p;	
		}
		int i = 0;
		bool ok = 0;
		string cur = "1";
		while(i < n){
			cur = split(cur,s[i]);
			
			i++;
			if(cur == "i"){
				ok = 1;
				break;
			}
		}
		if(!ok){
			puts("NO");
			continue;
		}
		ok = 0;
		cur = "1";
		while(i < n){
			cur = split(cur,s[i]);
			i++;
			if(cur == "j"){
				ok = 1;
				break;
			}
		}
		if(!ok){
			puts("NO");
			continue;
		}
		ok = 0;
		cur = "1";
		while(i < n){
			cur = split(cur,s[i]);
			i++;
		}
		if(cur != "k") puts("NO");
		else puts("YES");

	}
return 0;
}