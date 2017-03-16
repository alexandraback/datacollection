#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

typedef int ttyp;
#define fors(bg,en) for(int i=bg;i<en;i++)
#define forso(j,bg,en) for(int j=bg;j<en;j++)
#define forz(n) for(int i=0;i<n;i++)
#define forzo(j,n) for(int j=0;j<n;j++)
#define forsz(v) for(int i=0;i<v.size();i++)
#define forszo(j,v) for(int j=0;j<v.size();j++)
#define MP make_pair
#define sz(v) v.size()
#define MODV 1000000007
bool vis[26];

bool notz(string s){
    forszo(j,s)
    if(s[j]!=s[0]){
        return true;
    }
    return false;
}
string getuniq(string s){
    string ret="";
    ret = ret + s[0];
    for(int i=1;i<s.size();i++)
    if(s[i]!=ret[ret.size()-1])
        ret = ret + s[i];
    return ret;
}
bool notok(vector<string> vs, vector<int> b, vector<int> c){
    int ix;
    forz(26)
    if(b[i]!=-1 && b[i]==c[i])
        return true;
    forsz(vs){
        string st = getuniq(vs[i]);
        forszo(j,st)
        if(st[j]!=st[0] && st[j]!=st[st.size()-1]){
            ix = st[j] - 'a';
            if(b[ix]!=-1 || c[ix]!=-1)
                return true;
            b[ix]=c[ix]=-2;
        }
    }
    return false;
}
void dfs(int ix, vector<int> b){
    if(vis[ix])
        return ;
    vis[ix]=true;
    if(b[ix]>=0)
        dfs(b[ix], b);
    return;
}
long long fact(int v){
    if(v<=1) return 1;
    return (v * fact(v-1)) % MODV;
}

void doit(){
    int n ;  //a[0] fully a;
    vector<int> a, b, c; //b = stores ends with index, c=stores ends with
    int bix, cix;
    bool tnotok = false;
    long long ret =0 ;
    vector <string> vs;
    b.resize(26,-1), c.resize(26,-1), a.resize(26,0);
    memset(vis,0,sizeof(vis));
    cin>>n;
    vs.resize(n);
    forz(n){
        cin>>vs[i];
        if(notz(vs[i])){
            bix = vs[i][0]-'a';
            cix =vs[i][vs[i].size()-1]-'a';
            if(b[bix]!=-1 || c[cix]!=-1){
                tnotok =true;
            }
            b[bix]=cix;
            c[cix]=bix;
        }
        else
            a[(vs[i][0]-'a')]++;
    }
    //cout<<"here 0 "<<tnotok<<" "<<endl;

    if(tnotok || notok(vs, b, c)){
        cout<<0<<endl;
        return;
    }
    //cout<<"here 1"<<endl;
    forz(26)
    if(!vis[i] && b[i]>=0 && c[i]<0){
        dfs(i, b);
        ret++;
    }
    forz(26)
    if(!vis[i] && a[i]>0){
        ret++;
    }
    //cout<<"here 2 "<<ret<<endl;
    ret = fact(ret);
    forz(26)
    if(a[i]){
        ret = (ret * fact(a[i])) % MODV;
    }
    cout<<ret<<endl;
    return;

}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
      cout<<"Case #"<<i<<": ";
      doit();
    }
    return 0;
}
