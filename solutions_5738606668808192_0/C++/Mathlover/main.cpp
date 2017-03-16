#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
long long tran(int p,int n)
{
    long long ans=0;
    long long base=1;
    while(p)
    {
        ans+=p%2*base;
        base*=n;
        p/=2;
    }
    return ans;
}
#define MAXN 10
#define C 16381
long long mi;

long long multi(long long a, long long b, long long n){
	long long tmp = a % n, s = 0;
	while(b){
		if(b & 1) s = (s + tmp) % n;
		tmp = (tmp + tmp) % n;
		b >>= 1;
	}
	return s;
}

long long Pow(long long a, long long b, long long n){
	long long tmp = a % n, s = 1;
	while(b){
		if(b & 1) s = multi(s, tmp, n);
		tmp = multi(tmp, tmp, n);
		b >>= 1;
	}
	return s;
}

int witness(long long a, long long n){
	long long u = n - 1, t = 0, i, x, y;
	while(!(u & 1))	u >>= 1, t ++;
	x = Pow(a, u, n);
	for(i = 1; i <= t; i ++){
		y = multi(x, x, n);
		if(y == 1 && x != 1 && x != n -1) return 1;
		x = y;
	}
	if(x != 1) return 1;
	return 0;
}

int test(long long n){
	long long a;
	int i;
	if(n == 2) return 1;
	if(n < 2 || !(n & 1)) return 0;
	srand((long long)time(0));
	for(i = 0; i < MAXN; i ++){
		a = ((long long) rand()) % (n - 2) + 2;
		if(witness(a, n)) return 0;
	}
	return 1;
}

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

long long pollard_rho(long long n, long long c){
	long long x, y, d, i = 1, k = 2;
	srand((long long)time(0));
	x = ((long long) rand()) % (n - 1) + 1;
	y = x;
	while(1){
		i ++;
		x = (multi(x, x, n) + c) % n;
		d = gcd(y - x + n, n);
		if(d != 1 && d != n) return d;
		if(y == x) return n;
		if(i == k) y = x, k <<= 1;
	}
}

void cal(long long n, long long c){
	long long r;
	if(n <= 1) return;
	if(test(n)){
		if(mi > n) mi = n;
		return;
	}
	r = pollard_rho(n, c--);
	cal(n / r, c);
	cal(r, c);
}

long long MaxPrimeFactor(long long n)
{
	if(test(n))
	return n;

	long long k=-1,g;
	mi=n;
	cal(n,C);

	g=MaxPrimeFactor(mi);
	k=g>k?g:k;

	g=MaxPrimeFactor(n/mi);
	k=g>k?g:k;
	return k;
}
void print(int i)
{
    int temp[100];
    int cnt=0;
    while(i)
    {
        temp[cnt++]=i%2;
        i/=2;
    }
    for(int i=cnt-1;i>=0;--i)
        cout<<temp[i];
}
int main()
{
    int t;
    int ca=0;
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("Case #%d:\n",++ca);
        for(int i=(1<<n-1)+1;i<(1<<n)-1;i+=2)
        {
            if(m==0)
                break;
            bool flag=0;
            for(int j=2;j<=10;++j)
            {
                long long q=tran(i,j);
                if(test(q))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                continue;
            print(i);
            for(int j=2;j<=10;++j)
            {
                mi=1<<30;
                cal(tran(i,j),16381);
                printf(" %I64d",mi);
            }
            puts("");
            m--;
        }

    }
}
