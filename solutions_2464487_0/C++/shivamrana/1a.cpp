/* shivamrana */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
#define f0r(i,n) for(int i=0;i<n;i++)
#define fOr(i,n) for(int i=1;i<=n;i++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%I64d",a)
#define n(l) cout<<endl
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;
int main()
{
    freopen("1a.in","r",stdin);
    freopen("1a.out","w",stdout);
    int te;
    si(te);
    for(int c=1;c<=te;c++)
    {
    ll r ,total;
    cin>>r>>total;
    int n=0;
    while(1)
    {
    int temp=((r+1)*(r+1))-(r*r);
    if(total>=temp){
    n++;
    total-=temp;
    }
    else break;
    r=r+2;
    }
    printf("Case #%d: %d\n",c,n);
    }
    
    


//system("pause");
return 0;
}
