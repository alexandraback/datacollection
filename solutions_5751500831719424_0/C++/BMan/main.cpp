//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<cmath>
#include<climits>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb(a) push(a)
#define INF 0x1f1f1f1f
#define lson idx<<1,l,mid
#define rson idx<<1|1,mid+1,r
#define PI  3.1415926535898
template<class T> T min(const T& a,const T& b,const T& c) {
    return min(min(a,b),min(a,c));
}
template<class T> T max(const T& a,const T& b,const T& c) {
    return max(max(a,b),max(a,c));
}
void debug() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
   // freopen("d:\\out1.txt","w",stdout);
#endif
}
int getch() {
    int ch;
    while((ch=getchar())!=EOF) {
        if(ch!=' '&&ch!='\n')return ch;
    }
    return EOF;
}

const int maxn = 110;
char s[maxn][maxn];

vector<pair<int,char> > x[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%s", s[i]);
        for(int i = 1; i <= n; i++)
            x[i].clear();
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; s[i][j] != '\0'; )
            {
                int k = j + 1;
                while(s[i][k] != '\0' && s[i][k] == s[i][j]) k++;
                x[i].push_back(make_pair(k - j, s[i][j]));
                j = k;
            }
        }
        printf("Case #%d: ", ca);
        int flag = 1;
        for(int i = 1; i <= n; i++)
            if(x[i].size() != x[1].size())
                flag = 0;
        if(!flag)
        {
            printf("Fegla Won\n");
            continue;
        }

        for(int j = 0; j < x[1].size(); j++)
        {
            for(int i = 1; i <= n; i++)
            {
                if(x[i][j].second != x[1][j].second)
                {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag)
        {
            printf("Fegla Won\n");
            continue;
        }

        int res = 0;
        for(int j = 0; j < x[1].size(); j++)
        {
            int a[maxn];
            for(int i = 1; i <= n; i++)
                a[i - 1] = x[i][j].first;
            sort(a, a + n);
            for(int i = 0 ; i < n; i++)
                res += abs(a[i] - a[n / 2]);
        }

        printf("%d\n", res);
    }
    return 0;
}
