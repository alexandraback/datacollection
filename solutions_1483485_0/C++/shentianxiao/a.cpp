#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

typedef long long LL;
typedef vector< string > VS;
typedef vector< int > VI;
typedef pair< int, int > PRII;
typedef pair< double, double > PRDD;

#define p_b push_back
#define m_p make_pair
#define x first
#define y second

#define Size(a) ((int)a.size())
#define sqr(x) ((x)*(x))

#define oo 1000000000
#define eps 1e-9
const double pi = acos(-1.0);

#define maxl 200 + 10

map< char, char > hash;
char s[maxl];

void pre( string s1, string s2 )
{
    for( int i = 0 ; i < Size(s1) ; ++i )
        hash[s1[i]] = s2[i];
}

int main()
{
    int T,Test,i,l;
    
    pre("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
    pre("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
    pre("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up");
    
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    
    hash['q'] = 'z';
    hash['z'] = 'q';
            
    scanf("%d ",&Test);
    for( T = 1 ; T <= Test ; ++T )
        {
            gets(s);
            l = strlen(s);
            printf("Case #%d: ",T);
            for( i = 0 ; i < l ; ++i )
                printf("%c",hash[s[i]]);
            printf("\n");
        }
    
    return 0;
}
