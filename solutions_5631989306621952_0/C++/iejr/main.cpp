//iejr Header files
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <ctime>
#include <cctype>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

//iejr: Type defination
typedef unsigned long long int             ULLN;
typedef long long int                      LLN;
typedef vector<int>                        VI;
typedef vector<vector<int> >               VVI;
typedef vector<string>                     VS;
typedef vector<vector<string> >            VVS;


//iejr: Compile Options
//#define C11_Standard
//
#ifdef C11_Standard
    #include <unordered_set>
    #include <unordered_map>

    #define HASHSET                  unordered_set
    #define HASHMAP                  unordered_map;
#endif // C11_Standard


//iejr: Local Debug
#define INPUT_REDIRECTION
#define OUTPUT_REDIRECTION


//iejr: Main Function
int main()
{

#ifdef INPUT_REDIRECTION
    freopen( "A-small-attempt1.in", "r", stdin );
#endif // INPUT_REDIRECTION

#ifdef OUTPUT_REDIRECTION
    freopen( "out.txt", "w", stdout );
#endif // OUTPUT_REDIRECTION

    int T = 0;
    scanf( "%d", &T );
    for( int i = 0;i < T;++i ){
        char cBuff[1007];
        memset( cBuff, 0, 1007 );
        scanf( "%s", cBuff );
        string str = "";
        int L = strlen( cBuff );

        for( int i = 0;i < L;++i ){
            if( str == "" ){
                str +=  cBuff[i] ;
            }
            else{
                if( cBuff[i] >= str[0] ){
                //    string sTemp( cBuff[i] );
                    char cstr[2] = {0};
                    cstr[0] = cBuff[i];
                    string sTemp( cstr );
                    str = sTemp + str;
                }
                else{
                    str += cBuff[i] ;
                }
            }
        }

        cout<<"Case #"<<i +1<<": "<<str<<endl;
    }

#ifdef INPUT_REDIRECTION
    fclose( stdin );
#endif // INPUT_REDIRECTION

#ifdef OUTPUT_REDIRECTION
    fclose( stdout );
#endif // OUTPUT_REDIRECTION

    return 0;
}
