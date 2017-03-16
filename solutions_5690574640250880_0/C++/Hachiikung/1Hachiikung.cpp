/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
#include<utility>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define mp make_pair
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(55);

string a[MAXN];

int r,c;

void init(){
    REP(i,r)
    {
        a[i] = "";
        REP(j,c)
            a[i] += '*';
    }
}

void PR(){
    REP(i,r)
        cout << a[i] << endl;
}

void solve(int test){

    int m;
    S("%d%d%d",&r,&c,&m);

    init();

    int num = r * c - m;

    P("Case #%d:\n",test);

    if(num == 1)
    {
        a[0][0] = 'c';
        PR();
    }

    else if(r == 1)
    {
        REP(j,num)
            a[0][j] = '.';
        a[0][0] = 'c';
        PR();
    }

    else if(c == 1)
    {
        REP(i,num)
            a[i][0] = '.';
        a[0][0] = 'c';
        PR();
    }

    else if(r == 2 || c == 2)
    {
        if(num % 2 == 1 || num < 4) P("Impossible\n");

        else
        {
            if(r == 2)
            {
                REP(j,num/2)
                    a[0][j] = a[1][j] = '.';
                a[0][0] = 'c';
                PR();
            }
            else
            {
                REP(i,num/2)
                    a[i][0] = a[i][1] = '.';
                a[0][0] = 'c';
                PR();
            }
        }
    }

    else if(num == 2 || num == 3 || num == 5 || num == 7)
    {
        P("Impossible\n");
    }

    else if(num < 2 * c)
    {
        if(num % 2 == 1)
        {
            REP(i,3)
                REP(j,3)
                    a[i][j] = '.';

            num -= 9;

            FOR(j,3,c-1)
            {
                if(num == 0) break;
                a[0][j] = '.';
                a[1][j] = '.';
            }

            a[0][0] = 'c';

            PR();
        }

        else
        {
            REP(j,num/2)
            {
                a[0][j] = '.';
                a[1][j] = '.';
            }

            a[0][0] = 'c';

            PR();
        }
    }

    else
    {
        int t = num / c;

        REP(i,t)
            REP(j,c)
                a[i][j] = '.';

        if(num % c == 1)
        {
            if(t == 2)
            {
                a[t-2][c-1] = '*';
                a[t-1][c-1] = '*';
                a[t][0] = '.';
                a[t][1] = '.';
                a[t][2] = '.';
            }

            else
            {
                a[t-1][c-1] = '*';
                a[t][0] = '.';
                a[t][1] = '.';
            }
        }

        else
        {
            REP(j,num%c)
                a[t][j] = '.';
        }

        a[0][0] = 'c';

        PR();
    }

}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
        solve(i);

}

