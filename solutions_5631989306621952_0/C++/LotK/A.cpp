#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    int tt;
    char str[1010];
    list<char> ans;
    scanf("%d", &tt);
    for (int t=0 ; t<tt ; t++) {
        scanf(" %s", str);
        ans.clear();
        char last='A';
        int len = strlen(str);
        for (int i=0 ; i<len ; i++) {
            if (str[i] >= last) {
                ans.push_front(str[i]);
                last = str[i];
            }
            else {
                ans.push_back(str[i]);
            }
        }

        printf("Case #%d: ", t+1);

        for (list<char>::iterator it=ans.begin(); it != ans.end(); ++it) {
            printf("%c", *it);
        }
        printf("\n");
    }
}
