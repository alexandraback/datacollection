#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std;
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define fs first
#define sc second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ppii pair< pii,int >
#define big 2000000000

int kasus,a,b,k,jawab;

int main()
{
//    freopen("B-small-attempt0.in","r",stdin);
//    freopen("b.out","w",stdout);
    
    scanf("%d",&kasus);
    for (int z=1;z<=kasus;z++)
    {
        scanf("%d %d %d",&a,&b,&k);
        jawab = 0;
        for (int i=0;i<a;i++)
            for (int j=0;j<b;j++)
                if ((i&j) < k) jawab++;
        printf("Case #%d: %d\n",z,jawab);
    }
    
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
