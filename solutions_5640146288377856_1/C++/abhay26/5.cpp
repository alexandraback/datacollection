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
int A[35][35];
int main()
{
	freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    //cout << "HAH" << endl;
    int t;
    scanf("%d",&t);
    int kas = 0;
    for(int i=1;i<=30;i++)
    {
        int cur = 0;
        int tmp = i+1;
        for(int j=i+1;j<=30;j++)
        {
            A[i][j] = tmp;
            cur++;
            if(cur >= i)
            {
                cur = 0;
                tmp++;
            }
        }
    }
    //cout << "LOL"<< endl;
    while(t--)
    {
    	kas++;
        printf("Case #%d: ",kas);
    	int r,c,w;
        cin >> r >> c >> w;
        if(w == c)
        {
            cout << (r-1) + w << endl;
            continue;
        }
        cout << (c/w)*(r-1) + A[w][c] << endl;
    }
return 0;
}
