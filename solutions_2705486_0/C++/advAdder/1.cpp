#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <assert.h>
using namespace std;

const int MAX_L = 10;
const int MAX_N = 4000;

struct node{
    node *son[26];
    bool mark;
}*root;
int top = 0;
int f[MAX_N+3];

#define max(a, b) (a>b?a:b)

inline node *get_newnode()
{
    node *p = new(node);
    for (int i = 0; i < 26; ++i)
        p->son[i] = NULL;
    p->mark = false;
}

inline bool find(node *p, char *st, int cur)
{
    if (cur > top)
        return false;
    if (*st == 0) {
        return p->mark;
    }
    for (int i = 0; i < 26; ++i)
    if (p->son[i] != NULL) {
        if (find(p->son[i], st+1, cur+(i!=*st-'a')))
            return true;
    }
    return false;
}

inline void insert(node *p, char *st)
{
    if (*st == 0) {
        p->mark = true;
        return ;
    }
    if (p->son[*st-'a'] == NULL) {
        p->son[*st-'a'] = get_newnode();
    }
    insert(p->son[*st-'a'], st+1);
}

inline void deal()
{
    char st[4003];
    scanf("%s", st);
    memset(f, 0x3F, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= strlen(st); ++i) {
        char c = st[i];
        st[i] = 0;
        for (int j = max(0,i-8); j < i; ++j)
        if (f[j] < f[i]) {
            for (top = 0; top <= i-j; ++top)
            if (find(root, st+j, 0))
                break;
            if (top <= i-j && f[i] > f[j]+top) {
                f[i] = f[j]+top;
            }
        }
        st[i] = c;
    }
    printf("%d\n", f[strlen(st)]);
}

int main()
{
    char *st;
    root = get_newnode();
    FILE *dic;
    dic = fopen("garbled_email_dictionary.txt", "r");
    while (fscanf(dic, "%s", st) != EOF)
        insert(root, st);
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; ++i) {
        printf("Case #%d: ", i);
        deal();
    }
    return 0;
}
