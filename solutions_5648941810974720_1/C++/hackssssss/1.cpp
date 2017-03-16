
#include<bitset>
#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;int f=1;
    while((c=getchar())<'0' || c>'9')if(c=='-')f=-1;
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res*f;
}
const int N=100010,MOD=1e9+7;
int num[12345];
int ch[12345];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("in.txt","w",stdout);
    int T,t = 0;
    scanf("%d",&T);
    while(T--)
    {
        memset(ch,0,sizeof(ch));
        memset(num,0,sizeof(num));
        string str,ans = "";
        cin>>str;
        for(int i = 0; i < str.size(); ++i)
            ++ch[str[i]-'A'];
        num[0] = ch[25];num[2] = ch[22];num[4] = ch[20];num[6] = ch[23];num[8] = ch[6];
        num[1] = ch[14]-num[0]-num[2]-num[4];num[3] = ch[7]-num[8];num[5] = ch[5]-num[4];
        num[7] = ch[18]-num[6];num[9] = (ch[13]-num[1]-num[7])/2;
        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < num[i]; ++j)
            {
                ans += ('0'+i);
            }
        }
        printf("Case #%d: ",++t);
        cout<<ans<<endl;
    }
    return 0;
}
