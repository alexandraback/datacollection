#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Comb{int s,p,j;};
int T,J,P,S,K;
vector<Comb> vect;
int cnt[12][12][12];

int main(){
    freopen("data2.in","r",stdin);
    freopen("data2.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        vect.clear();
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d%d%d",&J,&P,&S,&K);
        for (int i = 1; i <= S; i++){
            for (int j = 1; j <= P; j++){
                for (int k = 1; k <= J; k++){
                    bool flag = 1;
                    for (int a = 0; a <= S; a++){
                        for (int b = 0; b <= P; b++){
                            for (int c = 0; c <= J; c++){
                                int zero = 0;
                                if (!a)zero++;
                                if (!b)zero++;
                                if (!c)zero++;
                                if (zero == 1){
                                    if (cnt[a][b][c] > K){
                                        flag = 0;
                                        break;
                                    }
                                }
                            }
                            if (!flag) break;
                        }
                        if (!flag) break;
                    }
                    if (flag){
                        if (cnt[i][j][0] < K && cnt[i][0][k] < K && cnt[0][j][k] < K){
                            vect.push_back((Comb){i,j,k});
                            cnt[i][j][0]++;
                            cnt[i][0][k]++;
                            cnt[0][j][k]++;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",z,(int)vect.size());
        for (int i = 0; i < vect.size(); i++){
            printf("%d %d %d\n",vect[i].j,vect[i].p,vect[i].s);
        }
    }
    
    return 0;
}