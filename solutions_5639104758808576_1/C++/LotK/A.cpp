#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int tt;
    scanf("%d", &tt);
    for(int t=0; t<tt ; t++) {
        int n;
        char str[1010];
        scanf("%d", &n);
        scanf("%s", str);
        int no_people = 0, atleast = 0;
        for(int i=0 ; i<n+1 ; i++) {
            if (no_people >= i) no_people += (str[i]-'0');
            else {
                atleast += i - no_people;
                no_people = i + (str[i]-'0');
            }
        }

        printf("Case #%d: %d\n", t+1, atleast);
    }
}
