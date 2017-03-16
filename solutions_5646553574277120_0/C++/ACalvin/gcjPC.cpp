#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005;
int ok[N],val[10];
int needs[100],txt = 1;
map<int,int> mp;
void solve(){
    mp.clear();
    int c,d,v;
    scanf("%d%d%d",&c,&d,&v);
    memset(ok,0,sizeof(ok));
    for(int i = 0 ; i < d ; i ++) scanf("%d",&val[i]);
    for(int i = 0 ; i < d ; i ++) mp[ val[i] ] = 1;
    for(int i = 0 ; i < (1 << d) ; i ++){
        int t = 0;
        for(int j = 0 ; j < d ; j ++)
            if(i & (1 << j)) t += val[j];
        ok[t] = 1;
    }
    int cnt = 0,res = 0;
    for(int i = 1 ; i <= v ; i ++) cnt += !ok[i];
    while(cnt){
        memset(needs,0,sizeof(needs));
        needs[0] = -10;
        for(int i = 1 ; i <= v ; i ++){
            if(ok[i]) continue;
            for(int j = 1 ; j < i ; j ++)
                if(ok[j] && mp.find(i - j) == mp.end()) needs[i - j] ++;
            needs[i] ++;
        }
        int Max = 0;
        for(int i = 1 ; i <= v ; i ++)
            if(needs[Max] < needs[i] && mp.find(i) == mp.end()) Max = i;
        for(int i = v ; i >= Max ; i --) if(ok[i - Max]) ok[i] = 1;
        mp[Max] = 1;
        cnt = 0;
        for(int i = 1 ; i <= v ; i ++) cnt += !ok[i];
        res ++;
    }
    printf("Case #%d: %d\n",txt ++,res);
}
int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("data.out","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
