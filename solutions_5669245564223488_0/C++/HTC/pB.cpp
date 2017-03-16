#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
int N,cnt = 0;
vector<string> v;
long long MOD = 1000000007;
char pre[104],suf[104];
int scnt[104],pcnt[104],all[104];
int type[104]; // 1 = has suf+pre 2 = only suf or pre
int nxt[104],num[104],X,addX[104];
int isCycle(int k){
    int now= k,id=num[k];
    while(nxt[now] != -1){
        //cout << "now = " << now<<"\n";
        now = nxt[now];
        if(num[now] != -1)id = num[now];
        if(now == k)return 1;
    }
   // cout << "k: " << k <<"\n";
   // cout << "over\n";
    if(id == -1){id = X;X++;}
    //cout << "X = "<< X << "\n";
    now = k;
    num[now] = id;
    while(nxt[now] != -1){
        now = nxt[now];
        num[now] = id;
      //  cout << "now = " << now <<"\n";
    }

    return 0;
}
int appinone[105],appinall[105];
int isValid(){
    for(int i=0;i<26;i++)appinall[i] = addX[i] = 0;
    for(int i=0;i<v.size();i++){
        //check "bab"
        for(int j=0;j<26;j++)appinone[j] = -1;
        for(int j=0;j<v[i].size();j++){
            if(appinone[v[i][j]-'a'] != -1){
                if(appinone[v[i][j]-'a'] != j-1)return 0;
            }
            appinone[v[i][j] - 'a'] = j;
        }
        pre[i] = v[i][0];
        suf[i] = v[i][(int)v[i].size()-1];
        for(int j=0;j<26;j++)appinone[j] = -1;
        for(int j=1;j<int(v[i].size())-1;j++){
            if(v[i][j] != pre[i] && v[i][j] != suf[i]){
                appinone[v[i][j]-'a'] = 1;
                //cout << "char : " << v[i][j] <<"\n";
            }
        }
        //count inside char
        for(int j=0;j<26;j++){
            if(appinone[j] == 1)appinall[j]++;
            if(appinall[j] > 1)return 0;
        }
    }

    // both inside and (suf or pre)
    for(int i=0;i<v.size();i++){
        if(appinall[pre[i]-'a'] > 0)return 0;
        if(appinall[suf[i]-'a'] > 0)return 0;
    }
//cout << "here\n";
    for(int i=0;i<26;i++){
        pcnt[i] = 0;
        scnt[i] = 0;
        all[i] = 0;
        nxt[i] = -1;
    }
    for(int i=0;i<v.size();i++){
        if(pre[i] != suf[i]){
            pcnt[pre[i]-'a']++;
            scnt[suf[i]-'a']++;
            //cout << "here suf is " << suf[i] << " pre is " << pre[i] << "\n";
            if(pcnt[pre[i]-'a'] > 1)return 0;
            if(scnt[suf[i]-'a'] > 1)return 0;
            type[i] = 0;
        }else{
            type[i] = 1;
            all[pre[i]-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        if(scnt[i] == 1 && pcnt[i] == 0){
            for(int j=0;j<N;j++){
                if(type[j] == 1 && suf[j] == i+'a'){type[j] = 0;break;}
            }
        }
        if(scnt[i] == 0 && pcnt[i] == 1){
            for(int j=0;j<N;j++){
                if(type[j] == 1 && suf[j] == i+'a'){type[j] = 0;break;}
            }
        }
    }
    for(int i=0;i<N;i++){
        if(type[i] == 1)continue;

            for(int j=0;j<N;j++){
                if(i == j)continue;
                if(pre[j] == suf[i] && type[j] == 0){
                    nxt[i] = j;
                    //cout << "nxt " << i << " is " << nxt[i] << "\n";
                    break;
                }
            }

    }
    //cout << "here\n";
    for(int i=0;i<N;i++){
        num[i] = -1;
        addX[pre[i]-'a'] = 1;
        addX[suf[i]-'a'] = 1;
    }
    for(int i=0;i<N;i++){
        if(type[i] == 0){
            addX[pre[i]-'a'] = 0;
            addX[suf[i]-'a'] = 0;
        }
    }
    for(int i=0;i<N;i++){
        if(type[i] == 0 && isCycle(i))return 0;
    }
   // cout << "here X = " << X <<"\n";
    for(int i=0;i<26;i++){
        X += addX[i];
    }
    return 1;
}
long long fact(int n){
    long long res = 1;
    for(int i=2;i<=n;i++){
        res = res * i ;
        res %= MOD;
    }
    return res;
}
int main (){
    int T,tmp,flag;
    string s;
    cin >> T;
    for(int ca=1;ca<=T;ca++){
        cout << "Case #" << ca << ": ";
        cin >> N;
        v.clear();
        for(int i=0;i<N;i++){
            cin >> s;
            v.push_back(s);
        }
        X = 0;
        if(isValid() == 0){
            cout << "0\n";
            continue;
        }else{
            //cout << "valid\n";
            long long ans = 1;
            ans *= fact(X);
           // cout << "X = "<< X << "\n";
            ans %= MOD;
            for(int i=0;i<26;i++){
                ans *= fact(all[i]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

