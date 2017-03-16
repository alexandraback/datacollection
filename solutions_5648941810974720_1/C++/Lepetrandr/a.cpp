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
	//freopen("a.in","r",stdin);
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
}

int f(string w, std::map<char, int>& m)
{
    int res = 0;
    while (true) {
        bool stop = false;
        FA(i, w) {
            m[w[i]]--;
            if (m[w[i]] < 0) stop = true;
        }
        if (stop) {
            FA(i, w) {
                m[w[i]]++;
            }
            break;
        }
        ++res;
    }
    return res;
}

std::string sol(string s){
    std::map<char, int> m;
    FA(i, s) {
        m[s[i]]++;
    }
    std::vector<int> res(10, 0);
    res[0] = f("ZERO",m);
    res[2] = f("TWO",m);
    res[4] = f("FOUR",m);
    res[6] = f("SIX",m);
    res[8] = f("EIGHT",m);
    res[1] = f("ONE",m);
    res[3] = f("THREE",m);
    res[5] = f("FIVE",m);
    res[7] = f("SEVEN",m);
    res[9] = f("NINE",m);
    std::string result;
    FOR(i,0,9) {
        result += string(res[i], '0' + i);
    }
    return result;
}

int main()
{
	init();
    int T; 
    cin >> T;
    string s;
    FOR(t,1,T) {
        cin >> s;
        cout << "Case #" << t << ": " << sol(s) << std::endl;
    }
	return 0;
}