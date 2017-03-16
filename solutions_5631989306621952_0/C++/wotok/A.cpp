#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;


char s[2010];
char in[1010];
int T;

struct Node {
    char ch;
    int pos;
}node[1010];

int cmp(const Node& a,const Node& b) {
    if(a.ch != b.ch) {
        return a.ch > b.ch;
    }
    return a.pos > b.pos;
}
int main() {

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    scanf("%d",&T);
    int C = 1;
    while(T --) {
        memset(s,0,sizeof(s));
        scanf("%s",in);
        int len = strlen(in);
        for (int i = 0;i < len;i ++) {
            node[i].pos = i;
            node[i].ch = in[i];
        }
        sort(node,node + len,cmp);

        int prepos = len;
        int idx = 0;
        while(idx < len) {
            if(node[idx].pos < prepos) {
                s[len - 1 - node[idx].pos] = node[idx].ch;
                prepos = node[idx].pos;
                idx ++;
            }
            else {
                idx ++;
            }
        }
        printf("Case #%d: ",C ++);
        for (int i = 0;i < len ;i ++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                putchar(s[i]);
            }
        }
        for (int i = 0;i < len ;i ++) {
            if(!(s[len -1 -i] >= 'A' && s[len -1 -i] <= 'Z')) {
                putchar(in[i]);
            }
        }
        puts("");
    }
}
























































































