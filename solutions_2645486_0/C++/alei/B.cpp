#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
typedef unsigned long long int uli;
uli find(uli from, uli to){
    uli mid = (from + to)/2;
    uli t = 2*mid*mid + mid;
}
int main(){
    freopen("bsmall.in","r",stdin);
    freopen("bsmall.out","w",stdout);
    int T, E,R,N,suma;
    int data[10006];
    scanf("%d",&T);
    for(int c=0;c<T;c++){
        scanf("%d %d %d",&E,&R,&N);
        suma = 0;
        for(int i=0;i<N;i++){
            scanf("%d",&data[i]);
            suma+=data[i];
        }
        sort(data,data+N);
        int max = data[N-1];
        suma-=max;
        //cout<<"suma="<<suma<<endl;
        int ans = max*E + min(E,R)*suma;
        printf("Case #%d: %d\n",c+1, ans);
    }
    return 0;
}
