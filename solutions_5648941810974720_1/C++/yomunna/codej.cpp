/*While alive CODE*/

					/*War will happen and code will follow*/

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define pb push_back
#define mk make_pair
#define pi 3.1415926535897932384626433832795

#define slld(x) scanf("%lld",&x)
#define sd(x) scanf("%d",&x)
#define sld(x) scanf("%ld",&x)
#define ss(x)  scanf("%s",x)

void debug(int* a, int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}


ll readline() {
        ll c = getchar();
        while (c < 33)
                c = getchar();
        int k=0;
        while (c > 32) {
                k = k*10 + (ll)c-48;
                c = getchar();
        }
        return k;
}
void print(ll x) {
     static char c[30];
     ll len = 0;
     if (x == 0) {
             c[0] = '0';
             len = 1;
     }
     while (x > 0) {
             int y = x / 10;
             c[len++] = (x - y * 10) + '0';
             x = y;
     }
     while (len > 0) {
             --len;
             putchar(c[len]);
     }
}



#define mod 1000000007
ll power(ll b, ll e) {
ll x = 1, y = b;
    while(e > 0) {
        if(e%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        e /= 2;
    }
    return x;
}

long long md(long long x)
{if(x==0)
return 0;
    if(x>0)
    {long long j=x/mod;
    x=x-j*mod;
    return x;}
    else
    {long long j=(-1*x)/mod;
    if((-1*x)%mod==0)
        return 0;

    x=x+(j+1)*mod;
    return x;


    }



}
int freq[10];
int coun[26];



int main()
{
	freopen("A-large (2).in", "r", stdin);
	freopen("Output1.out", "w", stdout);


    string a;
long long int t;
cin>>t;
//t=1;
for(int y=0;y<t;y++)
		{cin>>a;
		for(int i=0;i<10;i++)freq[i]=0;
		for(int i=0;i<26;i++)coun[i]=0;
		int len=a.size();
		for(int i=0;i<len;i++)coun[a[i]-'A']++;

		freq[0]=coun['Z'-'A'];
		coun[25]-=freq[0];
		coun['E'-'A']-=freq[0];
		coun['R'-'A']-=freq[0];
		coun['O'-'A']-=freq[0];
		freq[6]=coun['X'-'A'];
		coun['X'-'A']-=freq[6];
		coun['S'-'A']-=freq[6];
		coun['I'-'A']-=freq[6];
		freq[7]=coun['S'-'A'];
		coun['E'-'A']-=freq[7];
		coun['S'-'A']-=freq[7];
		coun['V'-'A']-=freq[7];
		coun['E'-'A']-=freq[7];
		coun['N'-'A']-=freq[7];
		freq[5]=coun['V'-'A'];
		coun['F'-'A']-=freq[5];
		coun['I'-'A']-=freq[5];
		coun['V'-'A']-=freq[5];
		coun['E'-'A']-=freq[5];
		freq[4]=coun['F'-'A'];
		coun['F'-'A']-=freq[4];
		coun['O'-'A']-=freq[4];
		coun['U'-'A']-=freq[4];
		coun['R'-'A']-=freq[4];
		freq[8]=coun['G'-'A'];
		coun['E'-'A']-=freq[8];
		coun['I'-'A']-=freq[8];
		coun['G'-'A']-=freq[8];
		coun['H'-'A']-=freq[8];
		coun['T'-'A']-=freq[8];
		freq[3]=coun['H'-'A'];
		coun['T'-'A']-=freq[3];
		coun['H'-'A']-=freq[3];
		coun['R'-'A']-=freq[3];
		coun['E'-'A']-=freq[3];
		coun['E'-'A']-=freq[3];
		freq[2]=coun['T'-'A'];
		coun['T'-'A']-=freq[2];
		coun['W'-'A']-=freq[2];
		coun['O'-'A']-=freq[2];
		freq[1]=coun['O'-'A'];
		coun['N'-'A']-=freq[1];
		coun['E'-'A']-=freq[1];
		coun['O'-'A']-=freq[1];
		freq[9]=coun['I'-'A'];
		cout<<"Case #"<<y+1<<": ";
		for(int i=0;i<10;i++){if(!freq[i])continue;
            while(freq[i]){cout<<i;freq[i]--;}

		}
cout<<"\n";






}




return 0;}

