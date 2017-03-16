#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#define INF 1000000007
using namespace std;
char s[1111];
int main() {
    int T, cas = 0, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s); 
        int len = strlen(s);
        int pre = -1;
        string ans = "";
        for(int i = 0; i < len; i++) {
            if(s[i] >= pre) {
                ans = s[i] + ans;
                pre = s[i];
            } else ans = ans + s[i];
        }
        printf("Case #%d: %s\n", ++ cas, ans.c_str());
    }
	return 0;
}
