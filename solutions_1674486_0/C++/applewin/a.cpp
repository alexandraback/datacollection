#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int NOGOOD;
int check[1100];
vector<int> mmap[1100];
vector<int> to[1100];

vector<int> loop(int i){
    if(check[i] == 1 || NOGOOD == 1)
        return to[i];
    check[i] = 1;
    int cc[N];
    memset(cc, 0, sizeof(cc));
    cc[i] = 1;
    vector<int> tmp;
    for(int j=0;j<mmap[i].size();++j){
        tmp = loop(mmap[i][j]);
        if(NOGOOD == 1) return tmp;
        for(int k=0;k<tmp.size();++k){
            if(cc[tmp[k]] == 1){
                NOGOOD = 1;
                break;
            }
            else
                cc[tmp[k]] = 1;
        }
        if(NOGOOD == 1)
            return tmp;
    }
    for(int j=0;j<N;++j)
        if(cc[j] == 1)
            to[i].push_back(j);
    return to[i];
}

int main(){
    int T, M, tmp;
    scanf("%d", &T);
    for(int c=1;c<=T;c++){
        printf("Case #%d: ", c);
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            mmap[i].clear();
            to[i].clear();
        }
        NOGOOD = 0;
        memset(check, 0, sizeof(check));

        for(int i=0;i<N;++i){
            scanf("%d", &M);
            for(int j=0;j<M;++j){
                scanf("%d", &tmp);
                mmap[i].push_back(tmp-1);
            }
        }
        for(int i=0;i<N && NOGOOD == 0;++i){
            if(check[i] == 0)
                loop(i);
        }
        if(NOGOOD == 1) puts("Yes");
        else puts("No");
    }
    return 0;
}
