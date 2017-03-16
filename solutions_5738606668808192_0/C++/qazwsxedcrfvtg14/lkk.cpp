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
bool p[1000000];
vector<unsigned int> pl;
void init(){
    for(unsigned int i=2;i<65536;i++)
        if(!p[i]){
            pl.push_back(i);
            for(unsigned int j=i*i;j<1000000;j+=i)
                p[j]=1;
            }
    }
bool isp(__int128 x){
    if(x<1000000)return !p[x];
    for(auto d:pl)
        if(!(x%d))
            return false;
    return true;
    }
__int128 mul(__int128 a,__int128 b,__int128 mod){
    a%=mod;
    b%=mod;
    __int128 ret=0;
    for(;b;b>>=1){
        if(b&1){
            ret+=a;
            if(ret>=mod)ret-=mod;
            }
        a<<=1;
        if(a>=mod)a-=mod;
        }
    if(ret>=mod)ret-=mod;
    return ret;
    }
__int128 pow(__int128 a,__int128 b,__int128 mod){
    __int128 ret=1;
    for(;b;a=mul(a,a,mod),b>>=1)
        if(b&1)ret=mul(ret,a,mod);
    return ret;
    }
__int128 test[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
bool miller_rabin(__int128 n){
    if(n==2)return true;
    if(n<2||(n&1)==0)return false;
    __int128 u=n-1;
    int t=0;
    while((u&1)==0)u>>=1,t++;
    for(__int128 a:test){
        a%=n;
        if(a==0||a== 1||a==n-1)continue;
        __int128 x=pow(a,u,n);
        if(x==1||x==n-1)continue;
        for(int i=0;i<t;i++){
            x=mul(x,x,n);
            if(x==1)return false;
            if(x==n-1)break;
            }
        if(x==n-1)continue;
        return false;
        }
    return true;
    }

__int128 trn(unsigned int x,int base){
    __int128 y=1,ans=0;
    while(x)
        ans+=(x&1)*y,y*=base,x>>=1;
    return ans;
    }
int main(){
    init();
    int t,n,k;
    scanf("%d%d%d",&t,&n,&k);
    int cnt=0;
    puts("Case #1:");
    for(unsigned int i=1+(1<<(n-1));cnt!=k;i+=2){
        //fprintf(stderr,"~~~%u\n",i);
        if(isp(i))continue;
        if(isp(trn(i,3)))continue;
        if(isp(trn(i,4)))continue;
        if(isp(trn(i,5)))continue;
        if(isp(trn(i,6)))continue;
        if(isp(trn(i,7)))continue;
        if(isp(trn(i,8)))continue;
        if(isp(trn(i,9)))continue;
        if(isp(trn(i,10)))continue;
        vector<int> ve;
        unsigned int j=i;
        while(j)
            ve.push_back(j&1),j>>=1;
        for(int i=n-1;i>=0;i--)
            putchar('0'+ve[i]);
        for(int b=2;b<=10;b++){
            __int128 now=trn(i,b);
            for(auto d:pl)
                if(!(now%d)){
                    printf(" %d",d);
                    break;
                    }
            }
        puts("");
        cnt++;
        }
    }
