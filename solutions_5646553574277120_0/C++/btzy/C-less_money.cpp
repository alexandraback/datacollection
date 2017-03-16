#include<cstdio>
using namespace std;
long long arr[100];
int index;
long long length;
int c,d,tc;
long long v;
int main(){
    scanf("%d",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d%d%lld",&c,&d,&v);
        for(index=0;index<d;++index){
            scanf("%lld",&arr[index]);
        }
        index=0;
        length=1;
        while(index<d&&arr[index]<=length){
            length+=arr[index]*c;
            ++index;
        }
        int coins=0;
        while(length<=v){
            length*=(c+1);
            ++coins;
            while(index<d&&arr[index]<=length){
                length+=arr[index]*c;
                ++index;
            }
        }
        printf("Case #%d: %d\n",ct,coins);
    }
}
