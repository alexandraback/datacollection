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

const int  N = 5 + 2000;
int vis[N];
char s[N];
char w[100][100] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int mp[10] = {0,8,2,4,6,7,1,3,5,9};

vector<int> res;

bool ok(int x,int k)
{
        for(int j = 0 ; j < k ; j++)
        {
            if(!vis[w[x][j]])
            {
                return 0;
            }
        }
        return 1;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE

#endif
    int Case ,tot = 1;
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%s",s);
        memset(vis,0,sizeof(vis));
        int l = strlen(s);
        for(int i = 0 ; i < l ; i++)
        {
            vis[s[i]]++;
        }
        res.clear();

        for(int i = 0; i <= 9 ; i++)
        {

            int k = strlen(w[mp[i] ]);
            while(ok(mp[i],k))
            {
                res.push_back(mp[i]);
                for(int j = 0 ; j < k ; j++)
                    vis[w[mp[i]][j] ]--;
            }
        }
        printf("Case #%d: ",tot++);
        sort(res.begin(),res.end());
        for(int i = 0 ; i < res.size() ; i++)
            printf("%d",res[i]);
        puts("");

    }
    return 0;
}
