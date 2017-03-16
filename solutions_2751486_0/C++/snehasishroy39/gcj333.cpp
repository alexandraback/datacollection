#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define frl(a, b, c) for( a = b; a < c; a++)
#define fru(a, b, c) for( a = b; a <= c; a++)
#define frd(a, b, c) for( a = b; a >= c; a--)
#define mst(a, b) memset(a, b, sizeof(a))
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sc(a) scanf("%c", &a)
#define pb(a) push_back(a)
#define mp make_pair

#define ssz(s) s.size()
#define bg(v) v.begin()
#define ed(v) v.end()

typedef pair<int, int> pair_int_int;
typedef pair<string, int> pair_string_int;
typedef pair<int, string> pair_int_string;
typedef pair<string, string> pair_string_string;

typedef set<int> set_int;
typedef set<string> set_str;

typedef vector<int> vector_int;
typedef vector<string> vector_string;
typedef vector<pair_int_int> vector_pair_int_int;
typedef vector<pair_string_string> vector_pair_string_string;

int main ()
{
    int testss;

    cin >> testss;
    int clourss = 0;
    while ( testss-- )
    {
        int uppperr = 0;
        string input_string;
        cin >> input_string;
        int length_of_string = (int)input_string.size();
        int var;
        cin >> var;
        for ( int lm = 0; lm < length_of_string; lm++ )
        {
            for ( int jp = lm + var; jp <= length_of_string; jp++ )
            {
                int counttt = 0;
                for ( int klm = lm; klm < jp; klm++ )
                {
                    if(input_string[klm]=='a' || input_string[klm]=='e' || input_string[klm]=='i'|| input_string[klm]=='o' || input_string[klm]=='u')
                        counttt = 0;
                    else
                        counttt += 1;
                    if ( counttt >= var )
                    {
                        uppperr += 1;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ++clourss, uppperr );
    }
}
