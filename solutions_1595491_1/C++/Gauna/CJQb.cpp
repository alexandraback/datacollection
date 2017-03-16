
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
bool vale(int a, int b){
    a -= b;
    a -= max(0,(b-1));
    a -= max(0,(b-1));
    return a>= 0;
}
bool vale2(int a, int b){
    a -= b;
    a -= max(0,(b-2));
    a -= max(0,(b-2));
    return a>= 0;
}


int main(){
    #ifdef ACMTUYO
        freopen("in.in","r", stdin);
    #endif
    int t; cin>>t;
    forn(tt,t){
        int res = 0;

        int n, s, p; cin>>n>>s>>p;
        vector<int> vec(n);
        forn(i,n) cin>>vec[i];
        forn(i,n){
            if (vale(vec[i], p)){
                res++;
            }else{
                if (s != 0 and vale2(vec[i],p)){
                    res++; s--;
                }
            }
        }

        cout<<caso(tt+1, res);
    }
}
