#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

#define FOR(i,n) for (int i = 0 ; i< n;i++)
#define FORI(i,s,e) for (int i = s ; i<= e;i++)
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define RALL(x) x.rbegin(),x.rend()
#define SZ(x) x.size()
#define FZ(x) memset(x,0,sizeof(x))


using namespace std;


bool multiplication_is_safe(unsigned long long a, unsigned long long  b) {
    return (log2(a)+log2(b)<=62);
}

int main()
{
    FILE* f = fopen("bull.in","r");
    FILE* fout = fopen("bull.out","w");
    int tt;
    fscanf(f,"%d\n",&tt);
    FOR(i,tt)
    {
        fprintf(fout,"Case #%d: ",i+1);
        unsigned long long r,t;
        fscanf(f,"%llu %llu\n",&r,&t);


        unsigned long long ll = 0;
        unsigned long long rr = 7071067800;
        unsigned long long best=0;
        while (ll<=rr)
        {
            unsigned long long mid = (ll+rr)/2;

            if (multiplication_is_safe(2*mid,mid-1)&&multiplication_is_safe(2*r+1,mid))
            {
                if ((2*mid*(mid-1))+(2*r+1)*mid<=t)
                {
                    //cout << mid<<endl;
                    //cout << t<<endl;
                    //cout << (2*mid*(mid-1))+(2*r+1)*mid <<endl;
                    //cout << "___________________________"<<endl;
                    best = mid;
                    ll=mid+1;
                }
                else
                {
                    rr=mid-1;
                }
            }
            else
            {
                rr=mid-1;
            }

        }
        fprintf(fout,"%llu\n",best);

    }

    fclose(fout);
}
