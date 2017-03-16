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
#include <fstream>

#define sz(X) ((int)X.size())
#define FOR(i,x,y) for(int i=x; i<y; ++i)
#define FORE(i,x,y) for(int i=x; i<=y; ++i)
#define FORD(i,x,y) for(int i=x; i>y; --i)
#define FORDE(i,x,y) for(int i=x; i>=y; --i)
#define ALL(x) x.begin(), x.end()

#define INT_MAXIMUM 100000007
#define isPowerOfTwo(S) (!(S & (S - 1)))


using namespace std;

string trim(string S)
{
    int N = sz(S);
    string ans = "";
    FOR(i,0,N)
    {
        char c = S[i];
        ans.push_back(c);
        while (i < N && S[i] == c)i++;
        i--;
    }

    return ans;

}
bool test(string S)
{
    vector<int> A(26,0);

    int N = sz(S);
    FOR(i,0,N) A[S[i]-'a'] = 1;

    int K = 0;
    FOR(i,0,26) K += A[i];

    FOR(i,0,N)
    {
        if(A[S[i]-'a'] == 0) return false;
        else
        {
            A[S[i]-'a'] = 0;
            char c = S[i];
            while (i < N && S[i] == c)i++;
            i--;
        }
    }

    return true;

}
int main()
{
    ofstream cout ("output.txt");
    ifstream cin ("input.txt");

    int T;
    cin>>T;

    FOR(i,1,T+1)
    {
        int N; cin>>N;
        vector<string> trains(N);

        string s;
        FOR(n,0,N) {cin>>s; s = trim(s); trains[n] = s;}

        vector<int> P(N);
        FOR(i,0,N) P[i] = i+1;

        int ans = 0;

        do
        {
            string S = "";
            FOR(i,0,N)
                S += trains[P[i]-1];


            if(test(S))
            { 
                ++ans;
            }

        } while (next_permutation(P.begin(), P.end()));

        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    
    return 0;
}