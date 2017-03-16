#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cassert>
#include<queue>
using namespace std;
long long pot[55];

int main(){
//    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);

    int tc;
    cin>>tc;
    pot[0]=1;
    pot[1]=1;
    pot[2]=1;
    for(int i=3;i<55;i++)
        pot[i]=pot[i-1]*2;
    
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        long long B,M;
        cin>>B>>M;
        char c[B][B];
        for(int i=0;i<B;i++)
            for(int j=0;j<B;j++){
                if(i>=j)c[i][j]='0';
                else c[i][j]='1';
            }
        
        
        if( (1LL<<(B-2)) <M){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        
        M=(1LL<<(B-2))-M;
        cout<<"POSSIBLE"<<endl;

        for(int i=B-1;i>=0;i--){
            if(M>=pot[i]){
                M-=pot[i];
                c[i-1][B-1]='0';
            }
        }
        
        for(int i=0;i<B;i++){
            for(int j=0;j<B;j++){
                cout<<c[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}





