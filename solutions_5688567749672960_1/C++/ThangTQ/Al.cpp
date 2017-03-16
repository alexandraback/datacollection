#include<bits/stdc++.h>

using namespace std;

long long p[20], N;

int countd(long long N)
{
    int res = 0;
    while (N>0)
    {
        res++;
        N/=10;
    }
    return res;
}

long long get9(int d)
{
    long long res = 0;
    for(int i=1; i<=d; i++) res=res*10+9;
    return res;
}

long long rev(long long a)
{
    long long res = 0;
    while (a>0)
    {
        res=res*10+(a%10);
        a/=10;
    }
    return res;
}

long long tt(int l, long long a)
{
    long long res = a - p[l-1];
    for(int i=1; i<l; i++)
    {
        long long t = a%p[l-i];
        //cout<<i<<' '<<t<<endl;
        if (t==0)
        {
            //cout<<'a'<<endl;
            long long tmp = 0;
            for(int j=l-i+1; j<=l; j++)
                tmp=tmp+(a/p[j-1]%10)*p[j-(l-i+1)];
            //cout<<tmp<<endl;
            tmp-=1;
            long long t2=rev(tmp);
            if (t2<p[i-1]) continue;
            //cout<<tmp<<endl;
            res=min(res,t2+p[l-i]);
        } else
        {
            long long t1 = 0;
            for(int j=l-i+1; j<=l; j++)
                t1=t1*10+(a/p[j-1]%10);
            res=min(res,t1+t);
        }
    }
    return res;
}

long long solve()
{
    long long res = 0;
    int L = countd(N);
    if (L==1) return N;
    //cout<<L<<endl;
    for(int i=1; i<L; i++)
    {
        if (i>1) res+=tt(i,get9(i)); else res+=9;
        res+=1;
        //cout<<res<<endl;
    }
    res+=tt(L,N);
    return res;
}

int main()
{
	freopen("test.inp","r",stdin); freopen("a.out","w",stdout);
	p[0]=1;
	for(int i=1; i<=15; i++) p[i]=p[i-1]*10;
	int T; scanf("%d",&T);
	for(int i=1; i<=T; i++)
    {
        scanf("%I64d",&N);
        long long res = solve();
        printf("Case #%d: %I64d\n",i,res);
    }
	fclose(stdin); fclose(stdout);
	return 0;
}
