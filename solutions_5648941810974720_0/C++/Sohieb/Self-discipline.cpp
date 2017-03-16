#include <bits/stdc++.h>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

#define Fastcin() cin.tie(0),cerr.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define oo       1e9
#define ll       long long
#define sc(x)    scanf("%d",&x)
#define scl(x)   scanf("%lld",&x)
#define lop(i,n) for(int i=0;i<n;++i)
#define sz(x)    (int)x.size()
#define all(x)   x.begin(),x.end()
#define f        first
#define s        second
#define pi       acos(-1)

int T;
string str;
int frq[26],need[26];
vector<string> arr;
vector<int> cur;

bool good(){
    for(int i=0;i<26;i++)
        if(need[i]>frq[i])return 0;
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    arr.push_back("ZERO");
    arr.push_back("TWO");
    arr.push_back("FOUR");
    arr.push_back("SIX");
    arr.push_back("EIGHT");
    arr.push_back("ONE");
    arr.push_back("THREE");
    arr.push_back("FIVE");
    arr.push_back("SEVEN");
    arr.push_back("NINE");
    cur.push_back(0);
    cur.push_back(2);
    cur.push_back(4);
    cur.push_back(6);
    cur.push_back(8);
    cur.push_back(1);
    cur.push_back(3);
    cur.push_back(5);
    cur.push_back(7);
    cur.push_back(9);
    sc(T);
    for(int C=1;C<=T;C++){
        cin>>str;
        string ans="";
        memset(frq,0,sizeof frq);
        for(int i=0;i<sz(str);i++)frq[str[i]-'A']++;
        for(int i=0;i<sz(arr);i++){
            memset(need,0,sizeof need);
            for(int j=0;j<sz(arr[i]);j++)need[arr[i][j]-'A']++;
            while(good()){
                ans+=(char('0'+cur[i]));
                for(int j=0;j<26;j++)frq[j]-=need[j];
                if(count(frq,frq+26,0)==26)break;
            }
        }
        sort(all(ans));
        printf("Case #%d: ",C);
        cout<<ans<<endl;
    }
}
