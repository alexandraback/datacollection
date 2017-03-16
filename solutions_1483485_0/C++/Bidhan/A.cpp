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
st in="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvzq";
st ou="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upqz";
int main(){
    /*set<char> ase;
    rep(i,26){
        int f=0;
        rep(j,sz(in)) if(char(i+'a')==in[j]) { f=1; cout<<char(i+'a')<<"="<<ou[j]<<endl; ase.insert(ou[j]); break; }
        if(!f) cout<<"NOT FOUND!"<<endl;
    }
    cout<<sz(ase)<<endl;
    rep(i,26){
        if(ase.find(char(i+'a'))==ase.end()){ cout<<"---->"<<char(i+'a')<<endl; break; }
    }*/
	read("in.txt");
	rite("out.txt");
	char inp[550];
	int test,kas=0;
	cin>>test;
	getchar();
	while(test--){
	    gets(inp);
	    printf("Case #%d: ",++kas);
	    for(int i=0; inp[i]; i++) rep(j,sz(in)) if(inp[i]==in[j]) { printf("%c",ou[j]); break; }
	    printf("\n");
	}
    double cl = clock();
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
