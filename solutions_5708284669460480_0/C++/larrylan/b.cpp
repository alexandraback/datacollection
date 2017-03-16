#include<bits/stdc++.h>
using namespace std;

char P[200], Q[200];

int main(){
    cout<<setprecision(10);
    int T, K, L, S;
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>K>>L>>S>>P>>Q;
        int cnt[256]={};
        double exp=S-L+1;
        for(int i=0; i<K; i++)
            cnt[P[i]]++;
        for(int i=0; i<L; i++)
            exp = exp*cnt[Q[i]]/K;
        int off = 1;
        for(int i=1; i<L; i++,off++){
            int j;
            for(j=i; j<L; j++)
                if(Q[j-i]!=Q[j])
                    break;
            if(j == L)
                break;
        }
        int mx = S<L||exp==0?0:(S-L)/off+1;
        //cout<<off<<" "<<mx<<endl;
        cout<<"Case #"<<tt<<": "<<(mx-exp)<<endl;
    }
    return 0;
}
