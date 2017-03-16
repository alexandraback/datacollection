#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
#define PI 2 * acos (0.0)
using namespace std;

const int mod = 1000000000 + 7;

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
int bigmod (int k, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return k;
	int q = bigmod(k, p / 2);
	q = (q * 1LL * q) % mod;
	if (p % 2 == 0)
		return q;
	else
		return (q * 1LL * k) % mod;
}

bool bi[1005];
vector<int>v;
int Max;

int main()
{

    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    /*
    cout << fixed << setprecision(4);
    std::ios::sync_with_stdio(false);

	*/

	int te,ti;

	scanf("%d",&te);

	int a,b,c,d,e,x,y,z,n;

	for(ti=1;ti<=te;ti++)
	{
	    cout<<"Case #"<<ti<<": ";

	    scanf("%d %d %d",&a,&n,&Max);

	    v.clear();

	    for(a=0;a<n;a++)
	    {
	        cin>>b;
	        v.push_back(b);
	    }

	    for(a=0;a<=Max;a++) bi[a]=false;
	    bi[0]=true;

	    for(a=1;a<(1<<n);a++)
	    {
	        x=0;
	        for(b=0;b<n;b++)
	        {
	            if((a&(1<<b))) x=x+v[b];
	        }
	        bi[x]=true;
	        //cout<<x<<" possible "<<endl;
	    }

	    e=0;
	    for(a=1;a<=Max;a++)
	    {
	        if(!bi[a])
	        {
	            e++;
	            for(b=Max-a;b>=0;b--)
	            {
	                if(bi[b]) bi[b+a]=true;
	            }
	        }
	    }
	    cout<<e<<endl;
	}

    return 0;
}
