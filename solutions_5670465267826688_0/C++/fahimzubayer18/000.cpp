#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
#define PI 2 * acos (0.0)
#define mod 1000000007
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

int mult[10][10];

void init()
{
    mult[1][1]=1; mult[1][2]=2; mult[1][3]=3; mult[1][4]=4;

    mult[2][1]=2; mult[2][2]=-1; mult[2][3]=4; mult[2][4]=-3;

    mult[3][1]=3; mult[3][2]=-4; mult[3][3]=-1; mult[3][4]=2;

    mult[4][1]=4; mult[4][2]=3; mult[4][3]=-2; mult[4][4]=-1;
}


string ch;
int ar[1000005];
int pre[1000005];
int suf[1000005];

vector<int>pr;
vector<int>sf;

int s[4*1000005];

void build(int lo,int hi,int at)
{
    if(lo==hi)
    {
        s[at]=ar[lo];
        return;
    }
    int mid=(lo+hi)/2;
    build(lo,mid,2*at);
    build(mid+1,hi,2*at+1);
    int i=s[2*at];
    int j=s[2*at+1];

    s[at]=mult[abs(i)][abs(j)];

    if((i<0 && j>0) || (i>0 && j<0)) s[at]=-1*s[at];
    return;
}

int q(int lo,int hi,int at,int from,int to)
{
    if(lo==from && hi==to) return s[at];

    int mid=(lo+hi)/2;
    int i,j,k;

    if(to<=mid)
    {
        return q(lo,mid,2*at,from,to);
    }
    else
    {
        if(from>mid) return q(mid+1,hi,2*at+1,from,to);
        else
        {
            i=q(lo,mid,2*at,from,mid);
            j=q(mid+1,hi,2*at+1,mid+1,to);
            k=mult[abs(i)][abs(j)];

            if((i<0 && j>0) || (i>0 && j<0)) k=-1*k;
            return k;
        }
    }
}

int main()
{

    freopen("0.in","r",stdin);
    freopen("00.out","w",stdout);

    /*
    cout << fixed << setprecision(4);
    std::ios::sync_with_stdio(false);

	*/

	init();

	int a,b,c,d,e,x,y,z,n,k,t,l,i,j;

	cin>>t;


	for(int te=1;te<=t;te++)
	{
	    cout<<"Case #"<<te<<": ";

	    scanf("%d %d",&l,&x);
	    cin>>ch;

	    if(l*x<=2)
	    {
	        printf("NO\n");
	        continue;
	    }

	    pr.clear();
	    sf.clear();

	    for(a=0;a<l;a++)
	    {
	        if(ch[a]=='i') ar[a+1]=2;
	        if(ch[a]=='j') ar[a+1]=3;
	        if(ch[a]=='k') ar[a+1]=4;
	    }
	    e=l;

	    for(a=1;a<x;a++)
	    {
	        for(b=1;b<=l;b++) ar[a*l+b]=ar[b];
	    }
	    //for(a=0;a<x*l;a++) printf("%d",ar[a]); printf("\n");
	    build(1,x*l,1);

	    pre[1]=ar[1];
	    if(pre[1]==2) pr.push_back(a);
	    for(a=2;a<=x*l;a++)
	    {
	        i=pre[a-1];
	        j=ar[a];
            k=mult[abs(i)][abs(j)];

            if((i<0 && j>0) || (i>0 && j<0)) k=-1*k;
            pre[a]=k;
            if(pre[a]==2) pr.push_back(a);
	    }

	    suf[x*l]=ar[x*l];
	    if(suf[x*l]==4) sf.push_back(x*l);
	    for(a=x*l-1;a>=1;a--)
	    {
	        i=ar[a];
	        j=suf[a+1];
            k=mult[abs(i)][abs(j)];

            if((i<0 && j>0) || (i>0 && j<0)) k=-1*mult[abs(i)][abs(j)];
            suf[a]=k;
            if(suf[a]==4) sf.push_back(a);
	    }

	    //for(a=0;a<x*l;a++) printf("%d ",pre[a]); cout<<endl;
	    //for(a=0;a<x*l;a++) printf("%d ",suf[a]); cout<<endl;
	    if(!pr.size() || !sf.size())
	    {
	        printf("NO\n");
	        continue;
	    }

	    sort(sf.begin(),sf.end());
	    for(a=0;a<pr.size();a++)
	    {
	        for(b=0;b<sf.size();b++)
	        {
	            if(pr[a]+1>=sf[b]) continue;
	            c=q(1,x*l,1,pr[a]+1,sf[b]-1);
	            if(c==3)
	            {
	                printf("YES\n");
	                break;
	            }
	        }
	        if(b!=sf.size()) break;
	    }
	    if(a==pr.size()) printf("NO\n");
	}


    return 0;
}
