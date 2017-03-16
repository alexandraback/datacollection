//MJRT
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//////////////////////
#include<iostream>
#include<algorithm>
#include<string>
#include <iterator>
#include<sstream>
#include<functional>
#include<numeric>
///////////////////////
#include<vector>
#include<map>
#include <stack>
#include<queue>
#include<set>
#include <bitset>
#include <list>
///////////////////////
//#include<ext/pb_ds/priority_queue.hpp> //pd_bs库,hdu&&poj不支持
using namespace std;
#define lowbit(x) ((x)&(-x))
static int INDEX = 0,BUGs = 0;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a,b) * b;    }
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x)          cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)      {cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n";}
#define Show2(x,s,l,h)   {cout << #x << ": " << l-s << "*" <<h-s <<"\n"; for(int j = s ; j < s+h ; j++){for(int i = s ; i < s+l ; i++) cout << x[j][i] << " ";cout << "\n";};  cout << "\n";}

typedef  long long int LL;
const int INF = 0x3f3f3f3f;

//const int  N = 5 + ;
//bool vis[N];
map<string,int> mp1,mp2;
vector<string> w1,w2;
int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case,tot=1;
    string s1,s2;
    int n;
    cin >> Case ;
    while(Case--)
    {
        int cnt = 0;

        mp1.clear();mp2.clear();

        cin >> n;
        while(n--)
        {
            cin >> s1 >> s2;

            if(!mp1.count(s1))     mp1[s1] = 1;
            else      mp1[s1]++;

            if(!mp2.count(s2))     mp2[s2] = 1;
            else      mp2[s2]++;

            w1.push_back(s1);
            w2.push_back(s2);
        }

        for(int i = 0 ; i < w1.size() ; i++)
        {
            if(mp1[w1[i]] >1 && mp2[w2[i] ]>1 )    cnt++;
        }
        cout << "Case #" << tot++ <<": " << cnt << endl;


    }
    return 0;
}
