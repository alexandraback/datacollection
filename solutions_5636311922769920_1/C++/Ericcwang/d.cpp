#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int T;
    cin>>T;
    for (int time=1;time<=T;time++){
        int K,C,S;
        cin>>K>>C>>S;
        int step=min(K,C);
        int minS=(K+step-1)/step;
        cout<<"Case #"<<time<<":";
        if (minS>S) cout<<" IMPOSSIBLE"<<endl;else{
            for (int i=0;i<K;i++)
            if (i%step==0){
                long long id=i;
                for (int j=1;j<C;j++){
                    id*=K;
                    if (j<K) id+=j;
                }
                cout<<" "<<(id+1);
            }
            cout<<endl;
        }
    }
}
