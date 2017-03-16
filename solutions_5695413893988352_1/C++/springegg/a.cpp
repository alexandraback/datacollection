#include <iostream>
#include <vector>
using namespace std;


int count(const string &s, char ch)
{
	int result = 0;
	for(int i = 0; i < s.size(); ++i) if(s[i] == ch) {
		++result;
	}
	return result;

}

string bs1, bs2;
long long bd, b1, b2;

long long getNumber(const string &s){
	long long res = 0;
	for(int i = 0; i < s.size(); ++i){
		res = res * 10 + s[i] - '0';
	}
	return res;
}

void dfs(int i, string &s1, string &s2, int now_flag)
{
	if(i >= s1.size()) {
		long long t1 = getNumber(s1), t2 = getNumber(s2), td = t1 - t2;
		if (td < 0) td = -td;
		if (bd < 0 || td < bd || td == bd && t1 < b1 || td == bd && t1 == b1 && t2 < b2){
			bs1 = s1;
			bs2 = s2;
			bd = td;
			b1 = t1;
			b2 = t2;
		}
		return;
	}
	if(s1[i] == '?' && s2[i] == '?'){
		if(now_flag == 0){
			s1[i] = s2[i] = '0';
			dfs(i+1, s1, s2, 0);
			s1[i] = '0'; s2[i] = '1';
			dfs(i+1, s1, s2, -1);
			s1[i] = '1'; s2[i] = '0';
			dfs(i+1, s1, s2, 1);
		}else if (now_flag == -1){
			s1[i] = '9';
			s2[i] = '0';
			dfs(i+1, s1, s2, now_flag);
		}else{
			s1[i] = '0';
			s2[i] = '9';
			dfs(i+1, s1, s2, now_flag);
		}
		s1[i] = s2[i] = '?';
	} else if(s1[i] != '?' && s2[i] != '?'){
		if (now_flag == 0){
			if(s1[i] < s2[i]){
				now_flag = -1;
			}else if(s1[i] > s2[i]){
				now_flag = 1;
			}
		}
		dfs(i+1, s1, s2, now_flag);
	} else{ 
		if(s1[i] == '?'){
			if(now_flag == 0){
				s1[i] = s2[i];
				dfs(i+1, s1, s2, 0);
				if(s2[i] > '0'){
					s1[i] = s2[i] - 1;
					dfs(i+1, s1, s2, -1);
				}
				if(s2[i] < '9'){
					s1[i] = s2[i] + 1;
					dfs(i+1, s1, s2, 1);
				}
			}else if(now_flag == -1){
				s1[i] = '9';
				dfs(i+1, s1, s2, now_flag);
			} else {
				s1[i] = '0';
				dfs(i+1, s1, s2, now_flag);
			}
			s1[i] = '?';
		} else {
			if(now_flag == 0){
				s2[i] = s1[i];
				dfs(i+1, s1, s2, 0);
				if(s1[i] > '0'){
					s2[i] = s1[i] - 1;
					dfs(i+1, s1, s2, 1);
				}
				if(s1[i] < '9'){
					s2[i] = s1[i] + 1;
					dfs(i+1, s1, s2, -1);
				}
			}else if(now_flag == -1){
				s2[i] = '0';
				dfs(i+1, s1, s2, now_flag);
			} else {
				s2[i] = '9';
				dfs(i+1, s1, s2, now_flag);
			}
			s2[i] = '?';
		}

	}

}

void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	bd = -1;
	dfs(0, s1, s2, 0);
	cout << bs1 << " " << bs2 << endl;
}

int main() 
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
