#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include "fstream"

#define sz(X) ((int)X.size())
#define FOR(i,x,y) for(int i=x; i<y; ++i)

char buf[50]; std::string itos(int x) {sprintf(buf,"%d",x); return buf;}

using namespace std;

map<long long, long long> D;
bool canFlip(long long N)
{
    return N%10;
}
long long flip(long long N)
{
    string sN = itos(N);
    reverse(sN.begin(), sN.end());

    return atoll(sN.c_str());

    long long fN = 0;
    int k = 1;
    while(N)
    {
        fN += (N%10) * k;
        k *= 10;
        N /= 10;
    }

    return fN;
}

void solve(long long N, long long S)
{
    if(D[N] > 0 && D[N] >= S) return;
    if(N == 1) { D[1] = S + 1; return; }
    if(D[N] > 0) D[N] = S;
    else
    {
        D[N] = S;
        long long fN = flip(N);
        if(canFlip(N) && fN < N) solve(fN, S + 1);
        solve(N-1, S+1);
    }

}
int main()
{
//    ofstream cout ("output.txt");
    ifstream cin ("input.txt");

//    cout << flip(234);
    int T;
    cin>>T;

    FOR(i,1,T+1)
    {
        long long N;
        cin>>N;

        D.clear();


        solve(N, 0);

        cout<<"Case #"<<i<<": "<<D[1]<<endl;
    }

    return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
