#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORE(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define inp(n) int (n); scanf("%d",&(n));
#define inp2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define inp3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
#define SSD(x) (scanf("%d",&x))
#define SSL(x) (scanf("%lld",&x))
#define SSF(x) (scanf("%f",&x))
#define SSS(x) (scanf("%s",x))
inline void prt(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS inp(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define MAX(a,b) (a)=max((a),(b));
#define MIN(a,b) (a)=min((a),(b));
#define INRAN(a,b,c) ((a)>=(b) && (a)<(c))

int main ()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w+",stdout);
    vector<string> mat(5);
    inp(t);
    FORE(test,t)
    {
        int x,o,blank=0;
        FOR(i,4)
        {
            cin>>mat[i];
        }
        FOR(i,4)
        {
            x=o=0;
            FOR(j,4)
            {
                if(mat[i][j]=='X') x++;
                if(mat[i][j]=='O') o++;
                if(mat[i][j]=='T') x++,o++;
                if(mat[i][j]=='.') blank++;
            }

            if(x==4) {printf("Case #%d: X won\n",test);goto jp;}
            else if(o==4) {printf("Case #%d: O won\n",test);goto jp;}
        }

        FOR(j,4)
        {
            x=o=0;
            FOR(i,4)
            {
                if(mat[i][j]=='X') x++;
                if(mat[i][j]=='O') o++;
                if(mat[i][j]=='T') x++,o++;
                if(mat[i][j]=='.') blank++;
            }

            if(x==4) {printf("Case #%d: X won\n",test);goto jp;}
            else if(o==4) {printf("Case #%d: O won\n",test);goto jp;}
        }

        x=o=0;
        FOR(j,4)
        {
            if(mat[j][j]=='X') x++;
            if(mat[j][j]=='O') o++;
            if(mat[j][j]=='T') x++,o++;
            if(mat[j][j]=='.') blank++;
        }

        if(x==4) {printf("Case #%d: X won\n",test);goto jp;}
        else if(o==4) {printf("Case #%d: O won\n",test);goto jp;}

         x=o=0;
        FOR(j,4)
        {
            if(mat[3-j][j]=='X') x++;
            if(mat[3-j][j]=='O') o++;
            if(mat[3-j][j]=='T') x++,o++;
            if(mat[3-j][j]=='.') blank++;
        }

        if(x==4) {printf("Case #%d: X won\n",test);goto jp;}
        else if(o==4) {printf("Case #%d: O won\n",test);goto jp;}

        if(blank!=0) {printf("Case #%d: Game has not completed\n",test);goto jp;}
        printf("Case #%d: Draw\n",test);
        jp:;

    }
    return 0;

}

