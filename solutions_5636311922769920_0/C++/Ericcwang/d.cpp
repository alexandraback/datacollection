#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int T;
    cin>>T;
    for (int time=1;time<=T;time++){
        int K,C,S;
        cin>>K>>C>>S;
        int minS=(K+C-1)/C;
        cout<<"Case #"<<time<<":";
        if (minS>S) cout<<"IMPOSSIBLE"<<endl;else{
            /*vector<long long> ans;
            for (int i=0;i<K;i++)
            if (i%C==0){
                long long id=i;
                for (int j=1;j<C;j++){
                if (i+j<K) id=id*K+j;else id=id*K;
                }
                ans.push_back(id);
            }
            for (long long x: ans) cout<<" "<<(x+1);
            cout<<endl;*/
            for (int i=0;i<K;i++)
            {
                long long id=i;
                for (int j=1;j<C;j++)
                    id=id*K;
                cout<<" "<<(id+1);

            }
            cout<<endl;
        }
    }
}
