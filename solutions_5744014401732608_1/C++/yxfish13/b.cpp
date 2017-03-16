#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int P[100];
long long B;
long long M;
int ans[100][100];
void Sol(){
    cin>>B;
    cin>>M;
    long long c=1;
    for (int i=0;i<B-2;i++)
        c=c*2;
    if (c<M) {printf(" IMPOSSIBLE\n");return;}
    memset(ans,0,sizeof(ans));
    printf(" POSSIBLE\n");
    c=1;
    int i;
    for (i=2;c<M;i++){
        for (int j=1;j<i;j++) ans[j][i]=1;
        c=c*2;
    }
    i--;
    if (i!=1)
        c/=2;
    //c/=2;
    while (M){
        if (M>=c){
            M-=c;
            ans[i][B]=1;
        }
        i--;
        if (i!=1)
            c/=2;
    }
    for (int i=1;i<=B;i++){
        for (int j=1;j<=B;j++)
            printf("%d",ans[i][j]);
        printf("\n");
    }
}
int main(){
    int T;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    for (int datanum=1;datanum<=T;datanum++){
        printf("Case #%d:",datanum);
        Sol();
    }
    //printf("fuck");
    fclose(stdout);
    return 0;
}
