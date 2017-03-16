#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 111
using namespace std;
char mp[32] = {"yhesocvxduiglbkrztnwjpfmaq"};
char str[maxn];
int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-ans.txt", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for(int i=1;i<=t;i++){
        gets(str);
        printf("Case #%d: ", i);
        for(int j=0;str[j];j++){
            if(str[j] == ' ') putchar(' ');
            else putchar(mp[str[j] - 'a']);
        }
        puts("");
    }
    return 0;
}
