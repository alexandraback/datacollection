#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define mp(a,b) make_pair(a,b)

const int N = 4e5;
const int mod = 1000000007;
const int inf = 1e9;
const double pi =  acos(-1.0);
const double eps = 1e-8;

struct unionset
{
    int fat[1003],len;
    void init(int x)
    {
        len = x;
        for(int i=0;i<x;i++)
            fat[i] = i;
        return ;
    }
    int getf(int x)
    {
        if(fat[x] == x)
            return x;
        return fat[x] = getf(fat[x]);
    }
    void un(int x,int y)
    {
        fat[getf(y)] = getf(x);
        return ;
    }
};

struct tree_array
{
    int c[1003];
    int v[1003],len;
    int get_low(int x) {return x&(-x);}
    void init(int x)
    {
        len = x;
        for(int i=0;i<x;i++)
            c[i] = v[i] = 0;
        return ;
    }
    void add(int x,int value)///v[x] += v
    {
        v[x] += value;
        while(x<=len)
        {
            c[x] += value;
            x += get_low(x);
        }
        return ;
    }
    int sum(int x)/// sigma(1,x)
    {
        int ans = 0;
        while(x>0)
        {
            ans += c[x];
            x -= get_low(x);
        }
        return ans;
    }
};

int pow_mod(int a,int b,int c)
{
    long long ans = 1,tmp = a;
    while(b){
        if(b&1)ans = ans*tmp%c;
        tmp = tmp*tmp%c;
        b>>=1;
    }
    return ans;
}

long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}

/// -------------------------------

class ColorfulCoins
{
    public:
        int minQueries(vector<long long> values)
        {
            int xx[100];
            int n = values.size()-1;
            for(int i=0;i<values.size();i++)
                xx[i] = values[i+1]/values[i];
            if(n == 0)return 0;
            int cnt = n,tag[100] = {0};
            while(cnt>0){
                int id = 0,bb = 0;
                for(int i=0;i<n;i++)
                if(tag[i]==0&&xx[i]>bb){
                    id = i;
                    bb = xx[i];
                }
                tag[id] = 1;
                cnt --;
            }
        }
};

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        double c,f,x;
        double d = 2;
        scanf("%lf%lf%lf",&c,&f,&x);
        double ans = x/d;
        double now = 0;
        while(now<ans){
            now += c/d;
            d += f;
            if(now + x/d > ans)break;
            ans=now + x/d;
        }
        printf("Case #%d: %.7lf\n",cas,ans);
    }
    return 0;
}
