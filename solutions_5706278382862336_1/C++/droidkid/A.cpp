#include<fstream>
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;


ll gcd(ll a, ll b){

    if(a==0)return b;
    return gcd(b%a,a);

}

int main(){
    ifstream fin("A.in");
    ofstream fout("A.out");

    int T;
    fin>>T;
        string s;

    getline(fin,s);
    for(int t=1; t<=T; t++){

        fout<<"Case #"<<t<<": ";

        getline(fin,s);

        int l = s.size();
        int i=0;
        ll a = 0;

        while(s[i]!='/'){
            a = a*10 + (s[i]-'0');
            i++;
        }

        ll b=0;
        i++;

        while(i<l){
            b=b*10 + (s[i]-'0');
            i++;
        }

        ll d = gcd(a,b);
        //cout<<d<<endl;
        a = a/d;
        b = b/d;

        ll pow = 1;

        while(pow<b){
            pow = pow * 2;
        }

        if(pow>b){
            fout<<"impossible"<<endl;
            continue;
        }

        int ans = 1;
        while(2*a<b){
            b=b/2;
            ans++;
        }

        fout<<ans<<endl;

    }
}
