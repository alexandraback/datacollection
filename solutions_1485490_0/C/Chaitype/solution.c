#include<stdio.h>
long long data[110][2],info[10][2];
int N,M,T;
long long out;
long long work(int q,int w,long long e,long long r)
{   int a,s,d,f;
    long long aaa=0;
    if(w<M&&q<N){
    for(a=q+1;a<N;++a) {
        f=work(a,w,0,r);
        if(aaa<f) aaa=f;
    }
    for(a=w;a<M;++a){
        if(info[q][1]==data[a][1]) break;
    }
    if(info[q][1]==data[a][1]){
        if((info[q][0]-e)>(data[a][0]-r)){
            s=work(q,a+1,(data[a][0]-r),0);
            d=work(q+1,a+1,0,0);
            if(aaa<s+(data[a][0]-r)) aaa=s+(data[a][0]-r);
            if(aaa<d+(data[a][0]-r)) aaa=d+(data[a][0]-r);
        }
        else if((info[q][0]-e)<=(data[a][0]-r)){
            s=work(q+1,a,0,(info[q][0]-e));
            d=work(q+1,a+1,0,0);
            if(aaa<s+(info[q][0]-e)) aaa=s+(info[q][0]-e);
            if(aaa<d+(info[q][0]-e)) aaa=d+(info[q][0]-e);
        }
    }
    }
    return aaa;
}
int main()
{   int q,w,e,r,t;
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&T);
    for(q=0;q<T;++q){
        scanf("%d%d",&N,&M);out=0;
        for(w=0;w<N;++w){
            scanf("%lld%d",&info[w][0],&info[w][1]);
        }
        for(w=0;w<M;++w){
            scanf("%lld%d",&data[w][0],&data[w][1]);
        }
        for(w=0;w<N;++w){
            e=work(w,0,0,0);
            if(e>out) out=e;
        }
        printf("Case #%d: %lld\n",q+1,out);
    }
    return 0;
}
/*
4
3 3
10 1 20 2 25 3
10 2 30 3 20 1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1
3 5
10 1 6 2 10 1
5 1 6 2 10 1 6 2 5 1
1 1
5000000 10
5000000 100
*/
