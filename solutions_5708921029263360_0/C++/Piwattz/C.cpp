#include<bits/stdc++.h>
using namespace std;
#define NSIZ 12
#define mxint (-1u/2)
#define mxll (-1ull/2)
#define F first
#define S second
typedef pair<int,int> pii;

int n, m, o, re=0;
int a[NSIZ], b[NSIZ];
bool chk[3][NSIZ][NSIZ], chk2[3][NSIZ], fin[NSIZ][NSIZ][NSIZ];
int check[3][NSIZ][NSIZ];
vector<int> ans[3];
int main(){
    int i, j, k, l;
    int test;
    scanf("%d", &test);
    for(int zz=1; zz<=test; zz++){
        scanf("%d %d %d %d", &n, &m, &o, &re);
        memset(fin,0,sizeof(fin));
        memset(check,0,sizeof(check));
        for(i=0; i<3; i++){
            ans[i].clear();
        }
        while(1){
            memset(chk,0,sizeof(chk));
            bool ch=0;
            while(1){
//                    printf("=====\n");
                memset(chk2,0,sizeof(chk2));
                bool ch2=0;
                for(i=1; i<=n; i++){
                    int ll=0;
                    for(j=i%m+1,ll=0; ll<m; j=(j%m)+1,ll++){
                        for(k=j%o+1,l=0; l<o; k=(k%o)+1,l++){
                            if(chk2[0][i])continue;
                            if(chk2[1][j])continue;
                            if(chk2[2][k])continue;
                            if(chk[0][i][j])continue;
                            if(chk[1][i][k])continue;
                            if(chk[2][j][k])continue;
//                            if(i==2 && j==1 && k==1)printf("..%d %d %d\n", check[0][2][1],check[1][2][1], check[2][1][1]);
                            if(check[0][i][j]==re)continue;
                            if(check[1][i][k]==re)continue;
                            if(check[2][j][k]==re)continue;
                            if(fin[i][j][k])continue;
                            ch2=1;
                            ch=1;
                            chk2[0][i]=1;
                            chk2[1][j]=1;
                            chk2[2][k]=1;
                            chk[0][i][j]=1;
                            chk[1][i][k]=1;
                            chk[2][j][k]=1;
                            check[0][i][j]++;
                            check[1][i][k]++;
                            check[2][j][k]++;
                            fin[i][j][k]=1;
                            ans[0].push_back(i);
                            ans[1].push_back(j);
                            ans[2].push_back(k);
                            goto skip;
                        }
                    }
                    skip:;
                }
                if(ch2==0)break;
            }
            if(ch==0)break;
        }
//        for(i=0; i<3; i++){
//            printf("==== %d ====\n", i);
//            for(j=1; j<=3; j++){
//                for(k=1; k<=3; k++){
//                    if(check[i][j][k]<re)printf("%d %d = %d\n", j, k, check[i][j][k]);
//                }
//            }
//        }
        printf("Case #%d: %d\n", zz, ans[0].size());
        for(i=0; i<ans[0].size(); i++){
            printf("%d %d %d\n", ans[0][i],ans[1][i],ans[2][i]);
        }
    }
    return 0;
}
