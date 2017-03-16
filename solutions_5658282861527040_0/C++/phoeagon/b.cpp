#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int work(){
    int a , b , k ;
    scanf("%d%d%d",&a,&b,&k);
    long long ans = 0 ;
    for ( int i = 0 ; i < a ; ++i )
        for ( int j = 0 ; j < b ; ++j )
            if ( (i & j) < k )
                ++ans ;
    cout<<ans<<endl;
}
int main(){
    int t ;
    scanf("%d",&t);
    for ( int i = 0 ; i < t; ++i ){
        cout<<"Case #"<<i+1<<": ";
        work();
    }
}
