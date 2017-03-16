#pragma comment(linker, "/STACK:65536000")
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<iostream>
#include<time.h>
#include <list>
#include <numeric>
#include <complex>
#define forn(i,n) for(int i=0;i<n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
#define lowb(i) (i&(-i))
#define bug(n,m,x) forn(i,n){forn(j,m)printf("%d ",x[i][j]);puts("");}puts("")
#define sqr(x) ((x)*(x))
using namespace std;
const int inf=1<<30;
const double eps=1e-8;
const double pi=acos(-1.0);
//const ll mod = 9223372034707292160LL;
//const double inf = 1e10;
const double E=2.718281828459;


int n,m;
int ti=1,t;
char a[1010];

int main(){
#ifdef jordan13game
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        int l=strlen(a);
        int p=l;
        string head,tail;
        while(p>0){
            char tmp=0;
            int pp=-1;
            for(int i=p-1;i>=0;i--){
                if(a[i]>tmp){
                    tmp=a[i];
                    pp=i;
                }
            }
            head+=a[pp];
            string tt(a+pp+1,a+p);
//            cout<<tt<<endl;
            tail=tt+tail;
            p=pp;
        }
        printf("Case #%d: ",ti++);
        cout<<head<<tail<<endl;
    }
    return 0;
}




