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
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 0
double p[100005];
int a,b;
int main(){
	read("ain.txt");
	rite("aout.txt");
    double cl = clock();
    cl = clock() - cl;
    int test,kas=0;//,a,b;
    cin>>test;
    while(test--){
        cin>>a>>b;
        double thik=1.0;
        rep(i,a) scanf("%lf",&p[i]), thik*=p[i];
        double vul=1.0-thik;
        double kt=0,ent=0;
        kt=(b-a+1)*thik+(b-a+1+b+1)*vul;
        if(b==a) ent=1*thik+(b+2)*vul;
        else ent=(b+2);
        double ans=1e12;
        ans=min(kt,ent);
        a--;
        double tt=0;
        int kkk=0;
        while(a>0){
            kkk++;
            thik/=p[a];
            vul=1.00-thik;
            tt=(b-a+1+kkk)*thik+(b-a+1+b+1+kkk)*vul;
            ans=min(ans,tt);
            a--;
        }
        //cout<<kt<<" "<<ent<<endl;
        printf("Case #%d: %.6lf\n",++kas,ans+eps);
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
