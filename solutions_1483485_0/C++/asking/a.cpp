#include <iostream>
#include <stdio.h>
#include <cstring> //for strlen, memcpy and memset.
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i(a), _n(b); i<=_n; i++)
#define FORD(i,a,b) for(int i(a), _n(b); i>=_n; i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define PR(c,x) ((c).find(x) != (c).end()) 
#define CP(c,x) (find(all(c),x) != (c).end()) 
#define SZ(a) int((a).size())a
#define X first
#define Y second
#define pb push_back
#define MEMST(a,i) memset(a,i,sizeof(a))
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> PII; 
//#define ONLINE_JUDGE

const int MXN = 100 + 10;
char str[MXN];
char dict[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    
    #ifndef ONLINE_JUDGE 
    freopen("A-small-attempt1.in","r",stdin); 
    freopen("aout.txt","w",stdout); 
    #endif

    int case_n;
    
    scanf("%d ", &case_n);    
    FOR(case_i, 1, case_n)
    {
		scanf("%100[^\n] ", &str); 
		FOR(i, 0, strlen(str)-1)
		{
			int tmp = str[i] - 'a';
			if(tmp >= 0 && tmp <=25)
			{
				str[i] = dict[tmp];
			}
		}
		
        printf("Case #%d: %s\n", case_i, str);
    }

    #ifndef ONLINE_JUDGE 
    fclose(stdin); 
    fclose(stdout); 
    #endif
    
    return 0;
}
