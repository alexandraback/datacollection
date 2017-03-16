
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<list>
#include<cmath>
#include <string.h>
#include<set>
#include<queue>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);i++)
#define forsn(i,s,n) for(int i = (int)s; i< (int)(n);i++)
#define dforn(i,n) for(int i=(int)(n-1);i>=0;i--)
#define dforsn(i,s,n) for(int i = (int)(n-1); i>= (int)(s);i--)
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define esta(a,c) (find(c.begin(),c.end(), a) != c.end())
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define MAX_int 2147483647
#define caso(x,y) "Case #"<<x<<": " <<y<<endl
#define PI 3.141592653589793238462643383279
#define MOD 1000000007
#define MODL 1000000007LL


int main(){
    #ifdef ACMTUYO
    //    freopen("in.in","r", stdin);
    #endif
    vector<string> a,b;
    a.pb("zqejp mysljylc kd kxveddknmc re jsicpdrysi");
    a.pb("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    a.pb("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    b.pb( "qzour language is impossible to understand");
    b.pb("there are twenty six factorial possibilities");
    b.pb("so it is okay if you want to just give up");

    int t ; cin>>t;
    string res;
    getline(cin, res);
    forn(tt,t){
        getline(cin, res);
       // cout<<res<<endl;
        forn(i,res.size()){
            bool entro = false;
            forn(j,3){
                forn(k, a[j].size()){
                    if (!entro and res[i] == a[j][k]){
                        res[i] = b[j][k];
                        entro = true;
                    }
                }
            }
            if (!entro){
                res[i] = 'z';
            }
        }

        cout<<caso(tt+1, res);

    }
}
