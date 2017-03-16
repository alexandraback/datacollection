#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int cnt[30];
       //[length][number of instances]
double dp[111][111];
double chance[211];
string alp;
string targ;
string ralp;

double exp;
int mxInst = 0;

int k, l, s;
int getInst(string s){
    int ans = 0;
    for(int i = 0; i + targ.size() - 1 < s.size(); ++i){
        bool tr = 1;
        for(int j = 0; j < targ.size(); ++j){
            if(targ[j] != s[i+j])tr = 0;
        }
        ans+=tr;
    }
    return ans;
}



void gen(int st, string s, double chance){
    if(st == 0){

        int inst = getInst(s);
        //if(inst)cout<<inst<<endl;
        if(inst > mxInst) mxInst = inst;
        //cout<<s<<' '<<chance<<endl;
        exp+=1ll*inst*chance;
    }
    else{
        for(int i = 0; i < ralp.size(); ++i){
            gen(st - 1, s + ralp[i], chance * (1ll*cnt[ralp[i] - 'A']));
        }
    }
}


void solve(){

    mxInst = 0; exp = 0;
    cin>>k>>l>>s>>alp>>targ;
    ralp = alp;
    sort(ralp.begin(),ralp.end());
    ralp.resize(unique(ralp.begin(),ralp.end()) - ralp.begin());
    //cout<<ralp<<endl;
    for(int i = 0; i < 30; ++i) cnt[i] = 0;
    for(int i = 0; i < k; ++i){
        cnt[alp[i] - 'A'] ++;
    }
    gen(s,"",1.0);

    for(int  i = 0 ; i < s; ++i)exp /= k;

    //printf("%0.7f %0.7f", double(mxInst), (exp));
    printf("%0.7f", double(mxInst) - (exp));
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }



    return 0;
}
