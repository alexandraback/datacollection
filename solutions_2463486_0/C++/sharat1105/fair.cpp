#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<cassert>
#include<iomanip>
using namespace std;

#define LL long long
#define PI pair<int,int>
#define F first
#define S second
#define MP make_pair
#define VI vector<int>
#define VPI vector<PI>
#define PB push_back

#define MAXN 100000000000000LL
#define MAXP 10000000LL

LL A,B;
vector<LL> v;

bool isPalindrome(LL n)
{
    LL d[20];
    int sz = 0;
    while(n){
        d[sz++] = n%10LL;
        n /= 10LL;
    }
    sz--;
    int i=0;
    while(sz-i > i){
        if(d[sz-i] != d[i]) return 0;
        i++;
    }
    return true;
}

void preprocess()
{
    for(LL i=1;i<=MAXP;i++){
        if(isPalindrome(i) && isPalindrome(i*i)) v.PB(i*i);
    }
}

int main()
{
    freopen("input1.txt","r", stdin);
    freopen("output1.txt", "w", stdout);
    preprocess();
    int sz = v.size();
    //printf("size of vector is %d\n", sz);
    //for(int i=0;i<sz;i++) printf("%lld\n", v[i]);
    int cases;
    scanf("%d", &cases);
    for(int casenum=1;casenum<=cases;casenum++){
        scanf("%lld%lld", &A, &B);
        int idx1 = 0;
        while(idx1 < sz && v[idx1] < A) idx1++;
        int idx2 = sz-1;
        while(idx2 >=0 && v[idx2] > B) idx2--;
        printf("Case #%d: %d\n", casenum, idx2-idx1+1);
    }
    return 0;
}
