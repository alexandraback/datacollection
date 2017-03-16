#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define TWO(i) (1<<(i))
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VIit;
typedef pair<int,int> PII;
typedef map<int,int> MII;
typedef MII::iterator MIIit;
typedef set<int> SI;
typedef SI::iterator SIit;
typedef long long LL;
const int DX[8]={1,-1,0,0,1,1,-1,-1};
const int DY[8]={0,0,1,-1,1,-1,1,-1};
const int intmax=0x7fffffff;
const int mod=1000000007;
int t;
double f[100005];
int la,lb;
int main()
{
    freopen("1.txt","r",stdin);
    freopen("3.txt","w",stdout);
    scanf("%d",&t);
    for(int mt=1;mt<=t;mt++)
    {
        scanf("%d%d",&la,&lb);
        for(int i=0;i<la;i++) scanf("%lf",f+i);
        double exp1=2+lb;
        double exp2=1e100;
        double pro=1.0;
        for(int i=0;i<la;i++)
        {
            pro*=f[i];
            int len=(la-i-1)*2+(lb-la)+1;
            double texp=len*pro+(len+1+lb)*(1-pro);
            exp2=min(exp2,texp);
        }
        printf("Case #%d: %.6f\n",mt,min(exp1,exp2));
    }
}

