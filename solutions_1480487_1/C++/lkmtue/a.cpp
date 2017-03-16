#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define maxn 1111
using namespace std;

int n;
double sum,s[maxn];


bool exceed(int v,double p) {
    double x=0;
    FOR(i,1,n) x+=max(s[v]+sum*p-s[i],(double)0)/sum;
    return x>1;
}

int main() {
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    int numt;
    cin >> numt;
    FOR(_,1,numt) {
        cin >> n;
        FOR(i,1,n) cin >> s[i];
        sum=0;
        FOR(i,1,n) sum+=s[i];
        
        cout << "Case #" << _ << ": ";
        FOR(i,1,n) {
            double low=0,high=1;
            FOR(z,1,10000) {
                double mid=(low+high)/2;
                if (exceed(i,mid)) high=mid;
                else low=mid;
            }
            printf("%.8lf ",high*100);
        }
        cout << endl;
        cerr << _<<endl;
    }
}
