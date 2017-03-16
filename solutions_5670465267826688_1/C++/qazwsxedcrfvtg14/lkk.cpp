#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
//#define mkptr make_shared<nod>
//#define mkptr new nod
//#pragma GCC diagnostic push
#pragma GCC diagnostic error "-std=c++11"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef pair<int,int> par;
typedef pair<par,int> pr;
gp_hash_table<char,gp_hash_table<char,char>>gp,mp;
char s[10005];
char pw(char a,int b){
    char ret='1';
    while(b){
        if(b&1)ret=mp[ret][a];
        a=mp[a][a];
        b>>=1;
        }
    return ret;
    }
int main(){
    gp['1']['1']='1';gp['1']['i']='i';gp['1']['j']='j';gp['1']['k']='k';
    gp['i']['1']='i';gp['i']['i']=-'1';gp['i']['j']='k';gp['i']['k']=-'j';
    gp['j']['1']='j';gp['j']['i']=-'k';gp['j']['j']=-'1';gp['j']['k']='i';
    gp['k']['1']='k';gp['k']['i']='j';gp['k']['j']=-'i';gp['k']['k']=-'1';
    for(auto x:gp)
        for(auto y:x.s)
            mp[x.f][y.f]=y.s,mp[-x.f][y.f]=-y.s,mp[x.f][-y.f]=-y.s,mp[-x.f][-y.f]=y.s;
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int n,m;
        scanf("%d%d%s",&n,&m,s);
        char now='1';
        for(int i=0;i<n;i++)
            now=mp[now][s[i]];
        now=pw(now,m);
        if(now!=-'1'){
            printf("Case #%d: NO\n",T);
            continue;
            }
        int lv=0;
        int cnt=0,i;
        now='1';
        for(i=0;cnt<min(10,m);cnt++,i=0){
            for(;lv==0&&i<n;i++){
                now=mp[now][s[i]];
                if(now=='i'){lv=1;now='1';}
                }
            for(;lv==1&&i<n;i++){
                now=mp[now][s[i]];
                if(now=='j'){lv=2,cnt=0x3fffffff;}
                }
            }
        if(lv==2)
            printf("Case #%d: YES\n",T);
        else
            printf("Case #%d: NO\n",T);
        }
    return 0;
    }

