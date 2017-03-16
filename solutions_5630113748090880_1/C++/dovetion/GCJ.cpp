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

int t,n=0,x,cnt[3333],kase=1;
set<int> ans;

int main(){
    freopen("/Users/gexin/Downloads/B-small-attempt0.in-3.txt", "r", stdin);
    freopen("/Users/gexin/Desktop/out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        mst(cnt,0);
        for(int i=0;i<2*n*n-n;i++){
            cin>>x;
            cnt[x]++;
        }
        for(int i=0;i<2500;i++)
            if(cnt[i]%2)
                ans.insert(i);
        cout<<"Case #"<<kase++<<":";
        for(auto i:ans) cout<<" "<<i;
        ans.clear();
        cout<<endl;
    }
    
    return 0;
}