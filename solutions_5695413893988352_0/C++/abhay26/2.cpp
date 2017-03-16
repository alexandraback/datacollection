/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define pll pair < ll, ll >
#define pill pair< int, pll >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
int cnt[26];
inline string some_function(int n, int len)
{
    string result(len--, '0');
    for (int val=(n<0)?-n:n; len>=0&&val!=0; --len,val/=10)
       result[len]='0'+val%10;
    if (len>=0&&n<0) result[0]='-';
    return result;
}
bool match(string A, string B){
    //cout << A << " " << B << endl;
    int n = A.length();
    for(int i=0;i<n;i++)
    {
        if(A[i] != '?')
        {
            if(A[i] != B[i])
                return false;
        }
    }
    return true;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        printf("Case #%d: ", z);
        string cc,jj;
        cin >> cc >> jj;
        int len = cc.length();
        string _C = "null",_J;
        int _d = 1000000000;
        int cs = 1000000000;
        int js = 1000000000;
        int lmt = 1000;
        if(len == 1)
            lmt = 10;
        else if(len == 2)
            lmt = 100;
        for(int i=0;i<lmt;i++)
        {
            string A = some_function(i,len);


            if(!match(cc,A))
                continue;
            for(int j=0;j<lmt;j++){
                string B = some_function(j,len);
                if(!match(jj,B))
                continue;
                int diff = abs(i-j);
                if(diff < _d)
                {
                    _d = diff;
                    _C = A;
                    _J  = B;
                    cs = i;
                    js = j;
                }
                else if(diff == _d && i < cs)
                {
                    _d = diff;
                    _C = A;
                    _J  = B;
                    cs = i;
                    js = j;
                }
                else if(diff == _d && i==cs && j < js)
                {
                    _d = diff;
                    _C = A;
                    _J  = B;
                    cs = i;
                    js = j;
                }
            }
        }
        cout << _C << " " << _J << endl;
    }
    return 0;
}
