#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
//#include <memory.h>  POJ problem
#include <functional>
#define x first
#define y second
#define pb push_back
#define forn(i,n) for(int i=0;i<n;i++)
#define mst(a,i) memset(a,i,sizeof(a))
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef long double ld;
typedef std::pair<int,int> pii;
const double pi=acos(-1.0);
const ll MAXN = 123;
using namespace std;

int t,cnt=1,fi=2500,se=2500;
string s,k;
char ans[5000];

int main(){
    freopen("/Users/gexin/Downloads/A-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/gexin/Desktop/out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>s;
        ans[fi]=s[0];
        for(int i=1;i<s.length();i++)
            if(s[i]>=ans[fi]){
                ans[--fi]=s[i];
            }
            else
                ans[++se]=s[i];
        for(int i=fi;i<=se;i++) k.append(1,ans[i]);
        fi=2500,se=2500;
        cout<<"Case #"<<cnt++<<": "<<k<<endl;
        k.clear();
    }
    
    return 0;
}