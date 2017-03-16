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


bool pos(string a,int num,int len){
for(int i=len-1;i>=0;i--){
    if(a[i]=='?'){num/=10;continue;}
    if((num%10)!=(a[i]-'0'))return false;

    num/=10;


}
return true;


}
int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("Output2.out", "w", stdout);


    string a,b;int i,k;
long long int t;
cin>>t;
//t=1;
for(int y=0;y<t;y++)
		{cin>>a>>b;
		int ans=10000;
		int m1=10000;
		int m2=10000;
		int len=a.size();
		int ma=1;
		for(int h=0;h<len;h++)ma*=10;
		ma-=1;
		for(i=0;i<=ma;i++){
            if(!pos(a,i,len))continue;
            for(k=0;k<=ma;k++){
                if(!pos(b,k,len))continue;
                //cout<<i<<k<<" "<<m1<<" "<<m2<<" ";

                if(abs(i-k)==ans){if(i<m1){m1=i;m2=k;continue;}


                    if(i==m1 && k<m2){m1=i;m2=k;continue;}

                }
            if(abs(i-k)<ans){m1=i;m2=k;ans=abs(i-k);continue;}
            }



		}
		//cout<<m1<<" "<<m2;
        string a1,a2;
        a1="";
        a2="";
        for(int i=0;i<len;i++){a1+='0';a2+='0';}
        int cur=len-1;
        while(m1){a1[cur]='0'+m1%10;
        cur--;
        m1/=10;





        }
        cur=len-1;
        while(m2){a2[cur]='0'+m2%10;
        cur--;
        m2/=10;





        }







		cout<<"Case #"<<y+1<<": ";
		cout<<a1<<" "<<a2;


cout<<"\n";






}




return 0;}

