#include <bits/stdc++.h>
using namespace std;
const vector <string> v=
{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int test;
int n;
bool fin=0;
vector<int> c;
string ans;

void add(int x){
    ans+=char('0'+x);
    for (int i=0;i<v[x].size();i++)
    c[v[x][i]-'A']--;
    n-=v[x].size();
}

void sol(){
    string s;
    cin>>s;

    n=s.size();
    c.clear();
    c.resize(26,0);

    for (int i=0;i<s.size();i++) c[s[i]-'A']++;
/*
    for (char i='A';i<='Z';i++){
        cout<<i<<" "<<int(i-'A')<<" = ";
        for (int j=1;j<10;j+=2) {
            int k=0;
            for (int z=0;z<v[j].size();z++)
            if (v[j][z]==i) k=1;
            if (k) cout<<j<<" ";
        }
        cout<<endl;
    }
*/
   ans="";
    while (c[6])
        add(8);
    while (c[20])
        add(4);
    while (c[22])
        add(2);
    while (c[23])
        add(6);
    while (c[25])
        add(0);
    while (c[5])
        add(5);
    while (c[7])
        add(3);
    while (c[18])
        add(7);
    while (c[14])
        add(1);
    while (c[4])
        add(9);
    fin=0;
    sort(ans.begin(),ans.end());
    test++;
    cout<<"Case #"<<test<<": "<<ans<<endl;
}

int main() {
    freopen("A2.in","r",stdin);
    freopen("A2.txt","w",stdout);
    int t;
    cin>>t;
    while (t--){
        sol();
    }
    return 0;
}
