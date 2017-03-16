#include<iostream>
#include<set>
#include<queue>
#include<cstdio>
unsigned long long ex[51];
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("Bout.txt","w",stdout);
    int cas,b;
    unsigned long long m,ma;
    cin>>cas;
    ex[0] = 1;
    ex[1] = 1;
    for(int i = 2 ; i< 51 ; i++)  ex[i] = ex[i-1]<<1;
for(int q=1;q<=cas;q++ ){
    cin>>b>>m;
    ma = 1ULL << (b-2);
    cout<<"Case #"<<q<<": ";
    if(m > ma){
        cout<<"IMPOSSIBLE"<<endl;
        continue;
    }
    cout<<"POSSIBLE"<<endl;
    cout<<0;
    for(int i = b-2 ;i >=0 ; i--){
        if(m && m >= ex[i]){
            m-=ex[i];
            cout<<1;
        }
        else cout<<0;
    }
    cout<<endl;
    for(int i = 1 ; i < b ; i++){
        for(int j =0;j<b;j++){
            if(j<=i)cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }
}
    return 0;
}
