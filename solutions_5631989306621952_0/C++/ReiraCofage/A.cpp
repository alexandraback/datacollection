#include <cstdio>
#include <cstring>

using namespace std;

int T, C=1, n;
char s[1024], r[1024];

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%s",s);
        n = strlen(s);
        char maior = 0;
        for (int i=0;i<n;i++)
            if (s[i] > maior)
                maior = s[i];

        bool m=false;
        for (int i=0;i<n;i++) {
            if (s[i]==maior or (!m and s[i]>=r[0])) {
                if (s[i]==maior) m=true;
                for (int j=i;j>0;j--)
                    r[j] = r[j-1];
                r[0] = s[i];
            } else
                r[i] = s[i];
        }
        r[n]='\0';
        printf("%s\n",r);
    }

    return 0;
}
