#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=(int)1e6;

int prime[maxn];
int pcnt=0;
int notprime(long long x){
    for (int i=0;i<pcnt && prime[i]*prime[i]<=x ;i++)
        if (x%prime[i]==0) return prime[i];
    return -1;
}
int main(){
    freopen("c.out","w",stdout);
    int N,J;
    for (int i=2;i<=maxn;i++){
        bool isprime=true;
        for (int j=0;j<pcnt;j++){
            if (i%prime[j]==0) {
                isprime=false;
                break;
            }
            if (prime[j]*prime[j]>i) break;
        }
        if (isprime) prime[pcnt++]=i;
    }
    for (int i=0;i<40;i++) cerr<<prime[i]<<" ";
    N=16;J=50;
    //N=16;j=50;
    int n=N-2;
    vector<int> ans[500];
    long long ans1[500];
    memset(ans1,0,sizeof ans1);
    int currj=0;
    for (long long i=0;i<(1LL<<n);i++){
        long long curr=(i<<1)+(1LL<<(n+1))+1LL;
        bool flag=true;
        for (int base=2;base<=10;base++){
            long long tmp=0;
            for (int j=n+1;j>=0;j--){
                tmp=tmp*base + (curr>>j)%2;
            }
            int tmpx=notprime(tmp);
            if (tmpx==-1) {
                flag=false;
                ans[currj].clear();
                ans1[currj]=0;
                break;
            }else{
                ans[currj].push_back(tmpx);
                if (base==10) ans1[currj]=tmp;
            }
        }
        if (flag) currj++;
        if (currj==J) break;
    }
    cout<<"Case #1: "<<endl;
    for (int i=0;i<J;i++){
        cout<<ans1[i];
        for (auto x : ans[i]) cout<<" "<<x;
        cout<<endl;
    }
}
