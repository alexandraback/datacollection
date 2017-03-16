#include <bits/stdc++.h>
using namespace std;
#define ll long long

string a, b;
ll sa, sb;
ll p(ll a, int b){
    ll ans=1;
    for(int i=0; i<b; ++i) ans*=a;
    return ans;
}

void updatea(int i){
    sa += (long long)(a[i]-'0')*p(10,a.size()-i-1);
}
void updateb(int i){
    sb += (long long)(b[i]-'0')*p(10,b.size()-i-1);
}

ll stoi(string a){
    ll ans=0;
    for(int i=0; i<a.size(); ++i){
        ans += (a[i]-'0')*p(10,a.size()-i-1);
    }
    return ans;
}

vector<string>alla, allb;
void dfs(string a){
    bool found = false;
    for(int i=0; i<a.size(); ++i){
        if(a[i] == '?'){
            for(int j='0'; j<='9';++j){
                a[i] = j;
                found = true;
                dfs(a);
            }
        }
    }
    if(!found){
        alla.push_back(a);
    }
}
void dfs1(string b){
    bool found = false;
    for(int i=0; i<b.size(); ++i){
        if(b[i] == '?'){
            for(int j='0'; j<='9';++j){
                b[i] = j;
                found = true;
                dfs1(b);
            }
        }
    }
    if(!found){
        allb.push_back(b);
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("Bans.out","w",stdout);
    int t;
    cin >> t;
    for(int IN=0; IN<t; ++IN){
        cin >> a >> b;
        alla.clear(), allb.clear();
        dfs(a);
        dfs1(b);
        //cout <<a << " " << b<< endl;
        //cout << allb.size() << endl;
        int mn = 1e9; string ai, bi;
        for(int i=0; i<alla.size(); ++i){
            for(int j=0; j<allb.size(); ++j){
                //cout << alla[i] << " "<< allb[j] << endl;
                if(abs(stoi(alla[i])-stoi(allb[j])) < mn){
                    mn = abs(stoi(alla[i])-stoi(allb[j]));
                    ai = alla[i], bi = allb[j];
                }
                if(abs(stoi(alla[i])-stoi(allb[j])) == mn){
                    if(stoi(ai) > stoi(alla[i])){
                        ai = alla[i]; bi = allb[j];
                    }
                    if(stoi(ai) == stoi(alla[i]) && stoi(bi) > stoi(allb[j])){
                        ai = alla[i]; bi = allb[j];
                    }
                }
            }
        }
        //cout << sa << " " << sb << endl;
        cout << "Case #" << IN+1 << ": " << ai << " " << bi << endl;
    }
}
