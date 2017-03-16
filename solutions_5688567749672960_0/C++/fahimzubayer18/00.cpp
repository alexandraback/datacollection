#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
#define PI 2 * acos (0.0)
#define mod 1000000007
#define f first
#define s second
using namespace std;

int bs(int *st,int *en,int val,char c) // en = size+1
{
    int k;
    //first element not less than val,else returns last
    if(c=='l') k=lower_bound(st,en,val)-st;
    //first element greater than val,else returns last
    if(c=='u') k=upper_bound(st,en,val)-st;
    return k;
}

int prime[78500];
int sieve() // RETURNS ACTUAL SIZE!!! NOT SIZE+1!!!! REMEMBER WELL!! >_<
{
    int a,b,c;
    c=0; prime[c]=2;
    bool *m=(bool *)calloc(1000006,sizeof(bool));
    for(a=3;a<=1000000;a=a+2)
    {
        if(!m[a])
        {
            prime[++c]=a;
            for(b=2*a;b<=1000000;b=b+a) m[b]=true;
        }
    }
    free(m);
    return c;
}

// inverse mod of i%prime = bigmod(i,prime-2)
ll bigmod(ll i,ll pow)
{
	if(pow<1) return 1;
	if(pow==1) return i%mod;
	ll j;
	if(pow%2)
	{
		j=(i*bigmod(i,pow-1))%mod;
	}
	else
	{
		j=bigmod(i,pow/2);
		j=(j*j)%mod;
	}
	return j;
}

int ar[10005];

int flipnum(int i)
{
    int a,b,c;
    b=0;
    while(i>=1)
    {
        b=b*10+i%10;
        i=i/10;
    }
    return b;
}


map<int,int>M;
bool bi[1000005];

priority_queue< pair<int,int> >Q;

void dijkstra(int i)
{
    M.clear();

    M[1]=1;

    for(int a=1;a<=i;a++) bi[a]=false;

    pair<int,int>p;

    p.f=-1;
    p.s=1;

    while(!Q.empty()) Q.pop();

    Q.push(p);

    int a,b,c,d,e,x,y,z;

    while(!Q.empty())
    {
        p=Q.top(); Q.pop();

        b=p.s; d=p.f*-1;

        if(bi[b]) continue; bi[b]=true;

        if(b==i) break;

        if(!bi[b+1])
        {
            M[b+1]=d+1;
            p.s=b+1;
            p.f=-1*M[b+1];
            Q.push(p);
        }
        else
        {
            if(d+1<M[b+1])
            {
                M[b+1]=d+1;
                p.s=b+1;
                p.f=-1*M[b+1];
                Q.push(p);
            }
        }
        x=flipnum(b);
        if(x>i) continue;
        if(!bi[x])
        {
            M[x]=d+1;
            p.s=x;
            p.f=-1*M[x];
            Q.push(p);
        }
        else
        {
            if(d+1<M[x])
            {
                M[x]=d+1;
                p.s=x;
                p.f=-1*M[x];
                Q.push(p);
            }
        }
    }
    cout<<M[i]<<endl;
}

int main()
{

    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int iter,tn;

	ll a,b,c,d,e,x,y,z,n,k;

    scanf("%d",&tn);

	for(iter=1;iter<=tn;iter++)
	{
	    printf("Case #%d: ",iter);

	    cin>>n;

	    dijkstra(n);

	}

    return 0;
}
