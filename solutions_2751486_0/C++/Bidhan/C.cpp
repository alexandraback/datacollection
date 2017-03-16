/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define inf (1<<30)
#define eps 1e-9
#define pb push_back
#define ins insert
#define mp make_pair
#define sz(x) ((int)x.size())
#define clr clear()
#define all(x) x.begin(),x.end()
#define xx first
#define yy second
#define sqr(x) ((x)*(x))
#define mem(x,val) memset((x),(val),sizeof(x));
#define read(x) freopen(x,"r",stdin);
#define rite(x) freopen(x,"w",stdout);
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef map<int,st> mis;
typedef set<int> si;
typedef set<st> ss;
typedef pair<i64,i64> pii;
typedef vector<pii> vpii;

#define mx 200

char name[mx];

int vow(char ch){
    if(ch=='a') return 1;
    if(ch=='e') return 1;
    if(ch=='i') return 1;
    if(ch=='o') return 1;
    if(ch=='u') return 1;
    return 0;
}

int main(){
	double cl = clock();
    cl = clock() - cl;
    read("A.in");
    rite("cout.txt");
    int test,kas=0;
    cin>>test;
    while(test--){
        printf("Case #%d: ",++kas);
        int n;
        cin>>name>>n;
        int ans=0;
        for(int i=0; name[i]; i++){
            int cnt=0,v=0;
            for(int j=i; name[j]; j++){
                if(vow(name[j])) cnt=0;
                else cnt++;
                v=max(cnt,v);
                if(v>=n) ans++;
            }
        }
        cout<<ans<<endl;
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
