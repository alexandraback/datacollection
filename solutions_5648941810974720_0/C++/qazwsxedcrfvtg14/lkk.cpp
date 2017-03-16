#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
//#define mkptr make_shared<nod>
//#define mkptr new nod
//#pragma GCC diagnostic error "-std=c++11"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
char s[10000];
int cnt[200];
int ans[10];
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        scanf("%s",s);
        for(int i=0;s[i];i++)
            cnt[s[i]]++;
        ans[0]=cnt['Z'];cnt['O']-=ans[0];
        ans[6]=cnt['X'];cnt['S']-=ans[6];cnt['I']-=ans[6];
        ans[2]=cnt['W'];cnt['O']-=ans[2];
        ans[8]=cnt['G'];cnt['H']-=ans[8];cnt['I']-=ans[8];
        ans[7]=cnt['S'];cnt['V']-=ans[7];
        ans[5]=cnt['V'];cnt['I']-=ans[5];
        ans[4]=cnt['U'];cnt['O']-=ans[4];
        ans[1]=cnt['O'];
        ans[3]=cnt['H'];
        ans[9]=cnt['I'];
        printf("Case #%d: ",T);
        for(int i=0;i<10;i++)
            for(int j=0;j<ans[i];j++)
                printf("%d",i);
        puts("");
        }
    }
