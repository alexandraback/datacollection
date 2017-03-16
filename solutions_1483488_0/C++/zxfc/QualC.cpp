#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <cassert>
#include <cctype>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int solve(int num, int lm)
{
    int dig[10];
    int numbers[10];
    int nsz=0;
    int k = 10000000;
    while((num/k)==0)k/=10;

    int sz=0;
    int n = num;
    while(k)
    {
        dig[sz++]=n/k;
        n = n%k;
        k/=10;
    }
    for(int i=1; i<sz; i++)
    {
        if(dig[i]==0)continue;
        if(dig[i]<dig[0])continue;
        int tn=0;
        for(int j=0; j<sz; j++)
        {
            tn = tn*10+dig[(i+j)%sz];
        }
        bool check=true;
        for(int j=0; j<nsz; j++)
        {
            if(tn==numbers[j])check=false;
        }
        if(check)numbers[nsz++]=tn;
    }
    int cnt=0;
    for(int i=0; i<nsz; i++)if(numbers[i]<=lm && numbers[i]>num)cnt++;
    return cnt;
}

int main()
{
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "w", stdout);
	int testcases;
	scanf("%d", &testcases);
	for(int cases=1; cases<=testcases; cases++)
	{
	    int a, b;
	    int res=0;
	    scanf("%d%d", &a, &b);
	    for(int i=a; i<b; i++)
            res+=solve(i, b);
	    printf("Case #%d: %d\n", cases, res);
	}
	return 0;
}

