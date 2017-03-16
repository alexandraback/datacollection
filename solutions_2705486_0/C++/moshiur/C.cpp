#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//#define DEBUG_MODE

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#ifdef DEBUG_MODE
#define DBG(X) X
#else
#define DBG(X)
#endif

inline int ___INT(){int ret; scanf("%d",&ret); return ret;}
#define INT ___INT()

typedef long long LL;
typedef pair<int,int> pii;

#define DICT_SIZE 521196

string dict[DICT_SIZE+2];

void load_dict(){
    FILE* dict_file = fopen("garbled_email_dictionary.txt","r");
    int cnt = 0;
    char buff[500];

    while( fscanf(dict_file,"%s",buff) == 1 ){
        dict[cnt++] = buff;
        if(cnt>1){
            assert(dict[cnt-1] > dict[cnt-2]);
        }
    }

    fclose(dict_file);

    assert(cnt == DICT_SIZE);
}

const int INF = (1<<29);

char str[4005];
int len;
int dp[4005][6];

int F(int cur, int d){
    if(cur >= len){
        return 0;
    }
    int& ret = dp[cur][d];
    if(ret>-1) return ret;

    ret = INF;

    FOR(i,DICT_SIZE){
        if(dict[i].size() > len-cur) continue;

        bool isGood = true;
        int prev = cur-d;
        int cost = 0;

        for(int j = 0, k = cur; j < dict[i].size(); ++j, ++k){
            if(dict[i][j] != str[k]){
                if(abs(prev-k) < 5){
                    isGood = false; break;
                }
                else{
                    prev = k;
                    ++cost;
                }
            }
        }

        if(isGood){
            int nxt = cur+dict[i].size();
            ret = min(ret, cost + F(nxt,min(5, nxt-prev)));
        }
    }

    return ret;
}

int calc(){

    len = strlen(str);

    CLR(dp,-1);

    return F(0,5);
}

int main(){
    freopen("C_small.in","r",stdin);
    freopen("C_small_output.out","w",stdout);


    load_dict();

    int T=INT;

    REP(t,1,T){
        scanf("%s",str);

        printf("Case #%d: %d\n",t,calc());
    }

    return 0;
}
