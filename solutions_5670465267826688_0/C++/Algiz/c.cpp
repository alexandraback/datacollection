#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int res[1111111];
int a[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0, 2,-1,4,-3},{0, 3,-4,-1,2},{0, 4,3,-2,-1}};

int conv(char c){
    if(c=='1')return 1;
    else if(c=='i')return 2;
    else if(c=='j')return 3;
    else if(c=='k')return 4;
}

string solve(){
    int l,x;
    string s = "",t;
    cin>>l>>x;
    cin>>t;
    for(int i = 0; i < x; ++i)
        s += t;
    res[0] = conv(s[0]);

    for(int i = 1; i < s.size(); ++i){
        int pr = res[i-1];
        bool neg = 0;
        if(pr < 0){pr = -pr;neg = 1;}
        res[i] = a[pr][conv(s[i])];
        if(neg)res[i] = -res[i];
    }

    /*for(int i = 0; i < s.size(); ++i)
        cout<<res[i]<<' ';
    cout<<endl;*/

    if(res[s.size() - 1] != -1)return "NO";
    bool tr1 = 0, tr2 = 0;

    for(int i = 0; i < s.size(); ++i){
        if(res[i] == 2)tr1 = 1;
        if(tr1 && res[i] == 4)tr2 = 1;
    }
    if(tr1 && tr2) return "YES";
    else return "NO";
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);



    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i){
        string t = solve();
        cout<<"Case #"<<i<<": "<<t<<"\n";
    }

    return 0;
}
