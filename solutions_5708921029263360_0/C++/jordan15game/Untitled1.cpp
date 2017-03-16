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
int a,b,c,d;

vector<vector<int> >  fun(int a,int b,int c,int pa,int pb,int pc){
    bool vis[11][11][11]={0};
    vector<vector<int> > p;
    int ab[11][11]={0},ac[11][11]={0},bc[11][11]={0};
    for(int i=1;i<=min(a,d);i++){
        int k=1;
        for(int j=1;j<=b;j++){
            for(int l=0;l<min(c,d);l++){
                vector<int> tmp(3,0);
                tmp[pa]=i;
                tmp[pb]=j;
                tmp[pc]=k;
                vis[i][j][k]=1;
                ab[i][j]++;
                ac[i][k]++;
                bc[j][k]++;
                if(ab[i][j]<=d&&ac[i][k]<=d&&bc[j][k]<=d)p.push_back(tmp);
                k++;
                if(k>c)k-=c;

            }
        }
    }
//    printf(" %d\n",p.size());
//    for(int i=0;i<p.size();i++){
//        for(int j=0;j<p[i].size();j++){
//            if(j)putchar(' ');
//            printf("%d",p[i][j]);
//        }
//        puts("");
//    }
    return p;
}


vector<vector<int> > func(int a,int b,int c,int pa,int pb,int pc){
    bool vis[11][11][11]={0};
    int ab[11][11]={0},ac[11][11]={0},bc[11][11]={0};
    vector<vector<int> > p;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++)if(ab[i][j]<d){
            for(int k=1;k<=c;k++)if(ac[i][k]<d&&bc[j][k]<d){
                vector<int> tmp(3,0);
                tmp[pa]=i;
                tmp[pb]=j;
                tmp[pc]=k;
                ab[i][j]++;
                ac[i][k]++;
                bc[j][k]++;
                p.push_back(tmp);
                if(ab[i][j]>=d)break;
            }
        }
    }
    return p;
}

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
//        scanf("%d%d%d%d",&a,&b,&c,&d);
        int a[3];
        scanf("%d%d%d%d",a,a+1,a+2,&d);
        printf("Case #%d:",ti++);
//        if(c>=a&&c>=b){
//            if(b>=d)fun(a,c,b,0,2,1);
//            else if(a>=d) fun(b,c,a,1,2,0);
//            else{
//                if(a<b)fun(a,b,c,0,1,2);
//                else fun(b,a,c,1,0,2);
//            }
//        }
//        else if(b>=a&&b>=c){
//            if(c>=d)fun(a,b,c,0,1,2);
//            else if(a>=d)fun(c,b,a,0,1,2);
//            else{
//                if(a<c)fun(a,c,b,0,2,1);
//                else fun(c,a,b,2,0,1);
//            }
//
//        }
//        else if(a>=b&&a>=c){
//            if(c>=d)fun(b,a,c,1,0,2);
//            else if(b>=d)fun(c,a,b,2,0,1);
//            else{
//                if(b<c)fun(b,c,a,1,2,0);
//                else fun(c,b,a,2,1,0);
//            }
//
//        }
        vector<vector<int> >ans;
        int b[]={0,1,2};
        do{
            vector<vector<int> >tmp=fun(a[b[0]],a[b[1]],a[b[2]],b[0],b[1],b[2]);
            if(tmp.size()>ans.size())ans=tmp;
        }while(next_permutation(b,b+3));
        printf(" %d\n",ans.size());
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                if(j)putchar(' ');
                printf("%d",ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}




