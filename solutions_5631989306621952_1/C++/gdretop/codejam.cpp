#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
char word[10000];
int main(){
    int t;
    freopen("A-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%d",&t);
    for(int tt = 1; tt <= t; tt++){
        scanf("%s",word);
        int len = strlen(word);
        string ans;
        ans = word[0];
        for(int i = 1;i < len; i++){
            if(word[i] >= ans[0]) ans = word[i] + ans;
            else ans = ans + word[i];
        }
        printf("Case #%d: %s\n",tt,ans.c_str());
    }
    return 0;
}
