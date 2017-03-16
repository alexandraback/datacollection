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
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
double A[1005],B[1005];
int n;
int dec()
{
    vector<double> P,Q,_P,_Q;
    FOR(i,n)
    {
        P.pb(A[i]);
        Q.pb(B[i]);
    }
    int ans = 0;
    FOR(z,n)
    {
        int m = P.size();
       /* cout << "DEC ";
        FOR(i,m)
        cout << P[i] << " ";
        cout << endl;
        cout << "DEC ";
        FOR(i,m)
        cout << Q[i] << " ";
        cout << endl;*/
        int flag = 0;
        FOR(i,m)
        {
            if(P[i] < Q[i])
            {
                P[i] = Q[m-1] = -1;
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            ans += m;
            break;
        }
        /*if(P[0] > Q[0])
        {
            P[0] = Q[0] = -1;
            ans++;
        }
        else
        {
            P[0] = -1;
            Q[m-1] = -1;
        }*/
        _P = P;
        _Q = Q;
        P.clear();Q.clear();
        FOR(i,m)
        {
            if(_P[i] != -1)
                P.pb(_P[i]);
            if(_Q[i] != -1)
                Q.pb(_Q[i]);
        }
    }
    return ans;
}
int war()
{
    vector<double> P,Q,_P,_Q;
    FOR(i,n)
    {
        P.pb(A[i]);
        Q.pb(B[i]);
    }
    int ans = 0;
    FOR(z,n)
    {

        int m = P.size();
       // cout << "WAR " << P[m-1] << " " << Q[m-1] << endl;
        if(P[m-1] > Q[m-1])
        {
            P[m-1] = Q[0] = -1;
            ans++;
        }
        else
        {

            for(int i=0;i<m;i++)
            {
                if(Q[i] > P[0])
                {
                    Q[i] = -1;
                    break;
                }
            }
            P[0] = -1;
           // Q[m-1] = -1;
        }
        _P = P;
        _Q = Q;
        P.clear();Q.clear();
        FOR(i,m)
        {
            if(_P[i] != -1)
                P.pb(_P[i]);
            if(_Q[i] != -1)
                Q.pb(_Q[i]);
        }
    }
    return ans;
}
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(z,t)
    {
        scanf("%d",&n);
        FOR(i,n)
        scanf("%lf",&A[i]);
        FOR(i,n)
        scanf("%lf",&B[i]);
        sort(A,A+n);
        sort(B,B+n);
        printf("Case #%d: %d %d\n",z+1,dec(),war());
    }
return 0;
}
