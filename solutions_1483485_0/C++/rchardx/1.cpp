#include <cstdio>
#include <cstring>

using namespace std;

const char ch[] = "ynficwlbkuomxsevzpdrjgthaq";
char t[26];

char st[1024];

int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int ntest;
    scanf("%d\n",&ntest);
    for (int i = 0; i<26; ++i)
        t[ch[i]-'a'] = i+'a';
    for (int loop = 1; loop<=ntest; ++loop) {
        gets(st);
        printf("Case #%d: ",loop);
        int len = strlen(st);
        for (int i = 0; i<len; ++i)
            if ('a'<=st[i] && st[i]<='z') {
                putchar(t[st[i]-'a']);
            }
            else putchar(st[i]);
        printf("\n");
    }
    return 0;
}
