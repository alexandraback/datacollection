#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX/3
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(){
    string s;cin>>s;
    string a = "";
    for(int i=0;i<s.size();i++){
        if(a.size()==0){
            a = a + s[i];
        }else{
            if(s[i]>a[0]){
                a.insert(a.begin(),s[i]);
            }else if(s[i]<a[0]){
                a = a + s[i];
            }else{
                string str1 = a + s[i];
                string str2 = "";
                str2.insert(str2.begin(),s[i]);
                str2 += a;
                if(str1>=str2) a = str1;
                else a = str2;
            }
        }
    }
    cout << a << endl;
}

int main(){
    int T;cin>>T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}
