#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long cd(string s){
    int n = s.size();
    long long a=0, b=0;
    int i;
    for(i=1;i*2<n;i++){
        a = a*10+s[i] - '0';
        b = b*10+s[i+n/2] - '0';
    }
    //cout<<s<<" "<<a<<" "<<b<<endl;

    return a > b?a-b:b-a;
}
string dfs(string cs, string js, int lv){
    int i;
    if(lv == cs.size()){
        return " "+cs+" "+js;
    }
    int big = 0;
    if(cs[lv] != '?' && js[lv] != '?'){
        return dfs(cs, js, lv+1);
    }
    for(i=0;i<lv;i++){
        if(cs[i] > js[i])
        {
            big = 1;
            break;
        }
        else if(js[i] > cs[i])
        {
            big = -1;
            break;
        }
    }

    if(big == 1){
        //cs bigger
        if(cs[lv] == '?')
            cs[lv] = '0';
        if(js[lv] == '?')
            js[lv] = '9';
        return dfs(cs, js, lv+1);
    }
    else if(big == -1){
        //js is bigger
        if(cs[lv] == '?')
            cs[lv] = '9';
        if(js[lv] == '?')
            js[lv] = '0';
        return dfs(cs, js, lv+1);
    }
    else{
        //same
        long long dif = 999999999999999999ll;
        string ret = "";
        long long td = 0ll;
        string tmp = "";
        if(cs[lv] == '?' && js[lv] != '?'){
            cs[lv] = js[lv];
            tmp = dfs(cs, js, lv+1);
            td = cd(tmp);
            if(td == dif && tmp < ret)
                ret = tmp;
            else if(td < dif)
                dif = td, ret = tmp;
            if(js[lv] != '0'){
                cs[lv] = js[lv] - 1;
                tmp = dfs(cs, js, lv+1);
                td = cd(tmp);
                if(td == dif && tmp < ret)
                    ret = tmp;
                else if(td < dif)
                    dif = td, ret = tmp;
            }
            if(js[lv] != '9'){
                cs[lv] = js[lv] + 1;
                tmp = dfs(cs, js, lv+1);
                td = cd(tmp);
                if(td == dif && tmp < ret)
                    ret = tmp;
                else if(td < dif)
                    dif = td, ret = tmp;
            }
        }else if(cs[lv] != '?' && js[lv] == '?'){
            js[lv] = cs[lv];
            tmp = dfs(cs, js, lv+1);
            td = cd(tmp);
            if(td == dif && tmp < ret)
                ret = tmp;
            else if(td < dif)
                dif = td, ret = tmp;
            //cout<<td<<" "<<ret<<endl;
            if(cs[lv] != '0'){
                js[lv] = cs[lv] - 1;
                tmp = dfs(cs, js, lv+1);
                td = cd(tmp);
                if(td == dif && tmp < ret)
                    ret = tmp;
                else if(td < dif)
                    dif = td, ret = tmp;
            }
            if(cs[lv] != '9'){
                js[lv] = cs[lv] + 1;
                tmp = dfs(cs, js, lv+1);
                td = cd(tmp);
                if(td == dif && tmp < ret)
                    ret = tmp;
                else if(td < dif)
                    dif = td, ret = tmp;
            }
        }else{
            cs[lv] = js[lv] = '0';
            tmp = dfs(cs, js, lv+1);
            td = cd(tmp);
            if(td == dif && tmp < ret)
                ret = tmp;
            else if(td < dif)
                dif = td, ret = tmp;

            cs[lv] = '0', js[lv] = '1';
            tmp = dfs(cs, js, lv+1);
            td = cd(tmp);
            if(td == dif && tmp < ret)
                ret = tmp;
            else if(td < dif)
                dif = td, ret = tmp;

            cs[lv] = '1', js[lv] = '0';
            tmp = dfs(cs, js, lv+1);
            td = cd(tmp);
            if(td == dif && tmp < ret)
                ret = tmp;
            else if(td < dif)
                dif = td, ret = tmp;

        }
        return ret;
    }
}
int main()
{
    int tn, i, j;
    freopen("gcbs.in", "r", stdin);
    freopen("gcbs.out", "w", stdout);
    scanf("%d", &tn);
    for(int tt = 1; tt<=tn;tt++){
        string cs, js;
        cin>>cs>>js;
        cout<<"Case #"<<tt<<":"<<dfs(cs, js, 0)<<endl;
    }
}
