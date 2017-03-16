#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include<algorithm>
#include <math.h>
#include <string.h>


using namespace std;
const int BIGNUM = 1000000007;
int T;
int N;
vector<string> VS;
vector<vector<int> > VVI;

const int Nmax = 110;
char C_Adj[Nmax][Nmax];
int CompOf[Nmax];
bool mark[Nmax];
int Ncomp;

bool isAdj(string u, string v){
    return (u[u.size()-1] == v[0]);
}

bool isAdjByContent(string u, string v){
    set<char> SC;
    for(int i = 0; i<u.size(); i++) SC.insert(u[i]);
    for(int i = 0; i<v.size(); i++)
        if (SC.count(v[i])>0) return true;
    return false;
}

void DFS(int i){
    for(int j = 0; j<N; j++)
    if ((mark[j]) and (C_Adj[i][j] ==1)){
        CompOf[j] = CompOf[i];
        mark[j] = false;
        DFS(j);
    }
}

bool sameChar(string SS){
    string s = "" + SS;
    bool res = true;
    sort(s.begin(), s.end());
    for(int i = 1; i<s.size(); i++)
        if(s[i] != s[i-1]) return false;
    return res;
}

bool check(string XX){
    bool res = true;
    for(int i = 0; i<XX.size(); i++){
        for(int j=i+1; j<XX.size(); j++)
            if (XX[i] == XX[j])
            if (j-i>1) return false;
    }
    return res;
}

long countWays(vector<string> S){

    //for(int i = 0; i<S.size(); i++) cout <<S[i]<<" ";

    sort(S.begin(), S.end());
    string XX;
    long res = 0;

    for(int i = 0; i<S.size(); i++){
        XX = S[i];
        bool mark[Nmax];
        memset(mark, true, Nmax);
        mark[i] =false;
        int cnt = 0;

        while(true){
            bool found = false;
            vector<string> Cands;
            Cands.clear();
            int n = -1;
            for(int j = 0; j<S.size(); j++){
                if (mark[j] == false) continue;
                if (isAdj(XX, S[j])){
                    Cands.push_back(S[j]);
                    found = true;
                    n++;
                    mark[j] = false;
                };
            };

            if (not found) break;

            int c = 0;
            for(int j = 0; j<=n; j++)
                if (sameChar(Cands[j])) {
                    cnt++;
                    XX = XX+Cands[j];
                    c++;
                };

            if (c>n) continue;

            if (c == n){
                XX = XX+Cands[n];
                cnt++;
            }
            else break;
        };// while true

        if (cnt >= S.size()-1)
            if (check(XX)) res++;
    };

    return res;
};


long calcFor(vector<int> V){
    //cout <<" calc for this: "<<endl;
    //for(int i = 0; i<V.size(); i++)
    //    cout <<" -- "<< VS[V[i]]<<endl;
   // cout <<endl<<endl;

    vector<string> myVS;
    for(int i = 0; i<V.size(); i++)
        myVS.push_back(VS[V[i]]);

    sort(myVS.begin(), myVS.end());

    bool myMark [Nmax];
    memset(myMark, true, Nmax);


    int myCompOf[Nmax];
    memset(myCompOf, -1, Nmax);


    vector<string> Str;
    vector<int> Vfac;


    for(int i = 0; i<myVS.size(); i++){
        if (myCompOf[i] >=0) continue;
        myCompOf[i] = i;
        Str.push_back(myVS[i]);

        if (sameChar(myVS[i])){
            int cnt = 1;
            for(int j = i+1; j<myVS.size(); j++)
            if (sameChar(myVS[j]) and (myVS[j][0] == myVS[i][0])){
                myCompOf[j] = i;
                cnt++;
            };
            Vfac.push_back(cnt);
        };
    };



    long ans = 1;
    ans = countWays(Str);

    ans = ans %BIGNUM;

    for(int i = 0; i<Vfac.size(); i++){
        int k = Vfac[i];
        for(int n = 1; n<=k; n++)
            ans = (ans * n) % BIGNUM;
    };
    return ans;
}

void solve(){
    memset(C_Adj,0, sizeof(C_Adj));
    for(int i = 0; i<N; i++)
    for(int j = i+1; j<N; j++ )
    if (isAdjByContent(VS[i], VS[j])){
        C_Adj[i][j] = 1;
        C_Adj[j][i] = 1;
    };

    memset(CompOf,0, sizeof(CompOf));
    Ncomp = 0;
    memset(mark,true, sizeof(mark));
    for(int i = 0; i<N; i++){
        if (mark[i]){
            Ncomp++;
            CompOf[i] = Ncomp;
            mark[i] = false;
            DFS(i);
        }
    };
    VVI.clear();
    VVI.resize(Ncomp+1);
    for(int c = 1; c<=Ncomp; c++){
        //cout <<"Component: "<<c<<" : "<<endl;
        for(int i = 0; i<N; i++)
        if (CompOf[i] == c){
            VVI[c].push_back(i);
            //cout<< VS[i]<<endl;
        };
    };


//main is here:
// n!:
    long Nfac = 1;
    for(int i = 1; i<=Ncomp; i++)
        Nfac = (Nfac * i) % BIGNUM;
//each component:
    long ans = 1;
     for(int c = 1; c<=Ncomp; c++){
        ans = (ans * calcFor(VVI[c]) ) % BIGNUM;
        if (ans == 0) break;
     };


    ans = (Nfac * ans) % BIGNUM;

    cout <<ans<<endl;
};


void input_solve(){
    cin >>T;
    for(int i = 1; i<=T; i++){
        cin >>N;
        VS.clear();
        for(int j = 1; j<=N; j++){
            string s;
            cin >>s;
            VS.push_back(s);
        }
        cout <<"Case #"<<i<<": ";
        //for(int j = 0; j<N; j++) cout <<VS[j]<<endl;
        solve();
    }
}


int main()
{
    input_solve();
    return 0;
}
