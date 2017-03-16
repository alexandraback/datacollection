#include<iostream>
#include<math.h>
using namespace std;
bool hash[26];
char s[1000];
int L;
bool check(int st, int ed)
{
    int pos = st;
    while(pos <= ed) {
        if(hash[s[pos] - 'a'] == true) {
            int ct = 0; 
            int temp = pos;
            while(pos <= ed && hash[s[pos] - 'a'] == true) {
                ct++;
                pos++;
            }
            if(ct >= L) {
                //printf("=%d %d=\n", temp, pos);
                return true;
            }
        }
        else {
            pos++;
        }
    }
    return false;
}
int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("outA.txt", "w", stdout);
	char ch[5] = {'a', 'e', 'i', 'o', 'u'};
	for(int i = 0; i < 26; i++) {
		hash[i] = true;
	}
	for(int i = 0; i < 5; i++) {
		hash[ch[i] - 'a'] = false;
	}
	int T;
	scanf("%d", &T);
	int ans, len, sum[10000];
	for(int i = 1; i <= T; i++) {
		scanf("%s%d", &s, &L);
		ans = 0;
		len = strlen(s);
		for(int j = 0; j < len; j++) {
			for(int k = j; k < len; k++) {
				if(check(j, k)) {
                    //printf("%d %d\n", j, k);
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
