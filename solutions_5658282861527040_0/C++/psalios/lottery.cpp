#include<iostream>
#include<cstdio>
#include<cstring>

const int MAXN = 1010;

using namespace std;

int A,B,K;

int main(){
    freopen( "lottery.in", "r", stdin );
    freopen( "lottery.out", "w", stdout );
    
    int T; cin>>T;
    
    for(int t=1;t<=T;t++){
            
            cin>>A>>B>>K;
            
            int c = 0;
            for(int i=0;i<A;i++)
                    for(int j=0;j<B;j++)
                            if( (i&j) < K )
                                c++;
            
            cout<<"Case #"<<t<<": "<<c<<endl;
            }
    
    return 0;
}
