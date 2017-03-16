#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

#define VS vector<string>
#define VI vector<int>
#define VVI vector< VI >
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORC(it,kont) for(__typeof((kont).begin()) it = (kont).begin(); it!=(kont).end(); ++it)

char buff[20000];

long long R,M,N,K;

int main()
    {
    int T;
    gets(buff);
    sscanf(buff,"%d",&T);

    FOR( t, 0, T )
        {
        string s;        
        cin >> R>> N>> M>> K;
        //cout << R << N << M << K;
        printf("Case #%d:\n",t+1);
        FOR(i,0,R)
            {
            s = "";
            vector<long long> x(K);
            FOR( j,0, K)
                cin >> x[j];
            //FOR( j,0, K)
            //    cout <<  x[i];
            
            int a[200]={0};
            int bla = 0;
            FOR( j, 0, K )
                if( (x[i] - 2)%4 == 0 )
                    ++bla;
            FOR(l,2,200)
                {
                FOR( j,0,K)
                    if( x[j] % l == 0 ) ++a[l];
                }
            if( a[125] > 0 )
                {
                s += "555";
                }
            else if( a[25] > 0 )
                {
                s += "55";
                }
            else if ( a[5] > 0 )
                {
                s += "5";
                }
            if( a[27] > 0 )
                {
                s += "333";
                }
            else if ( a[9] > 0 )
                {
                s += "33";
                }
            else if (a[3] > 0 )
                {
                s += "3";
                }
            int bl4 = 0, bl2 = 0;
            if( a[16] > 0 )
                { s += "4"; bl4 = 1; }
            if( bla > 0 )
                { s += "2"; bl2 = 1; }
            //cout << bla << " " << a[4] << endl;
            if( s.size() > 3 ) 
                s = s.substr(0,3);
            while( s.size() < 3 )
                {
                if( a[4] > 0 && bla == 0 ) s += "4";
                else s+= "2";
                }
            cout << s << endl;
            }
        }
    return 0;
    }
