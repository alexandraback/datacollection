#include<cstdio>
#include<cstdlib>
#include<cstring>

int T, L;
char str[105], rstr[105];

char rev(char ch){
    return ch=='+'?'-':'+';
}

int dfs(int now, char ch){
    //printf("s: %s\n", str);
    while(now>=0){
        if(str[now] == ch) now--;
        else{
            if(str[0] == ch){
                //printf("%d if\n", now);
                return 1+dfs(now-1, rev(ch));
            }
            //printf("%d else\n", now);
            for(int i=0;i<=now;i++) rstr[now-i] = rev(str[i]);
            for(int i=0;i<=now;i++) str[i] = rstr[i];
            return 1+dfs(now-1, ch);
        }
    }
    if(now==-1) return 0;
}

int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%s", str);
        L = strlen(str);
        int cnt = dfs(L-1, '+');
        printf("Case #%d: %d\n", t, cnt);
    }
    return 0;
}
