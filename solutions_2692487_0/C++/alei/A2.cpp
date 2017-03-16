#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>

#include<utility>
using namespace std;
const int MX=1000000+10;
typedef unsigned long long int uli;
uli data[MX];
pair<uli,int> reach(uli A, uli B){
    int ops = 0;
    while(A<=B){
        A = A + A-1;
        ops++;
    }
    return make_pair(A,ops);
}
int main(){
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int T,N;
    uli A,s,el;
    scanf("%d",&T);
    for(int c=0; c<T; c++){
        scanf("%lld %d",&A,&N);
        for(int i=0;i<N;i++){
            scanf("%lld",&s);
            data[i] = s;
        }
        sort(data, data+N);

        int ops = 0;
        int nops[MX], idx=0;
        for(int i=0; i<N && ops>=0;i++){
            el = data[i];
            if(A>el) A+=el;
            else{
                nops[idx] = ops + N-i;
                idx++;
                if(A==1) ops = -1;
                else{
                    pair<uli,int>r = reach(A,el);
                    A = r.first;
                    A += el;
                    ops += r.second;
                }
            }
        }
        int dops, ans;
        if(idx>0){
            sort(nops,nops+idx);
            dops = nops[0];
            if(ops==-1) ans = dops;
            else ans = min(ops, dops);
        }
        else ans = ops;
        printf("Case #%d: %d\n",c+1, ans);
    }
    return 0;
}
