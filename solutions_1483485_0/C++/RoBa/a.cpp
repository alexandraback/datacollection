/*
#include <cstring>
#include <cstdio>
using namespace std;

char buf[1024];
char buf2[1024];
int mp[26];

int main() {
    int n, i;
    memset(mp, -1, sizeof(mp));
    scanf("%d",&n);
    gets(buf);
    while (n--) {
        gets(buf);
        gets(buf2);
        for (i = 0 ; buf[i] ; i++) {
            if (buf[i] == ' ') continue;
            mp[buf[i]-'a'] = buf2[i]-'a';
        }
    }
    for (i = 0 ; i < 26 ; i++) {
        if (mp[i] != -1) {
            printf("\'%c\',",mp[i]+'a');
        } else {
            printf("\'-\',");
        }
    }
}
*/
#include <cstdio>
#include <cctype>

const char mp[26] = {
'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w',
'j','p','f','m','a','q'};

char buf[1024];

int main() {
    freopen("a-small.in","r",stdin);
    freopen("a-small.out","w",stdout);
    int n;
    scanf("%d",&n);
    gets(buf);
    for (int i = 1 ; i <= n ; i++) {
        gets(buf);
        printf("Case #%d: ", i);
        for (int j = 0 ; buf[j] ; j++) {
            char ch = ' ';
            if (isalpha(buf[j])) ch = mp[buf[j]-'a'];
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
