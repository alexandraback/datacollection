#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdint>
using namespace std;


int JP[3][3];
int PS[3][3];
int JS[3][3];
int j,p,s,k;
void sol(bool pp) {
    memset(JP,0,sizeof(JP));
    memset(PS,0,sizeof(PS));
    memset(JS,0,sizeof(JS));
    int count = 0;
    for(int J=0;J<j;J++) {
        for(int P=0;P<p;P++) {
            for(int S=0;S<s;S++) {
                int& a = JP[J][P];
                int& b = PS[P][S];
                int& c = JS[J][S];
                if(a<k && b<k && c<k) {
                    if(!pp)
                        cout<<J+1<<" "<<P+1<<" "<<S+1<<endl;
                    count++;
                    a++;
                    b++;
                    c++;
                }
            }
        }
    }
    if(pp) cout<<count<<endl;

}
void sol() {
    cin>>j>>p>>s>>k;
    sol(true);
    sol(false);
}
int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        sol();
    }
}
