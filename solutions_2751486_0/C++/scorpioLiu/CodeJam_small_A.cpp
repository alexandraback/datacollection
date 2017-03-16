#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

//BEGINTEMPLATE_BY_SCORPIOLIU
const double PI  = acos(-1.0);
const double EPS = 1e-11;
const double INF  = 1E200;

typedef long long int64;
typedef unsigned long long uint64;

typedef pair<int,int> ipair;
#define MP(X,Y) make_pair(X,Y)
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

#define REP(i,a) for(int i=0;i<int(a);++i)
#define REP2(i,n,m) for(int i=n;i<(int)(m);++i)
#define FORE(it,a) for (typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define ALL(a) (a).begin(),(a).end()
//ENDEMPLATE_BY_SCORPIOLIU

#define SMALL
//#define LARGE

int main()
{
#ifdef SMALL
    //ifstream fin("A-small-practice.in");ofstream fout("A-small-practice.out");
    //ifstream fin("A-small-attempt0.in");ofstream fout("A-small-attempt0.out");
    freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
#endif
#ifdef LARGE
    //ifstream fin("A-large-practice.in");ofstream fout("A-large-practice.out");
    //ifstream fin("A-large.in");ofstream fout("A-large.out");
    freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
#endif
    int Z;
    cin>>Z;
    REP(z,Z)
    {

        cout<<"Case #"<<z+1<<": ";
        //////////////////////////////////////
        string s;
        int n;
        cin>>s>>n;
        int res = 0;
        int k = 0;
        int hit = 0;
        bool flag = false;
        for (int i = 0; i != s.length() - n + 1; i++) {
            flag = true;
            for (int j = i; j < i + n; j++){
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (hit == 0) {
                    res = (s.length() - i - n + 1 ) *(i + 1);
                } else {
                    res = res + (i -k ) * (s.length() - i - n + 1);
                }
                hit ++;
                k = i;

            }
        }
        cout<<res;
        //////////////////////////////////////
        cout<<endl;
    }
    return 0;
}
