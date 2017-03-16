#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int t,i,j,k,cnt[305];
char s[2005];
vector <int> ans;

int main(){
	scanf("%d", &t);
	int testcase = 0;
	while(++testcase <= t){
		ans.clear();
		scanf("%s", s);
		int l = strlen(s);
		for(i = 0; i < l; i++)
		cnt[s[i]]++;
		while(cnt['Z']){
			cnt['Z']--;
			cnt['E']--;
			cnt['R']--;
			cnt['O']--;
			ans.push_back(0);
		}
		while(cnt['X']){
			cnt['S']--;
			cnt['I']--;
			cnt['X']--;
			ans.push_back(6);
		}
		while(cnt['G']){
			cnt['E']--;
			cnt['I']--;
			cnt['G']--;
			cnt['H']--;
			cnt['T']--;
			ans.push_back(8);
		}
		while(cnt['U']){
			cnt['F']--;
			cnt['O']--;
			cnt['U']--;
			cnt['R']--;
			ans.push_back(4);
		}
		while(cnt['F']){
			cnt['F']--;
			cnt['I']--;
			cnt['V']--;
			cnt['E']--;
			ans.push_back(5);
		}
		while(cnt['V']){
			cnt['S']--;
			cnt['E']--;
			cnt['V']--;
			cnt['E']--;
			cnt['N']--;
			ans.push_back(7);
		}
		while(cnt['I']){
			cnt['N']--;
			cnt['I']--;
			cnt['N']--;
			cnt['E']--;
			ans.push_back(9);
		}
		while(cnt['N']){
			cnt['O']--;
			cnt['N']--;
			cnt['E']--;
			ans.push_back(1);
		}
		while(cnt['O']){
			cnt['T']--;
			cnt['W']--;
			cnt['O']--;
			ans.push_back(2);
		}
		while(cnt['T']){
			cnt['T']--;
			cnt['H']--;
			cnt['R']--;
			cnt['E']--;
			cnt['E']--;
			ans.push_back(3);
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", testcase);
		for(i = 0; i < ans.size(); i++)
		printf("%d", ans[i]);
		printf("\n");
	}
}

