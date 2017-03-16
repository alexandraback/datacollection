#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<string>
#include<iostream>
#define pb push_back
#define sc second
#define fs first
#define mp make_pair
using namespace std;
int N,M;
int ok=1,T,ind,K;

string S[101010];
int v[1010];
int loc[1010];
int stk[1010];
int m[1010][1010];
int kS=0;
string ret = "";
void mtry(){
    string calc = "";
    vector<int> viz;
    viz.resize(10);
    for(int i=1;i<=2*N;++i){
        if(viz[loc[i]] ==0){
            calc=calc+S[loc[i]];
            viz[loc[i]] = 1;
        }
    }
    if(ret == ""){
        ret = calc;
    }
    else if(calc < ret){
        ret = calc;
    }
}
void back(int x){
    if(x == 2*N){
        loc[x] = loc[1];
        mtry();
    }
    else{
        for(int i=1;i<=N;++i){
            if(v[i] == 0 && m[stk[kS]][i] == 1){
                loc[x]=i;
                v[i]=1;
                stk[++kS] = i;
                back(x+1);
                loc[x]=0;
                --kS;
                v[i]=0;
            }
        }
        if(kS > 1){
            int el = stk[kS];
            v[el] = 2;
            loc[x] = el;
            --kS;
            back(x+1);
            stk[++kS] = el;
            v[el]=1;
        }
    }
}
int main(){
    freopen("test3.in","r",stdin);
    freopen("test3.out","w",stdout);
    cin>>T;
    while(T--){
    ++ind;
    cin>>N>>M;
    ret = "";
    for(int i=0;i<=N;++i){
        for(int j=0;j<=N;++j){
        m[i][j]=0;
        }
        m[0][i]=1;
        m[i][0]=1;
    }
    for(int i=1;i<=N;++i){
        cin>>S[i];
    }
    for(int i=1;i<=M;++i){
        int a,b;
        cin>>a>>b;
        m[a][b]=1;
        m[b][a]=1;
    }
    kS=0;
    back(1);

    printf("Case #%d: ",ind);
    cout<<ret<<endl;
    }

}
