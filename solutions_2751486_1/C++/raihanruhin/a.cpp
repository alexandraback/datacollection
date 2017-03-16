#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>

using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define KS printf("Case %d: ",kk++)

#define MOD 1000000007
#define MX 1000010

bool isVowel(char ch) {
if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
         return true;
else return false;
}

int next_point[MX];

int main()
{
    READ;
    WRITE;
    int tc,kk=1,n,m,cnt;
    LL sum;
    string s;
    cin>>tc;
    while(tc--)
    {
        cin>>s>>cnt;
        sum=0;

        int sl=s.length();
        for(int i=0;i<sl;i++) next_point[i]=sl;

        int tmp=0,st=0;
        for(int i=0;i<sl;i++)
        {
            if(isVowel(s[i]))
                    tmp=0;
            else tmp++;
            if(tmp>=cnt)
            {
                int limit=i-cnt+1;
                while(st<=limit)
                {
                    next_point[st]=i;
                    st++;
                }
            }
        }

        for(int i=0;i<sl;i++)
        {
            sum+= (long long)(sl-next_point[i]);
            /*int tmp=0;
            for(int j=i;j<sl;j++)
            {
                if(isVowel(s[j]))
                    tmp=0;
                else tmp++;
                if(tmp==cnt)
                {
                    sum+=sl-j;
                    break;
                }
            }*/
        }

        printf("Case #%d: ",kk++);
        cout<<sum;
        printf("\n");
    }
    return 0;
}

