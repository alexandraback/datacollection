#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int T,L,X;
char s[10005];

int a[5][5] = {{0,0, 0, 0, 0},
               {0,1, 2, 3, 4},
               {0,2,-1, 4,-3},
               {0,3,-4,-1, 2},
               {0,4, 3,-2,-1}};

int main(){
    scanf("%d",&T);
    FOE(t,1,T){
        scanf("%d%d",&X,&L); gets(s);
        gets(s);

        FOR(i,1,L) strncat(s,s,X);

        bool ok = 0;
        int tmp = 1,pos = 0;
        while(pos < L*X){
            int tar = s[pos]-'i'+2;
            if (tmp < 0) tmp = -a[-tmp][tar];
            else tmp = a[tmp][tar];
            ++pos;

            if (tmp == 2){
                ok = 1;
                //printf("i %d!\n",pos);
                //puts("find i");
                break;
            }
        }
        if (ok){
            ok = 0; tmp = 1;
            while(pos < L*X){
                int tar = s[pos]-'i'+2;
                if (tmp < 0) tmp = -a[-tmp][tar];
                else tmp = a[tmp][tar];
                ++pos;

                if (tmp == 3){
                    //printf("i %d!\n",pos);
                    //puts("find j");
                    ok = 1;
                    break;
                }
            }

            if (ok){
                ok = 0; tmp = 1;
                while(pos < L*X){
                    int tar = s[pos]-'i'+2;
                    if (tmp < 0) tmp = -a[-tmp][tar];
                    else tmp = a[tmp][tar];
                    ++pos;
                }

                if (tmp == 4) ok = 1;
            }
        }
        printf("Case #%d: %s\n",t,ok?"YES":"NO");
    }
    return 0;
}
