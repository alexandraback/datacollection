#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> c[11000];
int w[11000];

int main(){
    int tt,TT,E,R,n,i,x,y,j,d,v,mv,td;
    long long sum;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ){
        scanf("%d %d %d",&E,&R,&n);
        for( i=0; i<n; i++ ){
            scanf("%d",&x);
            c[i]=make_pair(x,i+1);
        }
        sort(c,c+n);
        for( i=1; i<=n; i++ ){
            w[i]=0;
        }
        w[0]=0;
        sum=0;
        for( i=n-1; i>=0; i-- ){
            x=c[i].second;
            y=c[i].first;
            d=E;
            for( j=0; j<x; j++ ){
                d=min(d-w[j]+R,E);
            }
            td=d;
            v=d;
            mv=d;
            for( j=x+1; j<=n; j++ ){
                v+=R;
                if(v>=E){
                    mv-=v-E;
                    if(mv<=0){
                        d-=mv+v-E;
                        break;
                    }else{
                        d-=v-E;
                        v=E;
                    }
                }
                v-=w[j];
                if(v<mv){
                    mv=v;
                    if(mv==0) break;
                }
            }
            if(mv>0){
                d-=mv;
            }
            w[x]=td-d;
            sum+=(long long)w[x]*y;
        }
        cout << "Case #" << tt+1 << ": " << sum << endl;
    }
    return 0;
}
