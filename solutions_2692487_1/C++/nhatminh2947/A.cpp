//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
// Verdict: 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1000000

ll A;
int n;
int a[maxN+5];

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    #endif*/
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        printf("Case #%d: ",t);
        read2(A,n);
        
        rep(i,n) read(a[i]);
        
        sort(a,a+n);
        
        int ans = 0;
        //rep(i,n)
        //    cout << a[i] << " ";
        //printf("\n");
        //cout << "A ne " << A << endl;
        if(A == 1)
        {
            cout << n << endl;
            continue;
        }
        
        rep(i,n)
        {
            if(A > a[n-1]) break;
            
            int k = 0;
            while(A <= a[i])
            {
                k++;
                A += A-1;
            }
                    
            A += a[i];
            
            if(n-i < k)
            {
                ans += n-i;
                break;
            }
            ans += k;
            //DEBUG(A);
        }
        
        cout << min(n,ans) << endl;
    }

    return 0;
}