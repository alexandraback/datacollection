#include <bits/stdc++.h>
using namespace std;
int test;

bool can(char A,char B){
    if (A=='?') return 1;
    return A==B;
}

void tr(string &s,char ch){
    for (int i=0;i<s.size();i++)
    if (s[i]=='?') s[i]=ch;
}

long long dif(string a,string b){
    long long R=0;
    for (int i=0;i<a.size();i++)
    R=R*10+a[i]-b[i];
    return abs(R);
}

void sol(){
    string c,s,S,C,ca,sa,Ca,Sa;
    cin>>c>>s;
    S=s;
    C=c;
    int i=0;
    Sa=s;
    Ca=c;
    tr(Sa,'0');
    tr(Ca,'0');
    for (int i=0;i<s.size();i++){
        for (char cc='0';cc<='9';cc++)
        for (char ss='0';ss<='9';ss++)
        if (can(C[i],cc) && can(S[i],ss)){
            sa=s;
            ca=c;
            sa[i]=ss;
            ca[i]=cc;

            tr(sa,'0');
            tr(ca,'9');
            if (make_pair(dif(ca,sa),make_pair(ca,sa))<make_pair(dif(Ca,Sa),make_pair(Ca,Sa))) Ca=ca,Sa=sa;
            sa=s;
            ca=c;
            sa[i]=ss;
            ca[i]=cc;

            tr(sa,'9');
            tr(ca,'0');
            if (make_pair(dif(ca,sa),make_pair(ca,sa))<make_pair(dif(Ca,Sa),make_pair(Ca,Sa))) Ca=ca,Sa=sa;
            sa=s;
            ca=c;
            sa[i]=ss;
            ca[i]=cc;

            tr(sa,'0');
            tr(ca,'0');
            if (make_pair(dif(ca,sa),make_pair(ca,sa))<make_pair(dif(Ca,Sa),make_pair(Ca,Sa))) Ca=ca,Sa=sa;
            sa=s;
            ca=c;
            sa[i]=ss;
            ca[i]=cc;

            tr(sa,'9');
            tr(ca,'9');
            if (make_pair(dif(ca,sa),make_pair(ca,sa))<make_pair(dif(Ca,Sa),make_pair(Ca,Sa))) Ca=ca,Sa=sa;


        }

        if (s[i]=='?') s[i]=c[i];
        if (c[i]=='?') c[i]=s[i];
        if (s[i]=='?') s[i]=c[i]='0';
    }

            sa=s;
            ca=c;
            tr(sa,'0');
            tr(ca,'0');
            if (make_pair(dif(ca,sa),make_pair(ca,sa))<make_pair(dif(Ca,Sa),make_pair(Ca,Sa))) Ca=ca,Sa=sa;


    test++;
    cout<<"Case #"<<test<<": "<<Ca<<" "<<Sa<<endl;
}

int main() {
    freopen("BL.in","r",stdin);
    freopen("BL.txt","w",stdout);
    int t;
    cin>>t;
    while (t--){
        sol();
    }
    return 0;
}
