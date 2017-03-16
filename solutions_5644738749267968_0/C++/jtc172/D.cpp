#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define MaxN 1500

int T,N;
double nb[MaxN],kb[MaxN];

int ws()
{
    int a = 1, b = N, tmp = 0;
    for (int i = N ; i>=1 ; i -- ) {
        if (nb[i]>kb[b]){
            a++;tmp++;
        } else {b--;}
    }
    return tmp;
}

int ds()
{
    int a = 1, b = N, tmp=0;
    for (int i = N ; i >= 1 ; i-- ) {
        if (nb[b]<kb[i]) {a++;}
        else {
            b--;tmp++;
        } 
    }
    return tmp;
}  

            

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int i = 1 ; i <= T ; i ++ ) {
        cin>>N;
        for (int j = 1 ; j <= N ; j++ ) scanf("%lf",&nb[j]);
        for (int j = 1 ; j <= N ; j++ ) scanf("%lf",&kb[j]);
        sort(nb+1,nb+N+1);
        sort(kb+1,kb+N+1);
        cout<<"Case #"<<i<<": "<<ds()<<" "<<ws()<<endl;
    }
    return 0;
}
