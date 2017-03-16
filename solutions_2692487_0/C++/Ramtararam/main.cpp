#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <inttypes.h>
using namespace std;

#define N 10

int motes[N];
int grows[N];

int main(){

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int t;

    scanf("%d", &t);

    for(int h=1;h<=t;++h){
        int a,n;
        scanf("%d %d", &a, &n);

        for(int i=0; i<n; ++i){
            scanf("%d", motes + i);
        }

        sort(motes, motes + n);

        int player = a;
        int res = 0;
        bool deleteAll = false;
        for(int i=0; i<n; ++i){
            if(player > motes[i]){
                player += motes[i];
                grows[i] = 0;
            }else{
                int grs = 0;
                if(player <= 1){
                    deleteAll = true;
                    res = n-i;
                    break;
                }
                while(player <= motes[i])
                    player += player-1, grs += 1;
                player += motes[i];
                grows[i] = grs;
            }
        }

        if(deleteAll){
            printf("Case #%d: %d\n", h, res);
            continue;
        }

        int sum = 0;

        for(int i=n-1; i>=0; --i){
            sum += grows[i];
            if(sum > n-i){
                for(int j=i; j<n && grows[j] != -1; ++j){
                    sum -= grows[j];
                    grows[j] = -1;
                }
            }
        }

        for(int i=0; i<n; ++i){
            res += grows[i] >= 0 ? grows[i] : 1;
        }

        printf("Case #%d: %d\n", h, res);

    }

    return 0;
}
