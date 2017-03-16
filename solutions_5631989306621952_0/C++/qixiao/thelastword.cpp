#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define fst first
#define snd second
#define fr(i, a, b) for(int i=a; i<b; i++)

string deal(string a, char b) {
    string temp = "";
    temp += b;
    string a1 = a+temp;
    string a2 = temp+a;
    if(a1 < a2) return a2;
    else return a1;
}

void main2() {
    string s;
    cin >> s;
    string res = "";
    res += s[0];
    for(int i=1; i<s.size(); i++) {
        res = deal(res, s[i]);
    }
    cout<<res<<endl;
}

int main() {
    int T;
    cin>>T;
    for(int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<": ";
        main2();
    }
}
