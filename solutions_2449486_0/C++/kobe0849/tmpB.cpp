#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 110;
int col[maxn];
int row[maxn];
int a[maxn][maxn];
int main(){
    freopen("ss.in","r",stdin);
    freopen("sss.out","w",stdout);
    int T,cas = 1;;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                scanf("%d",&a[i][j]);
                row[i] = max(row[i],a[i][j]);
                col[j] = max(col[j],a[i][j]);
            }
        }
        bool flag = true;
        for(int i = 1; i <= N && flag; i++)
            for(int j = 1; j <= M; j++){
                if(a[i][j] < row[i] && a[i][j] < col[j]){
                    flag = false;
                    break;
                }
            }
            printf("Case #%d: ",cas++);
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
