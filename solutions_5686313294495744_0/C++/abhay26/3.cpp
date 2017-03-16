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
string A[20], B[20];
map<string, int> MA, MB;

bool cmp (pip i,pip j)
{
    int A1 = i.second.first;
    int A2 = i.second.second;

    int B1 = j.second.first;
    int B2 = j.second.second;

    if(A1 == 1 || A2 == 1)
        return 1;
    if(B1 == 1 || B2 == 1)
        return 0;
    return min(A1,A2) > min(B1,B2);
}
bool cmp2 (pip i,pip j)
{
    int A1 = i.second.first;
    int A2 = i.second.second;

    int B1 = j.second.first;
    int B2 = j.second.second;

    return min(A1,A2) > min(B1,B2);
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        MA.clear();
        MB.clear();
        printf("Case #%d: ", z);
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> A[i] >> B[i];
            MA[A[i]]++;
            MB[B[i]]++;
        }
        vector<pip> V;
        for(int i=0;i<n;i++)
        {
            V.pb(pip(i, pii(MA[A[i]], MB[B[i]])));
        }
        sort(V.begin(),V.end(), cmp);
        /*for(int i=0;i<n;i++)
        {
            cout << V[i].second.first << " " << V[i].second.second << endl;
        }*/
        set<string> SA, SB;
        vector<pip> tmp;
        int ans = 0;
        int pos = 0;
        for(int i=0;i<V.size();i++)
        {
            pip Q = V[i];
            pos = i;
            if(V[i].second.first == 1 || V[i].second.second == 1)
            {
                string a = A[Q.first];
                string b = B[Q.first];
                if(SA.find(a) != SA.end() && SB.find(b) != SB.end())
                {
                    ans++;
                }
                SA.insert(a);
                SB.insert(b);
                pos++;
            }
            else
            {
                //cout << "LOL " << i << endl;
                //pos=i;
                break;
            }
        }
        vector<pip> GG;
        for(int i=pos;i<V.size();i++)
            GG.pb(V[i]);
        V = GG;
        //cout << V.size() << endl;
        while(V.size() > 0)
        {
            //cout << V[0].first << endl;
            pip Q = V[0];
            string a = A[Q.first];
            string b = B[Q.first];
            //cout << a << " " << b << endl;
            if(SA.find(a) != SA.end() && SB.find(b) != SB.end())
            {
                ans++;
            }
            SA.insert(a);
            SB.insert(b);
            tmp.clear();
            MA[a]--;
            MB[b]--;
            for(int j=1;j<V.size();j++){
                int ii = V[j].first;
                tmp.pb(pip(ii, pii(MA[A[ii]], MB[B[ii]])));
            }
            V = tmp;
            sort(V.begin(),V.end(), cmp2);
            /*for(int i=0;i<V.size();i++)
            {
                cout << V[i].second.first << " " << V[i].second.second << endl;
            }
            cout  << "siz " <<V.size() << endl;*/
        }
        cout << ans << endl;
    }
    return 0;
}
