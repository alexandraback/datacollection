#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define LL long long

const LL M = 1000000007;

char in[12000];

int m[30];
int l[30];
int r[30];
int f[30];


struct cart {
	char st;
	char en;
	char lsen;
	bool hmg;
};

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int k = 1; k <= T; k++) {
		printf("Case #%d: ", k);
		
		LL pos = 1;
		
		int N;
		scanf("%d ", &N);
		
		memset(in, 0, sizeof(in));
		fgets(in, 12000, stdin);
		
		vector<cart> cr;
		
		memset(m, 0, sizeof(m));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(f, 0, sizeof(f));
		
		int i = 0;
		int p = 0;
		cart c;
		c.st = 0;
		c.en = 0;
		c.lsen = 0;
		c.hmg = true;
		while(i < N) {
			if(in[p] <= 'z' && in[p] >= 'a') {
				if(c.st == 0) {
					c.st = in[p];
					l[in[p]-'a']++;
				} else {
					if(in[p] != c.en) {
						if(c.lsen != 0) {
							m[c.en-'a']++;
						}
						c.lsen = c.en;
						c.hmg = false;
					}	
				}
				c.en = in[p];
			} else {
				if(c.hmg) {
					l[c.en-'a']--;
					f[c.en-'a']++;
				} else {
					r[c.en-'a']++;
					cr.push_back(c);
					if(c.st == c.en) pos = 0;
				}
				c.st = 0;
				c.lsen = 0;
				c.hmg = true;
				i++;
			}
			p++;
		}
		
		/*printf("pos == %lld\n", pos);
		for(int i = 0; i < 26; i++) {
			printf("%c: l %d, r %d, f %d, m %d\n", (char)(i+'a'), l[i], r[i], f[i], m[i]);
		}*/
		
		for(int i = 0; i < 26; i++) {
			if(l[i] > 1) pos = 0;
			if(r[i] > 1) pos = 0;
			if(m[i] > 0 && (l[i]+r[i]+f[i]) > 0) pos = 0; 
			if(m[i] > 1) pos = 0;
		}
		
		if(pos == 0) {
			printf("0\n");
			continue;
		}
		
		int num = (int) cr.size();
		
		for(int i = 0; i < (int) cr.size(); i++) {
			if(r[cr[i].st-'a'] > 0) {
				for(int j = 0; j < (int) cr.size(); j++) {
					if(i == j) continue;
					if(cr[j].en == cr[i].st) {
						cr[j].en = cr[i].en;
						cr[i].en = 0;
						break;
					}
				}
				num--;
			}
		}
		
		for(int i = 0; i < (int) cr.size(); i++) { 
			if(cr[i].en == cr[i].st) {
				pos = 0;
			}
		}
		
		if(pos == 0) {
			printf("0\n");
			continue;
		}
		
		for(int i = 0; i < 26; i++) {
			if(f[i] > 0 && l[i]+r[i] == 0) num++;
			
			while(f[i] > 0) {
				pos = (pos*f[i])%M;
				f[i]--;
			}
		}
		
		while(num > 0) {
			pos = (pos*num)%M;
			num--;
		}
		
		printf("%lld\n", pos);
	}
	
	return 0;
}
