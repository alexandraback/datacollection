#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define S(x) scanf("%d",&x)
#define SD(x) scanf("%lf",&x)
#define SL(x) scanf("%lld",&x)
#define pb(x) push_back(x)
#define mp make_pair
#define F(i, a, b) for (int i = int(a); i < int(b); i++)
#define forit(it, a) for (it = (a).begin(); it != (a).end(); it++)
#define M(x,i) memset(x,i,sizeof(x))

/* -------------------CODE GOES HERE---------------------- */

bool isBetter(string a, string b, string x, string y){

    int m = stoi(a);
    int n = stoi(b);
    int p = stoi(x);
    int r = stoi(y);

    if(abs(m-n) > abs(p-r)) return true;
    if(abs(p-r) > abs(m-n)) return false;
    if(m < p) return false;
    if(p < m) return true;
    if(n < r) return false;
    if(r < n) return true;
    return true;
}

string tostring(int i, int n){

    string x = to_string(i);
    int l = x.length();
    F(i,0,n-l){
        x = '0' + x;
    }
    return x;
}

bool subpart(string a, string b){

    F(i,0,b.length()){
        if(b[i] == '?') continue;
        if(b[i] != a[i]) return false;
    }

    return true;
}

int main(){

    int T, tst = 1; S(T);
    string c,j,C,J;
    int n,l;
    string a,b;

    while(T--){

        cin>>c>>j;
        n = c.length();

        C = c; J = j;

        F(i,0,n){
            if(c[i] == '?') C[i] = '0';
            if(j[i] == '?') J[i] = '0';
        }

        l = int(pow(10,n));

        F(i,0,l){
            F(jj,0,l){
                a = tostring(i,n);
                b = tostring(jj,n);

                if((!subpart(a,c)) || (!subpart(b,j))) continue;
                if(isBetter(C,J,a,b)){
                    C = a;
                    J = b;
                }
            }
        }

        printf("Case #%d: ", tst++);
        cout<<C<<" "<<J<<endl;
    }
}
