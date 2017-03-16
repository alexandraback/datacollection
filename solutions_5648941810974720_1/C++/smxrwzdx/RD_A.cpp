#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int A[230],N;
char ch[2010];
int ans[10];
int main(){
    freopen("AL.in","r",stdin);
    freopen("Adata.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        memset(A,0,sizeof(A));
        scanf("%s",ch);
        N = strlen(ch);
        for(int i=0;i<N;i++) {
            A[ch[i]]++;
        }
        ans[0] = A['Z'];
        ans[2] = A['W'];
        ans[4] = A['U'];
        ans[6] = A['X'];
        ans[8] = A['G'];

        ans[7] = A['S'] - ans[6];
        ans[5] = A['V'] - ans[7];
        ans[3] = A['T'] - ans[2] - ans[8];
        ans[1] = A['O'] - ans[0] - ans[2] - ans[4];
        ans[9] = A['I'] - ans[5] - ans[6] - ans[8];
        printf("Case #%d: ",tt);
        for(int i=0;i<10;i++) {
            for(int j=0;j<ans[i];j++){
                printf("%c",'0' + i);
            }
        }
        printf("\n");
    }
    return 0;
}
