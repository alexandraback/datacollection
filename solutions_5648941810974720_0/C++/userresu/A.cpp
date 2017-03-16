#include <cstdio>
#include <cstring>
using namespace std;

char s[2001];
int freq[256];
const char nums[10][10] = {"ZERO","TWO","EIGHT","THREE","SIX","FOUR","FIVE","NINE","SEVEN","ONE"};
char ch[10];
int wh[10] = {0,2,8,3,6,4,5,9,7,1};
int cnt[10];
int main () {
	int T;
	scanf("%d",&T);
	ch[0]='Z';
	ch[1]='W';
	ch[2]='G';
	ch[3]='H';
	ch[4]='X';
	ch[5]='R';
	ch[6]='F';
	ch[7]='I';
	ch[8]='S';
	ch[9]='N';
	for (int z=1;z<=T;++z) {
		scanf("%s",s);
		for (int i='A';i<='Z';++i) freq[i] = 0;
		for (int i=0;i<10;++i) cnt[i] =0;
		int n = strlen(s);
		for (int i=0;i<n;++i) ++freq[s[i]];
		for (int i=0;i<10;++i) if (freq[ch[i]]) {
			int v = freq[ch[i]];
			int x = strlen(nums[i]);
			for (int j=0;j<x;++j) freq[nums[i][j]] -= v;
			cnt[wh[i]] = v;
		}
		printf("Case #%d: ",z);
		for (int i=0;i<10;++i) for (int j=0;j<cnt[i];++j) printf("%d",i);
		printf("\n");
	}
	return 0;
}
