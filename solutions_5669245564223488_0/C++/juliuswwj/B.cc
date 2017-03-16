#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<list>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;

typedef long long LL;

#define SIZE 102
#define M   1000000007
char mm[SIZE][SIZE];
int  sz[SIZE];
int  N;
LL NN[SIZE];

int run()
{
    for(int i=0; i<N; i++)if(sz[i]>2){
        for(int j=1; j<sz[i]-1; j++){
            for(int a=0; a<N; a++)for(int b=0; b<sz[a]; b++)if(mm[i][j] == mm[a][b] && (i!=a || j!=b)){
                if(i != a)return 0;
                for(int k=min(j,b); k!=max(j,b); k++)if(mm[i][k] != mm[i][j])return 0;
            }
        }
    }
    struct ENTRY {
        set<int> sh;
        set<int> st;
        int scnt;
        char h;
        char t;
        int gid;
        ENTRY() { h=t=0; scnt = 0; gid=-1;}
    };
    map<char, ENTRY> chs;
    for(char ch='a'; ch<='z'; ch++)chs[ch] = ENTRY();
    
    for(int i=0; i<N; i++){
        chs[ mm[i][0] ].sh.insert(i);
        chs[ mm[i][sz[i]-1] ].st.insert(i);
        if( mm[i][0] == mm[i][sz[i]-1] ) chs[ mm[i][0] ].scnt++;
    }
    for(char ch='a'; ch<='z'; ch++){
        int nh = 0;
        int nt = 0;
        for(auto k : chs[ch].sh)if(mm[k][ sz[k]-1 ] != mm[k][0]){ 
            nt++;
            if(chs[ mm[k][ sz[k]-1 ] ].sh.size() > 0)
                chs[ch].t = mm[k][ sz[k]-1 ];
        }
        for(auto k : chs[ch].st)if(mm[k][ sz[k]-1 ] != mm[k][0]){ 
            nh++;
            if(chs[ mm[k][0] ].sh.size() > 0)
                chs[ch].h = mm[k][ 0 ];
        }
        if(nh > 1 || nt > 1)return 0;
    }
    
    int gc = 0;
    LL ans = 1;
    for(char ch='a'; ch<='z'; ch++)if(chs[ ch ].sh.size()){
        ans = (ans * NN[ chs[ch].scnt ]) % M;
        if(chs[ch].h){
            if( chs[ chs[ch].h ].t != ch )return 0;
            if( chs[ chs[ch].h ].gid < 0) {
                if(chs[ch].gid < 0)chs[ch].gid = gc++;
                chs[ chs[ch].h ].gid = chs[ch].gid;
            } else {
                chs[ch].gid = chs[ chs[ch].h ].gid; 
            }
        }
        if(chs[ch].t){
            if( chs[ chs[ch].t ].h != ch )return 0;
            if( chs[ chs[ch].t ].gid < 0) {
                if(chs[ch].gid < 0)chs[ch].gid = gc++;
                chs[ chs[ch].t ].gid = chs[ch].gid;
            } else {
                chs[ch].gid = chs[ chs[ch].t ].gid; 
            }
        }
        if(chs[ch].gid < 0)chs[ch].gid = gc++;
    }
    //for(int i=0; i<N; i++)printf("%d %s\n", i, mm[i]);
    //for(char ch='a'; ch<='z'; ch++)if(chs[ ch ].sh.size()){
    //    printf("m[%c] scnt=%d sh=%d h=%c t=%c gid=%d\n", ch, chs[ch].scnt, chs[ch].sh.size(), chs[ch].h, chs[ch].t, chs[ch].gid);
    //}
    ans = (ans * NN[gc]) % M;
    return (int)ans;
}

int main()
{
    NN[0] = 1;
    for(int i=1; i<SIZE; i++){
        NN[i] = (NN[i-1]*i) % M;
    }
    CASET {
        RI(N);
        for(int i=0; i<N; i++){
            RS(mm[i]);
            int l = 0;
            int p = 0;
            while(mm[i][p]){
                if(p>0 && mm[i][p] == mm[i][p-1]){
                    p++;
                    continue;
                }
                mm[i][l] = mm[i][p];
                l++;
                p++;
            }
            mm[i][l] = 0;
            sz[i] = l;
        }
        printf("Case #%d: %d\n", case_n++, run());
    }
    return 0;
}
