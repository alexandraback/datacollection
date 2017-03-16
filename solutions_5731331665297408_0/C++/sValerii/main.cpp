/* 
 * File:   main.cpp
 * Author: sValerii
 *
 * Created on May 3, 2014, 7:50 PM
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define forr(i,a,b) for (int i=a; i<=b; i++)
#define ford(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define sqr(q) q*q
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;

string answer = "";
string a[60];
PII w[2700];

string myGets(){
    string st= "";
    char s = ' ';
    while (s != '\n') {
        if (s != ' ') st+=s;
        scanf("%c",&s);
    }
    return st;
}

int n,m;

int isExistWay(int u, int v) {
    rep(i,m){
        if (w[i].X-1 == u && w[i].Y-1==v) return true;
        if (w[i].X-1 == v && w[i].Y-1==u) return true;
    }
    //printf("No way between %d and  %d\n",u,v);
    return false;
    
}

int p[60];
int pr[60];

void hid(string ans, int ind) {
   // printf("%s %d\n",ans.c_str(), ind);
    if ( ind == n) {
//printf("%s\n", ans.c_str());
        if (answer == "") answer = ans;
        if (ans < answer) answer = ans;
        return ;
    }

    int can[60] = {0};
    rep(i,n) can[i] = 1;
    rep(i,ind) can[ p[i] ] = 0;
    int now = p[ind-1];
    rep(i,n) 
        if ( can[i] == 1) {
            now = p[ind-1];
            //printf("now: %d\n",now);
            while (now!=-1 && !isExistWay(now,i) ) now = pr[now];
            if (now != -1) {
                p[ind] = i;
                pr[i] = now;
                hid(ans+a[i],ind+1);
            } else {
 //printf("can't get to %d \n",i);
}
        }
}
int main(int argc, char** argv) {
    freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
    int tnum;
    scanf("%d",&tnum);
    rep(tc,tnum) {
        printf("Case #%d: ",tc+1);
        answer = "";
        scanf("%d %d\n",&n,&m);
        rep(i,n) {
            char ch;
            a[i]="";
            rep(j,5){ scanf("%c",&ch); a[i]+=ch;} scanf("\n");
        }
        rep(i,m) scanf("%d %d",&w[i].X,&w[i].Y);
        rep(i,n) {  
            pr[i] = -1;
            p[0] = i;
            hid(a[i],1);
        }
        printf("%s\n",answer.c_str());
    }
    return 0;
}


