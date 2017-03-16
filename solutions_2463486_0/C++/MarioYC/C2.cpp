#include <cstdio>

using namespace std;

long long prec[] = {
1LL,
4LL,
9LL,
121LL,
484LL,
10201LL,
12321LL,
14641LL,
40804LL,
44944LL,
1002001LL,
1234321LL,
4008004LL,
100020001LL,
102030201LL,
104060401LL,
121242121LL,
123454321LL,
125686521LL,
400080004LL,
404090404LL,
10000200001LL,
10221412201LL,
12102420121LL,
12345654321LL,
40000800004LL,
1000002000001LL,
1002003002001LL,
1004006004001LL,
1020304030201LL,
1022325232201LL,
1024348434201LL,
1210024200121LL,
1212225222121LL,
1214428244121LL,
1232346432321LL,
1234567654321LL,
4000008000004LL,
4004009004004LL
};

int main(){
    int T;
    long long A,B;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%lld %lld",&A,&B);
        int ans = 0;
        
        for(int i = 0;i < 39;++i)
            if(prec[i] >= A && prec[i] <= B)
                ++ans;
        
        printf("Case #%d: %d\n",tc,ans);
    }
    
    return 0;
}
