#include <cstdio>
#include <string>
#include <tuple>
#include <algorithm>
int ans;
std::string s, j;
std::string ans_s, ans_j;
int _stoi(std::string s){
	int n1 = 0;
	for (int i = 0; i < s.size(); i++){
		n1 = n1 * 10 + s[i] - '0';
	}
	return n1;
}
void find_ans(std::string s1, std::string s2, int depth){
	if (depth == s.size()){
		int n1 = _stoi(s1), n2 = _stoi(s2);
		int nj = 0;
		
		if (ans > std::abs(n1- n2)){
			ans = std::abs(n1 - n2);
			ans_s = s1;
			ans_j = s2;
		}
		else if (ans == std::abs(n1 - n2)){
			int ni = _stoi(ans_s);
			int nj = _stoi(ans_j);
			if (std::make_tuple(ni, nj) > std::make_tuple(n1, n2)){
				ans_s = s1;
				ans_j = s2;
			}
		}
		return;
	}
	std::string tmp;
	if(s[depth] != '?') s1 += s[depth];
	if(j[depth] != '?') s2 += j[depth];

	if (s[depth] == '?' && j[depth] == '?'){
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) 
			find_ans(s1 + (char)('0' + i),s2 + (char)('0' + j), depth + 1);
	}
	else if (s[depth] == '?'){
		for (int i = 0; i < 10; i++) find_ans(s1 + (char)('0' + i), s2, depth + 1);
	}
	else if (j[depth] == '?')
	{
		for (int i = 0; i < 10; i++) find_ans(s1, s2 + (char)('0' + i), depth + 1);
	}
	else
		find_ans(s1, s2, depth + 1);
}
int main(void){
	int T;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("BSoutput", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		printf("Case #%d: ", t);
		char tmp1[10], tmp2[10];
		scanf("%s%s", tmp1, tmp2);
		s = tmp1; j = tmp2;
		ans_s = "";
		ans_j = "";
		ans = 1234567890;
		find_ans("", "", 0);
		printf("%s %s\n", ans_s.c_str(), ans_j.c_str());
	}
}