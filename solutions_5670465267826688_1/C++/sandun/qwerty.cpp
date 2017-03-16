#include <bits/stdc++.h>
using namespace std;
const int maxn = 411500;
const int I = 2;
const int J = 3;
const int K = 4;
int MAP[5][5]={
    {0,0, 0, 0, 0},
    {0,1, 2, 3, 4},
    {0,2,-1, 4,-3},
    {0,3,-4,-1, 2},
    {0,4, 3,-2,-1}
};
int calc(int x,int y){
    int sign=1;
    if(x<0){
        x=-x;
        sign*=-1;
    }
    if(y<0){
        y=-y;
        sign*=-1;
    }
    return sign*MAP[x][y];
}
char s[maxn];
int a[maxn];
int wn[maxn];
int wv[maxn];
template<typename T>
void output(T a[],int n){
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool check(int n){
    wn[0]=a[0];
    static bool ok[maxn];
//    memset(ok,false,sizeof(ok));
    ok[0]|=(wn[0]==I);

//    output(a,n);
    for(int i=1;i<n;++i){
        wn[i]=calc(wn[i-1],a[i]);
        ok[i]=(wn[i]==I);
        ok[i]|=ok[i-1];
    }
//    output(ok,n);
    if(wn[n-1]!=-1){
        return false;
    }

    wv[n-1]=a[n-1];
    for(int i=n-2;i>=0;--i){
        wv[i]=calc(a[i],wv[i+1]);
    }
//    output(wv,n);
    for(int i=n-1;i>=2;--i){
        if(wv[i]==K&&ok[i-2]){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("E:\\in.txt","r",stdin);
    freopen("E:\\out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;++cas){
        cout<<"Case #"<<cas<<": ";
        int L;
        long long X;
        cin>>L>>X;
        if(X>=16){
            X=X%16+16;
        }
        cin>>s;
        int n=X*L;
        for(int i=L;i<n;++i){
            s[i]=s[i%L];
        }
        for(int i=0;i<n;++i){
            a[i]=s[i]-'i'+2;
        }
        if(check(n)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

