#include<bits/stdc++.h>
#define set(p) memset(p,-1,sizeof(p))
#define clr(p) memset(p,0,sizeof(p))
#define ll long long int
#define llu unsigned long long int
#define si(n)					scanf("%d",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n)                                   scanf("%s",n)
#define rep(i,a,n) for(i=(a);i<(n);i++)
#define pii pair<int,int>
#define pb(x) push_back(x)
#define v(x) vector<x>
using namespace std;

int gcd(int a,int b)
{
 int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}


long long int power(long long int x,long long int y)
{
    long long int temp,ty,my;
    long long int mod;
    mod=1000000007;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    ty=(temp%mod)*(temp%mod);
    if (y%2 == 0)
        {

                return ty%mod;
        }
    else
        {
                my=(x%mod)*(ty%mod);
                return my%mod;
        }
}



long long int maxi(long long int a,long long int b)
{
        return a>b?a:b;
}



struct abhi
{
       ll val;
       ll pos;
};

struct abhi brr[100010];

bool cmp(struct abhi x,struct abhi y)
{
        return x.pos<y.pos;
}




string finall;

ll lps[111];
char petrn[111];
char toxt[111];

string initial;

ll L,K,S;

vector<string> v;

void solve1(string str, ll len);
void solve2();
ll solve3();


int main()
{

       freopen("C:\\Users\\ABHISHEK004\\Desktop\\a3.in","r",stdin);
        freopen("C:\\Users\\ABHISHEK004\\Desktop\\ab1.out","w",stdout);


        ll t,i,kk=0;
        cin>>t;

        while(t--)
        {
            kk++;
            v.clear();

            cin >> K >> L >> S;
            cin >> initial;
            cin >> finall;

            solve1("", 0);

            strcpy(petrn, finall.c_str());

            ll maxx = 0;
            ll total = 0;
            ll si=v.size();
            rep(i,0,si)
            {
                strcpy(toxt, v[i].c_str());
                solve2();
                ll fii = solve3();
                total = total + fii;
                maxx = maxi(maxx, fii);
            }

            //printf("%lld\n",maxx);
        //printf("%0.8lf\n",(1.0 * total)/si);

            double aa1=maxx - ((1.0 * total)/si);

            printf("Case #%lld: %0.8lf\n", kk,aa1);
        }

        return 0;
}

void solve2()
{
    lps[0] = 0;
    ll i,k = 0;
    ll len = strlen(petrn);

    for(i = 1;i < len;i++)
    {
        while(k > 0 && petrn[k] != petrn[i])
        {
            k = lps[k-1];
        }

        if(petrn[k] == petrn[i])
        {
            k++;
        }

        lps[i] = k;
    }
}


ll solve3()
{
    ll len = strlen(toxt);
    ll found = strlen(petrn);
    ll i,answer = 0;

    ll q = 0;
    for(i = 0;i < len;i++)
    {
        while(q > 0 && petrn[q] != toxt[i])
        {
            q = lps[q-1];
        }

        if(petrn[q] == toxt[i])
        {
            q++;
        }

        if(q == found)
        {
            answer++;
            q = lps[q-1];
        }
    }

    return answer;
}


void solve1(string str, ll len)
{
    ll i;
    if(len == S)
    {
        v.push_back(str);
        return;
    }
    else
    {
        for(i = 0;i < K;i++)
        {
            string str2 = str+initial[i];
            solve1(str2, len+1);
        }
    }
}

