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
vector<bool> selected;

int j,p,s,k;
int best;
vector<bool> best_s;
void rec(int i, int count) {
    if(27-i+count < best) return;
    if(i==27) {
        if(count > best) {
            best = count;
            best_s = selected;
        }

    } else {
        int J = i%3;
        int P = (i/3)%3;
        int S = (i/9)%3;
        
        if(J<j && P < p && S < s) {
            int& a = JP[J][P];
            int& b = JS[J][S];
            int& c = PS[P][S];
            if(a < k && b < k && c < k) {
                a++;
                b++;
                c++;
                selected[i] = true;
                rec(i+1,count+1);
                a--;
                b--;
                c--;
                selected[i] = false;
            }
        }
        rec(i+1,count);

    }
    
}

void sol() {
    cin>>j>>p>>s>>k;
    memset(JP,0,sizeof(JP));
    memset(PS,0,sizeof(PS));
    memset(JS,0,sizeof(JS));
    best=0;
    selected.resize(27,false);
    rec(0,0);
    cout<<best<<endl;
    for(int i = 0; i< 27;i++) {
        int J = i%3;
        int P = (i/3)%3;
        int S = (i/9)%3;
        if(best_s[i]) {
            cout<<J+1<<" "<<P+1<<" "<<S+1<<endl;
        }
    }


}

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        sol();
    }
}
