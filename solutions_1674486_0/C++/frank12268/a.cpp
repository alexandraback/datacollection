#include<cstdio>
#include<vector>
#include<cstring>

const int MAXN = 1000+10;

int edges[MAXN*10];
int count[MAXN];
bool used[MAXN];
int qu[MAXN];

bool check(int i){
    memset(used,false,sizeof(used));
    used[i] = true;
    qu[0] = i;
    int fr = -1;
    int ba = 0;
    while (fr<ba){
        ++fr;
        for (int j=count[qu[fr]-1];j<count[qu[fr]];++j){
            if (used[edges[j]]){
                return true;
            }
            used[edges[j]] = true;
            qu[++ba] = edges[j];
        }
    }
    return false;
}

int main(){
    int noc;
    int n;
    scanf("%d",&noc);
    for (int tnoc=1;tnoc<=noc;++tnoc){
        printf("Case #%d: ",tnoc);
        scanf("%d",&n);
        count[0] = 0;
        for (int i=1;i<=n;++i){
            scanf("%d",&count[i]);
            for (int j=0;j<count[i];++j){
                scanf("%d",&edges[count[i-1]+j]);
            }
            count[i] += count[i-1];
        }
        bool res = false;
        for (int i=1;i<=n;++i){
            if (check(i)){
                res = true;
                break;
            }
        }
        if (res){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
