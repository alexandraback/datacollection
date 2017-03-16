#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int start,box;
int require[30];
vector<int> out[30];

char dp[1<<23+3];
int save[1<<23+3];
int cntkey[30];

char func( int state ){

    if ( state==(1<<box)-1 )return 1;

    if ( dp[state]!= -1 )return dp[state];

    int nxt= -1;
    for (int i=0;i<box;++i){
        if ( check(state,i)==0 ){
            if ( cntkey[ require[i] ]>=1 ){
                cntkey[ require[i] ]-- ;
                for (int j=0;j<out[i].size();++j){
                    cntkey[ out[i][j] ]++;
                }
                if ( func( set(state,i) ) ){
                    nxt=i;
                    break;
                }
                cntkey[ require[i] ]++ ;
                for (int j=0;j<out[i].size();++j){
                    cntkey[ out[i][j] ]--;
                }

            }
        }
    }
    if ( nxt== -1 ){
        return dp[state]=0;
    }else{
        save[state]=nxt;
        return dp[state]=1;
    }
}


void show(int state){
    if ( state==(1<<box)-1 )return ;

    printf(" %d",save[state]+1);
    show( set(state,save[state]) );
}


int main(){
    freopen("D-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);

    int kase,tmp,tt;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&start,&box);

        memset(cntkey,0,sizeof(cntkey));

        for (int i=0;i<start;++i){
            scanf("%d",&tmp);
            tmp--;
            cntkey[tmp]++;
        }

        for (int i=0;i<=box;++i){
            out[i].clear();
        }
        for (int i=0;i<box;++i){
            scanf("%d",&require[i]);
            require[i]--;
            scanf("%d",&tmp);
            while(tmp--){
                scanf("%d",&tt);
                tt--;
                out[i].push_back(tt);
            }
            sort(out[i].begin(),out[i].end());
        }
        printf("Case #%d:",kk);

        bool pos=false;
        memset(dp,-1,sizeof(dp));

        int nxt= -1;

        for (int i=0;i<box;++i){
            if ( cntkey[ require[i] ]>=1 ){
                cntkey[ require[i] ]-- ;
                for (int j=0;j<out[i].size();++j){
                    cntkey[ out[i][j] ]++;
                }

                if( func( set(0,i) ) ){
                    pos=true;
                    //printf("%d\n",i);
                    nxt=i;
                    break;
                }
                cntkey[ require[i] ]++;
                for (int j=0;j<out[i].size();++j){
                    cntkey[ out[i][j] ]--;
                }
            }
        }
        if ( !pos ){
            printf(" IMPOSSIBLE\n");
        }else{
            printf(" %d",nxt+1);
            show(set(0,nxt));
            printf("\n");
        }

    }
    return 0;
}
