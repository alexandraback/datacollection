#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
#define FORN(i_, n_) for(int i_ = 0; i_ < (n_); ++i_)
char mapping[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main (int argc, char** argv)
{
    istream* is = &cin;
    ostream* os = &cout;

    if (argc >= 2) is = new ifstream(argv[1]);
    if (argc == 3) os = new ofstream(argv[2]);
    
    int n;
    *is >> n;
    string s;
    getline(*is,s);
    FORN(i,n){
        getline(*is,s);
        FORN(j,s.size()){
            s[j] = ((s[j] == ' ') ? s[j] : mapping[s[j]-'a']);
        }
        *os << "Case #" << i+1 <<": " << s << endl;
    }
    if (is != &cin) delete is;
    os->flush();
    if (os != &cout) delete os;
    return 0;
}

