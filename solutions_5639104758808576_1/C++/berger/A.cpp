#include <cstdio>

using namespace std;

int s;
char audience[2000];

int main() {
	int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        
        scanf("%d", &s);
        scanf("%s", audience);
        
        int ans = 0;
        int standing = 0;
        int i;
        for (i = 0; i < s+1; i++) {
            if (standing < i) {
                 ans += i - standing;
                 standing = i;
            }
            standing += audience[i]-'0';
        }
        
        printf("%d\n", ans);
    }
}