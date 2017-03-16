#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <ctime>
#include <memory.h>

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,Be,En) for(int (i)=(Be);(i)<=(En);++(i))
#define DFOR(i,Be,En) for(int (i)=(Be);(i)>=(En);--(i))
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a,0,sizeof(a))

#define LL  long long
#define VI  vector<int>
#define PAR pair<int ,int> 

using namespace std;
void __never(int a){printf("\nOPS %d", a);}
void __die(int a){printf("%d",(a*a)/(a+a));}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();__die(0);}}


void init()
{
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
}

int sol(std::string s){
    int friends = 0;
    int current_stand = 0;
    FA(i, s) {
        if (current_stand >= i) {
            current_stand += (s[i] - '0');
        } else {
            friends += i - current_stand;
            current_stand = i + (s[i] - '0');
        }
    }
    return friends;
}
int main()
{
	init();
    int T;
    cin >> T;
    int sz;
    string s;
    FOR(t,1,T) {
        cin >> sz >> s;
        ass(SZ(s) == sz + 1);
        cout << "Case #" << t << ": " << sol(s) << std::endl;
    }
	return 0;
}