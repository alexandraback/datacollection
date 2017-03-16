#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define frl(a, b, c) for( (a) = (b);( a) < (c); (a++))
#define fru(a, b, c) for( (a) = (b); (a) <= (c); (a++))
#define frd(a, b, c) for( (a) = (b); (a) >= (c); (a--))
#define mst(a, b) memset(a, b, sizeof(a))
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sc(a) scanf("%c", &a)

#define pb(a) push_back(a)
#define mp make_pair
#define nwl puts("");
#define sp << " " <<

#define sz size()
#define bg begin()
#define en end()
#define X first
#define Y second

#define vi vector <int>
#define vs vector <string>
#define ll long long int
#define dec int i = 0, j= 0, k = 0;

#define i(n) cin >> n;
#define p(s) cout << s;
#define pau system("pause");


#define mod 1000000007

vector<int> v;
vector<string> str;

bool check(){
    int taken[2000] ;
    mst(taken, 0);
    dec;
    int l1 = str.sz;
    string s;
    frl(i, 0, l1){
        s += str[v[i]];
    }
    l1 = s.sz;
//    cout <<   s << endl;
    bool flag = 1;
    frl(i, 0, l1){
        if(i && s[i] == s[i-1])
            continue;
        else{
            if(taken[s[i]]){
                flag = 0;
                break;
            }
            else
                taken[s[i]] = 1;
        }
    }
//    cout << flag << endl;
    return flag;


}


int main(){
    freopen("B-small-attempt6.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t, n;
    int te = 1;
    cin >> t;
    dec;
    for(int jj = 1; jj <= t; jj++){
        v.clear();
        str.clear();

        cin >> n;
        frl(i, 0, n){
            string str1;
            cin >> str1;
            str.pb(str1);
        }
        frl(i, 0, n){
            v.pb(i);
        }
        ll ans = 0;
        do{
            if(check())
                ans += 1;
        } while(next_permutation(v.begin(), v.end()));
        cout << "Case #" << jj << ": " << ans << endl;
    }

}













