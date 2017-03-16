#include <stdio.h>
#include <vector>
using namespace std;

int box[210][500],tp[210],bn[210];
int n;
int tk[210];
int to[210];
vector<int> kb[210];
int pos[210];
int u[410],uid;
int pre[410];
int tried[210];
int list[210],r;

int dfs(int x,int t){
    u[x]=uid;
    for( int j=0; j<bn[x]; j++ ){
        if(u[box[x][j]+n]==uid) continue;
        u[box[x][j]+n]=uid;
        int tt=box[x][j];
        if(tt==t){
            list[0]=x;
            r=1;
            return 1;
        }
        for( int i=0; i<kb[tt].size(); i++ ){
            int y=kb[tt][i];
            if(u[y]!=uid && !to[x]){
                if(dfs(y,t)){
                    list[r++]=x;
                    return 1;
                }
            }
        }
    }
    return 0;
}

class State{
    public:
        int key[210];
        int op[210];
        State(){
            for( int i=1; i<=200; i++ ){
                key[i]=0;
            }
            for( int i=0; i<n; i++ ){
                op[i]=0;
            }
        }
        int check(){
            int i,j,k,x;
            for( i=1; i<=200; i++ ){
                tk[i]=key[i];
                kb[i].clear();
            }
            for( i=0; i<n; i++ ){
                to[i]=op[i];
                tried[i]=0;
                if(!op[i]){
                    pos[i]=kb[tp[i]].size();
                    kb[tp[i]].push_back(i);
                }
            }
            while(1){
                /*puts("---------------------");
                for( i=1; i<=200; i++ ){
                    for( j=0; j<tk[i]; j++ ){
                        printf("%d ",i);
                    }
                }
                puts("");
                for( i=0; i<n; i++ ){
                    printf("%d ",to[i]);
                }
                puts("");*/
                for( i=1; i<=200; i++ ){
                    if(kb[i].size()>0 && kb[i].size()<=tk[i]){
                        break;
                    }
                }
                if(i<=200){
                    //printf("type1: %d\n",i);
                    for( j=0; j<kb[i].size(); j++ ){
                        x=kb[i][j];
                        to[x]=1;
                        for( k=0; k<bn[x]; k++ ){
                            tk[box[x][k]]++;
                        }
                        tk[i]--;
                    }
                    kb[i].clear();
                }else{
                    for( i=0; i<n; i++ ){
                        if(!to[i] && !tried[i] && tk[tp[i]]){
                            uid++;
                            tried[i]=1;
                            if(dfs(i,tp[i])){
                                //printf("type2: %d\n",i);
                                for( j=0; j<r; j++ ){
                                    x=list[j];
                                    to[x]=1;
                                    tk[tp[x]]--;
                                    pos[kb[tp[x]].back()]=pos[x];
                                    kb[tp[x]][pos[x]]=kb[tp[x]].back();
                                    kb[tp[x]].pop_back();
                                    for( k=0; k<bn[x]; k++ ){
                                        tk[box[x][k]]++;
                                    }
                                }
                                break;
                            }
                        }
                    }
                    if(i==n){
                        break;
                    }
                }
            }
            for( i=0; i<n; i++ ){
                if(!to[i]) return 0;
            }
            return 1;
        }
        State open(int x){
            State ret=*this;
            ret.key[tp[x]]--;
            ret.op[x]=1;
            for( int i=0; i<bn[x]; i++ ){
                ret.key[box[x][i]]++;
            }
            return ret;
        }
        void print(){
            int i,j;
            puts("----------------------------");
            for( i=1; i<=200; i++ ){
                for( j=0; j<key[i]; j++ ){
                    printf("%d ",i);
                }
            }
            puts("");
            for( i=0; i<n; i++ ){
                printf("%d ",op[i]);
            }
            puts("");
            puts("");
        }
};

int main(){
    int tt,TT,x,m,i,j;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ){
        scanf("%d %d",&m,&n);
        State S;
        for( i=0; i<m; i++ ){
            scanf("%d",&x);
            S.key[x]++;
        }
        for( i=0; i<n; i++ ){
            scanf("%d %d",&tp[i],&bn[i]);
            for( j=0; j<bn[i]; j++ ){
                scanf("%d",&box[i][j]);
            }
        }
        printf("Case #%d:",tt+1);
        if(S.check()){
            for( j=0; j<n; j++ ){
                for( i=0; i<n; i++ ){
                    if(!S.op[i] && S.key[tp[i]]){
                        State T=S.open(i);
                        if(T.check()){
                            printf(" %d",i+1);
                            S=T;
                            break;
                        }
                    }
                }
            }
            puts("");
        }else{
            puts(" IMPOSSIBLE");
        }
    }
    return 0;
}
