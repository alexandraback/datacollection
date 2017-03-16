#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

#define SI(x) scanf("%d ",&x)
#define SL(x) scanf("%lld",&x)

typedef long long LL;
using namespace std;

int howMany(int n,int B)
{
    
    int p10 = 1, t = n, m = 1, ret = 0,N = n;
    set<int> S;
    while(t>9)
    {
        t/=10;
        p10*=10;
    }
    t = p10;
    
    while(t>0)
    {
        m = p10*(n%10);
        m+=(n/10);
        t/=10;
        if(m>N && m<=B){
          S.insert(m);
        }
        n = m;
    }

    return S.size();

}


int main()
{
    freopen("in.in","r",stdin);
    freopen("outputC.txt","w",stdout);
    
    int T, tnum = 1;
    SI(T);

    int A,B;
    while(T-- >0)
    {
        SI(A); SI(B);
        int ans = 0;
        
        for(int i=A;i<=B;i++)
        {
            ans+=howMany(i,B);  
        }

        printf("Case #%d: %d\n",tnum,ans);
        tnum++;
    }


    fclose(stdout);
	return 0;
}
