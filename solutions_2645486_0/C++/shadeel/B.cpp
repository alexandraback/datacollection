#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct WORK{
    int gain, index;
};

WORK work[10000];
int remain[10000], gain[10000];

bool cmp(WORK a, WORK b){
    if( a.gain > b.gain )       return true;
    else if( a.gain < b.gain )  return false;
    else{
        if( a.index > b.index ) return true;
        else                    return false;
    }
}

int main(void){
    
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, e, r, n;
    
    scanf("%d", &cas);
    while( cas-- ){
        
        scanf("%d %d %d", &e, &r, &n);
        for(int i=0; i<n; ++i){
            scanf("%d", &gain[i]);
            work[i].gain = gain[i];
            work[i].index = i;
        }
        memset(remain,-1,sizeof(remain));
        sort(work, work+n, cmp);
        
        for(int i=0; i<n; ++i){
            if( remain[work[i].index] < 0 )
                remain[work[i].index] = 0;
            for(int j=work[i].index-1,k=e-r; (k>=0)&&(j>=0)&&(work[i].gain>gain[j]); --j,k-=r)
                remain[j] = k;
        }
        long long int ans = 0;
        for(int i=0,ini=e; i<n; ++i,ini+=r){
            long long int use = ini-remain[i];
            if( use<0 ) use = 0;
            else        ini = remain[i];
            ans += use*(long long int)gain[i];
        }
        printf("Case #%d: ", ++c);
        cout << ans << endl;
    }
    
    return 0;
}
