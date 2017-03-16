#include<fstream>
#include<iostream>
#include<string>
using namespace std;

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
        cout<<s<<endl;
        int l = s.size();
        int i=0;
        int a = 0;

        while(s[i]!='/'){
            a = a*10 + (s[i]-'0');
            i++;
        }

        int b=0;
        i++;

        while(i<l){
            b=b*10 + (s[i]-'0');
            i++;
        }
        int pow = 1;
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
