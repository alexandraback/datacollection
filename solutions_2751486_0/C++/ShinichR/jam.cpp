#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

#define FOR(i,n,first) for(int i=first;i<n;i++)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define pb push_back
#define N 11000
#define M 121000
const int MOD=100000007;
const int INF = 0x3f3f3f3f;
const int MAX_N =130;
typedef pair<int,int> pii;
typedef long long int Int64;
//#define SMALL
//#define BIG
map<char ,int>maps;

int main()
{
    #ifdef SMALL
    freopen("A-small-attempt2.in","rt",stdin);
    freopen("text_sm.out","w",stdout);
    #endif
    #ifdef BIG
    freopen("text.in","rt",stdin);
    freopen("text_bg.out","w",stdout);
    #endif

    maps['a']=1,maps['e']=1,maps['i']=1;
    maps['o']=1,maps['u']=1;
    int n,w;
    char str[210];
    scanf("%d",&n);
    for(int ii=1;ii<=n;ii++){
        scanf("%s %d",&str,&w);
        int len=strlen(str);
        int ans=0;
        for(int i=0;i<len;i++){
          //  printf("i = %d------\n",i);
            bool flag=false;
            int now=0;
            for(int j=i;j<len;j++){
                if(!maps[str[j]])now++;
                else now=0;
                if(now==w){
                    flag=true;
                }
                if(flag)ans++;
                //if(now>w)break;
              //  printf("now = %d\n",now);
            }
        }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
