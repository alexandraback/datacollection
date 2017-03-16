#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

#define FOR(i,a,b) for(int i = (a),_n=(b);i<=_n;i++)
#define REP(i,n) for(int i = 0,_n=(n);i<_n;i++)
#define _m(a,b) memset(a,b,sizeof(a))

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << "[" <<  y << "] = " << x[y] << endl;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

int main()
{
    int t,n;
    int step[1000];
    pair<int,int> num[1000];
    scanf("%d",&t);
    REP(_,t)
    {
        scanf("%d",&n);
        _m(step,0);
        REP(i,n) scanf("%d %d",&num[i].first,&num[i].second);

        int count = 0,gems=0, res=0;
        while (count < n)
        {
            int hit = -1;
            REP(i,n)
            {
                if (step[i] < 2 && num[i].second <= gems)
                {
                    hit = i;
                    break;
                }
            }

            if (hit != -1)
            {
         //       printf("knock 2  -> %d\n",hit);
                gems += 2-step[hit];
                step[hit]+=2;
                count++;
                res++;
        //        debug(gems);
             //   debug(count);
             //   debug(res);
             //   if (count ==n) break;
                continue;
            }

            hit = -1;
            REP(i,n)
            {
                if (step[i] < 1 && num[i].first <= gems)
                {
                    if (hit == -1 || (num[hit].second < num[i].second)) hit = i;
       //             debug(hit);
                }
            }

            if (hit != -1)
            {
         //       printf("knock 1  -> %d\n",hit);
                gems += 1-step[hit];
                step[hit]+=1;
                res++;
                continue;
            }
            else
            {
                res = -1;
                break;
            }

        }
        printf("Case #%d: ",_+1);
        if (res == -1) puts("Too Bad");
        else printf("%d\n",res);

    }
    return 0;
}
