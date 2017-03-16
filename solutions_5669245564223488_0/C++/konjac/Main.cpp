#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char cars[101][101];
int len[101];

//#define DEBUG

int main() {
    int bt;
    scanf("%d", &bt);
    for (int bf = 1; bf <= bt; bf++) {
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) {
            scanf("%s", cars[i]);
            int l = strlen(cars[i]);
            int k = -1;
            for (int j = 0; j < l; j++)
                if (j == 0 || cars[i][k] != cars[i][j]) {
                    ++k;
                    cars[i][k] = cars[i][j];
                }
            ++k;
            cars[i][k] = 0;
        }
        bool noAns = false;
        for (int i = 0; i < n; i++)
            len[i] = strlen(cars[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < len[i]; j++)
                for (int k = j + 1; k < len[i]; k++)
                    if (cars[i][j] == cars[i][k]) {
                        noAns = true;
                    }
            for (int j = 1; j < len[i] - 1; j++)
                for (int k = 0; k < n; k++)
                    if (k != i) for (int p = 0; p < len[k]; p++)
                        if (cars[i][j] == cars[k][p]) {
                            noAns = true;
                        }
        }
#ifdef DEBUG
        for (int i=0;i<n;i++)puts(cars[i]);
#endif
        int ru[26], chu[26], c1[26], c2[26];
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        memset(ru, 0xff, sizeof(ru));
        memset(chu, 0xff, sizeof(chu));
        for (int i = 0; i < n; i++)
            if (len[i] != 1) {
                if (ru[(int)cars[i][0]-(int)'a']!=-1) noAns=true;
                ru[(int)cars[i][0]-(int)'a']=i;
                if (chu[(int)cars[i][len[i]-1]-(int)'a']!=-1) noAns=true;
                chu[(int)cars[i][len[i]-1]-(int)'a']=i;
            }
        int sum=0;
        for (int i=0;i<n;i++)
            if (len[i]==1){
                int index=(int)cars[i][0]-(int)'a';
                if (ru[index]==-1 && chu[index]==-1) c1[index]++; else c2[index]++;
                ++sum;
            }
#ifdef DEBUG
        printf("c1  ");for (int i=0;i<26;i++) printf("%d ",c1[i]);printf("\n");
        printf("c2  ");for (int i=0;i<26;i++) printf("%d ",c2[i]);printf("\n");
        printf("ru  ");for (int i=0;i<26;i++) printf("%d ",ru[i]);printf("\n");
        printf("chu ");for (int i=0;i<26;i++) printf("%d ",chu[i]);printf("\n");
        printf("noAns=%d\n",noAns);
#endif
        if (noAns){
            printf("Case #%d: 0\n", bf);
            continue;
        }
        if (sum==n){
            long long ans=1;
            int c1f=1;
            for (int i=0;i<26;i++)
                if (c1[i]!=0){
                    ans=(ans*c1f)%1000000007;
                    c1f++;
                    for (int j=1;j<=c1[i];j++)
                        ans=(ans*j)%1000000007;
                }
            printf("Case #%d: %lld\n", bf, ans);
            continue;
        }
        bool found=false;
        int fi;
        for (int i=0;i<26;i++)
            if (ru[i]!=-1 && chu[i]==-1){
                if (found) noAns=true;
                found=true;
                fi=i;
            }
#ifdef DEBUG
        printf("found=%d fi=%d\n", found, fi);
        printf("noAns=%d\n", noAns);
#endif
        if (noAns || !found){
            printf("Case #%d: 0\n", bf);
            continue;
        }
        if (found){
            int c=0;
            for (int i=0;i<n;i++)
                if (len[i]!=1) ++c;
            for (int i=0;i<c;i++){
                int no=ru[fi];
#ifdef DEBUG
                printf("found i=%d no=%d\n",i,no);
#endif
                ru[fi]=-1;
                fi=(int)cars[no][len[no]-1]-(int)'a';
                chu[fi]=-1;
                if (ru[fi]==-1 && i!=c-1){
                    noAns=true;
                    break;
                }
            }
            if (noAns){
                printf("Case #%d: 0\n", bf);
                continue;
            }
            long long ans=1;
            for (int i=0;i<26;i++)
                for (int j=1;j<=c2[i];j++)
                    ans=(ans*j)%1000000007;
            int c1f=2;
            for (int i=0;i<26;i++)
                if (c1[i]!=0){
                    ans=(ans*c1f)%1000000007;
                    c1f++;
                    for (int j=1;j<=c1[i];j++)
                        ans=(ans*j)%1000000007;
                }
            printf("Case #%d: %lld\n", bf, ans);
        }
    }
    return 0;
}
