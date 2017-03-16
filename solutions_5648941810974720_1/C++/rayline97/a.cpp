#include <cstdio>
#include <map>
#include <cstring>
using std::map;

int cnt[10];

int main(){
	char s[2086];
	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		map<char,int> m;
		scanf("%s",s);
		int n = strlen(s);
		for(int i=0;i<n;i++){
			m[s[i]]++;
		}
		printf("Case #%d: ", Case);
		for(int i=0;i<10;i++)cnt[i] = 0;
		while(m['Z']&&m['E']&&m['R']&&m['O']){
			cnt[0]++;
			m['Z']--;
			m['E']--;
			m['R']--;
			m['O']--;
		}
		while(m['S']&&m['I']&&m['X']){
			cnt[6]++;
			m['S']--;
			m['I']--;
			m['X']--;
		}
		while(m['T']&&m['W']&&m['O']){
			cnt[2]++;
			m['T']--;
			m['W']--;
			m['O']--;
		}
		while(m['E']&&m['I']&&m['G']&&m['H']&&m['T']){
			cnt[8]++;
			m['E']--;
			m['I']--;
			m['G']--;
			m['H']--;
			m['T']--;
		}
		while(m['T']&&m['H']&&m['R']&&m['E']>=2){
			cnt[3]++;
			m['T']--;
			m['H']--;
			m['R']--;
			m['E']-=2;
		}
		while(m['F']&&m['O']&&m['U']&&m['R']){
			cnt[4]++;
			m['F']--;
			m['O']--;
			m['U']--;
			m['R']--;
		}
		while(m['O']&&m['N']&&m['E']){
			cnt[1]++;
			m['O']--;
			m['N']--;
			m['E']--;
		}
		while(m['S']&&m['E']>=2&&m['V']&&m['N']){
			cnt[7]++;
			m['S']--;
			m['E']-=2;
			m['V']--;
			m['N']--;
		}
		while(m['F']&&m['I']&&m['V']&&m['E']){
			cnt[5]++;
			m['F']--;
			m['I']--;
			m['V']--;
			m['E']--;
		}
		while(m['N']>=2&&m['I']&&m['E']){
			cnt[9]++;
			m['N']-=2;
			m['I']--;
			m['E']--;
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<cnt[i];j++)putchar(i+'0');
		}
		putchar('\n');
	}
}