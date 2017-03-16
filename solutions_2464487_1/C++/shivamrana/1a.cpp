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
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;
int main()
{
    freopen("1b.in","r",stdin);
    freopen("1b.out","w",stdout);
    int te;
    si(te);
    for(int c=1;c<=te;c++)
    {
    unsigned long long r,t;
   cin>>r>>t;
    unsigned long long n;
    long long piggi=1000000000000000000LL,l=1000000000,m=piggi/r;
    unsigned long long p,mid,beg,end;
        beg=0;end=(m<=l?m:l);
        while(beg<=end)
        {
                mid=(beg+end)/2;
                //printf("beg=%llu mid=%llu end=%llu\n",beg,mid,end);
                if(mid==beg)
                {
                        mid=end;
                        p=2*mid*mid+mid*(r+r-1);
                        if(p<=t)
                        n=end;
                        else n=beg;
                        break;
                }
                p=2*mid*mid+mid*(r+r-1);
                if(p>t)
                end=mid-1;
                else
                beg=mid;
                
        }
    printf("Case #%d: %llu\n",c,n);
    //cerr<<c<<endl;
    }
    
    


//system("pause");
return 0;
}
