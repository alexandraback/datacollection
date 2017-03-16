#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;

int T;
int getAt(int num,int pos) {
    if(pos == 0) return num % 10;
    else if(pos == 1) {
        num /= 10;
        return num % 10;
    }
    else {
        num /= 100;
        return num % 10;
    }
}
char s1[5],s2[5];

bool ck(int num,char s[5],int len) {
    for (int i = 0;i < 3;i ++) {
        if(len - 1 - i >= 0 && s[len - 1 - i] == '?') continue;
        int cur = (len - 1 - i >= 0? s[len - 1 - i] - '0' : 0);
        if(getAt(num,i) != cur) {
            return false;
        }
    }
    return true;
}
int getlen(int x) {
    if(x <= 9) return 1;
    else if(x <= 99) return 2;
    else return 3;
}
void print(int x,int num) {
    int curlen = getlen(x);
    for (int i = 0;i < num - curlen;i ++) {
        printf("0");
    }
    printf("%d",x);
}
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int C = 1;
    while(T --) {
        scanf("%s%s",s1,s2);
        int len = strlen(s1);
        int ans1 = 0;
        int ans2 = 0x3f3f3f3f;
        for (int i = 0;i <= 999;i ++) {
            for (int j = 0;j <= 999;j ++) {
                if(i == 19 && j == 20) {
                    int z = 1;
                }
                if(ck(i,s1,len) && ck(j,s2,len)) {
                    if(abs(i - j) < abs(ans1 - ans2) || abs(i - j) == abs(ans1 - ans2) && i < ans1 ||
                       abs(i - j) == abs(ans1 - ans2) && i == ans1 && j < ans2) {
                            ans1 = i;
                            ans2 = j;
                       }
                }
            }
        }
        printf("Case #%d: ",C++);
        print(ans1,len);
        printf(" ");
        print(ans2,len);
        puts("");
    }
}
