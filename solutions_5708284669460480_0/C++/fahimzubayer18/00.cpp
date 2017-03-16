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

string K;
vector<string>v;
int L;
string tar;
vector<int>ans;

void recur(int len,string s)
{
    if(len==L)
    {
        v.push_back(s);
        return;
    }
    for(int a=0;a<K.size();a++)
    {
        recur(len+1,s+K[a]);
    }
}

int cnt[500];

void generate()
{
    v.clear();
    ans.clear();
    recur(0,"");
    int a,b,c,e,x;
    string s;
    x=0;
    for(a=0;a<v.size();a++)
    {
        s=v[a];
        e=0;
        for(b=0;b+tar.size()-1<s.size();b++)
        {
            for(c=0;c<tar.size();c++)
            {
                if(s[b+c]!=tar[c]) break;
            }
            if(c==tar.size()) e++;
        }
        ans.push_back(e);
        x=max(e,x);
    }

    //cout<<x<<endl;

    for(a=0;a<=x;a++) cnt[a]=0;

    for(a=0;a<ans.size();a++)
    {
        //cout<<ans[a]<<endl;
        ans[a]=x-ans[a];
        //cout<<ans[a]<<endl;
        cnt[ ans[a] ]++;
    }

    double an,sz,p;

    an=0.00;

    sz=v.size()*1.00;

    for(a=0;a<=x;a++)
    {
        p=(a*1.00)*((cnt[a]*1.00)/sz);
        //cout<<a<<" "<<cnt[a]<<endl;
        an=an+p;
    }

    cout<<an<<endl;
}

int main()
{

    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);


    cout << fixed << setprecision(10);
    //std::ios::sync_with_stdio(false);



	int te,ti;

	scanf("%d",&te);

	int a,b,c,d,e,x,y,z,n;

	for(ti=1;ti<=te;ti++)
	{
	    cout<<"Case #"<<ti<<": ";

	    cin>>x>>y>>z;
	    cin>>K;
	    cin>>tar;
	    L=z;
	    generate();
	}

    return 0;
}
