#include <cstdio>
#include <cstring>

char s[200];

int main(){
    int T=0;
    scanf("%d", &T);
    for (int t=1;t<=T; ++t){
        printf("Case #%d: ", t);
        scanf("%s", s);
        int l=strlen(s);
        int ans=0;
        for (int i=l-1; i>=0; --i)
            if (s[i]=='-'){
                ++ans;
                for (int j=i-1; j>=0; --j)
                    if (s[j]=='+') s[j]='-'; else s[j]='+';
            }
        printf("%d\n", ans);
    }
}

