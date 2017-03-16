// User :: lovelotus ( Prem Kamal )

//#include<bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<cctype>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<deque>

#define lli long long int
#define ulli unsigned long long int
#define F first
#define S second
#define pii pair<int,int>
#define pip pair<int,pii>
#define pis pair<int,string>
#define pll pair<lli,lli>

using namespace std;

int main()
{
    freopen("C:\\Users\\lovelotus\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\lovelotus\\Desktop\\output.txt","w",stdout);
    int t,r,w,c,tst=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: %d\n",tst,(c/w)*r+w-(c%w==0));
        tst++;
    }
    return 0;
}
