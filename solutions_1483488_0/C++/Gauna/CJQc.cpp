
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

int res[3000000];
int ma [3000000];
int toint(string &a){
    int acu = 1;
    int res = 0;
    dforn(i,a.size()){
        res+= acu * (a[i]-'0');
        acu*=10;
    }
    return res;
}
int tran(string &a, int j){
    /*string res = a.substr(j);
    forn(i,j) res+= a[i];
   // cout<<res<< " " << a << " " <<j <<endl;
    return toint(res);
    */
    int res = 0;
    int acu = 1;
    dforn(i,a.size()){
        res+= acu * (a[(j+i) %a.size()]-'0');
        acu*=10;
    }
    return res;

}
void modificar(int a){
    string num = "";
    while(a>0){
        num = (char)('0' + (a%10)) + num;
        a/= 10;
    }

    map<int, bool> use;
    forn(i,num.size()){
        int aux = tran(num,i);
        if(use[aux] == false and aux < 2000001){
          //  cout<< aux <<endl;
            ma[aux] ++;
            use[aux] = true;
        }
    }
}
int main(){
    #ifdef ACMTUYO
        freopen("in.in","r", stdin);
    #endif



    int t; cin>>t;
    forn(tt,t){
        int a = 1000000,b =  2000000; cin>>a>>b;
        forsn(i,a-1,b+2){ res[i] = 0; ma[i] = 0; }
        forsn(i,a,b+2){
           // if (i %10000 == 0) cout<<i<<endl;
           // cout<< i << " "<<ma[i]<<endl;
         //   if (i == 0 ) continue;
            res[i] = ma[i]+ res[i-1];
            modificar(i);
        }
        cout<<caso(tt+1, res[b]);
    }
}
