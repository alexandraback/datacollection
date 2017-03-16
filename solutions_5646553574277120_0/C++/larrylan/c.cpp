#include<bits/stdc++.h>
using namespace std;

int V, use[40];

bool test(int mx, int p){
    if(mx == 0){
        int c=0, cnt[350]={}, v[10]={};
        for(int i=0; i<40; i++)
            if(use[i]) v[c++]=i;//, cout<<i<<" ";
        //cout<<endl;
        for(int i=0; i<(1<<c); i++){
            int sum=0;
            for(int j=0; j<c; j++)
                sum += v[j]*((i>>j)&1);
            cnt[sum]++;
        }
        for(int i=0; i<=V; i++)
            if(!cnt[i])
                return false;
        /*for(int i=0; i<c; i++)
            cout<<v[i]<<" ";
        cout<<endl;*/
        return true;
    }
    for(int i=p; i<=V+1-mx; i++){
        if(use[i]) continue;
        use[i] = true;
        if(test(mx-1,i+1))
            return true;
        use[i] = false;
    }
    return false;

}

int main(){
    int T, C, D, M;
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>C>>D>>V;
        fill(use+1,use+V+1,0);
        for(int i=0; i<D; i++)
            cin>>M, use[M]++;
        int ans = 0;
        for(int i=0; i<=5; i++)
            if(test(i,1)){
                ans = i;
                break;
            }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
