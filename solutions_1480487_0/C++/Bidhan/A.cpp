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
#define eps 1e-12
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

#define mx 250
mii ase;
int n,s[mx];
double sum,lim;
double f(double S){
    double tot=0;
    rep(i,n){
        double diff=S-double(s[i]);
        if(s[i]==0) diff/=double(ase[0]);
        tot+=(diff*100.0)/sum;
    }
    return tot-100.0;
}

int main(){
	double cl = clock();
    cl = clock() - cl;
    read("ain.txt");
    rite("aout3.txt");
    int test,kas=0;
    cin>>test;
    while(test--){
        cin>>n;
        sum=0;
        double lo=0;
        ase.clr;
        rep(i,n) cin>>s[i], sum+=s[i], ase[s[i]]++, lo=max(lo,double(s[i]));
        //lim=(100.0/n)*n;
        double hi=sum;
        int stp=500;
        //cout<<"lim ="<<lim<<endl;
        //double ans=1e18;
        while(stp--){
            double mid=(lo+hi)/2.0;
            double temp=f(mid);
            if(temp>eps) hi=mid;
            else lo=mid;
        }
        double ans=(lo+hi)/2.0;
        //cout<<ans<<endl;
        printf("Case #%d:",++kas);
        if(ans<eps){
            rep(i,n){
                printf(" ");
                printf("0.0");
            }
        }
        else rep(i,n){
            printf(" ");
            if(s[i]==0){
                double oooo=ans/double(ase[0]);
                printf("%lf",((oooo-double(s[i]))*100.0)/sum);
            }
            else printf("%lf",((ans-double(s[i]))*100.0)/sum);
        }
        cout<<endl;
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
