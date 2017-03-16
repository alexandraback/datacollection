#include <bits/stdc++.h>
using namespace std;

char S[10005];
int c[5][5]={
    {},
    {0,1,2,3,4},
    {0,2,1,4,3},
    {0,3,4,1,2},
    {0,4,3,2,1}
},  d[5][5]={
    {},
    {0,1,1,1,1},
    {0,1,-1,1,-1},
    {0,1,-1,-1,1},
    {0,1,1,-1,-1}
};

int main(){
    int T, L;
    long long X;
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>L>>X>>S;
        int a=1, b=1;
        for(int i=0; i<L; i++)
            S[i]-='i'-2, b*=d[a][S[i]], a=c[a][S[i]];
        bool ans = (a*b!=1)&(a==1&&X%2==1||a!=1&&X%4==2);
        //cout<<a<<" "<<b<<endl;
        int p = 0;
        bool ta = false;
        a = 1, b = 1;
        for(long long q=p+5*L; p<min(X*L,q); p++){
            b*=d[a][S[p%L]], a=c[a][S[p%L]];
            if(a*b==2){ta=true, p++; break;}
        }
        assert(a!=0);
        ans &= ta;
        ta = false;
        a = 1, b = 1;
        for(long long q=p+5*L; p<min(X*L,q); p++){
            b*=d[a][S[p%L]], a=c[a][S[p%L]];
            if(a*b==3){ta=true, p++; break;}
        }
        assert(a!=0);
        ans &= ta;
        cout<<"Case #"<<tt<<": "<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}
