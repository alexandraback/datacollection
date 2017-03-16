#include<bits/stdc++.h>
#define MOD 1000000007

/**
 *  Author : kaspers, Delhi Technological University
 */

#define mp(x,y) make_pair(x,y)
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define pi   3.14159265358979323846264338327950288
#define set0(a) memset(a,0,sizeof(a))
#define setN(a) memset(a,-1,sizeof(a))

using namespace std;

//Util Functions
template<class T> T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<class T> T power(T a,T b){T result=1;while(b>0){if(b&1)	result = result * a;a = a*a;b>>=1;}return result;}
template<class T> T powerMod(T a,T b,T c){T result =1%c;while(b>0){if(b&1)result = (result * a)%c;a = (a*a)%c;b>>=1;}return result;}

typedef long long ll;
ll Pow[22][22];
vector<vector<ll> >res;
ll k, n;
ll convert(ll num, ll base)
{
    int i;
    ll res=0;
    for(i=0; (num>>i) > 0; i++)
    {
        if((num>>i) &1)
        {
            res = res + (Pow[base][i]);
        }
    }
    return res;
}
ll primeTest(ll A)
{
    int i;
    for(i=2; i<min((int)sqrtl(A), (int)17000) ; i++)
    {
        if(A%i == 0)
        {
            return i;
        }
    }
    return -1;
}
bool check(ll num)
{
    vector<ll> temp;
    int i;
    ll factor;

    temp.push_back(convert(num, 10));
    for(i=2; i<=10; i++)
    {
        factor = primeTest(convert(num, i));
        if(factor == -1)
        {
            return 0;
        }
        temp.push_back(factor);
    }
    res.push_back(temp);
    if(res.size() >= k)
    {
        return 1;
    }
    return 0;
}
void call(ll num)
{
    ll i, j;
    for(i=0; i<(1LL<<(n-2)); i++)
    {
        ll temp = num;
        for(j=0; j<(n-2); j++)
        {
            if((i>>j)&(1))
            {
                temp = temp|(1LL<<(j+1));
            }
        }
        if(check(temp))
            return;
    }
}
void eval()
{
    int  i, j;
    ll num;
    cin>>n>>k;
    num = (1LL<<(n-1)) | (1LL);
    call(num);

    for(i=0; i<res.size(); i++)
    {
        for(j=0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{       //freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    	cin.sync_with_stdio(0);
        cout.sync_with_stdio(0);
        int t, j=1, i;
        cin>>t;
        for(j=2; j<=10; j++)
        {
            for(i=0; i<16; i++)
            {
                if(i == 0)
                {
                    Pow[j][i] = 1;
                }
                else
                    Pow[j][i] = Pow[j][i-1] * j;
            }
        }
        j=1;
        while(t--)
        {
            cout<<"Case #"<<j++<<":\n";
            eval();
        }
	return 0;
}
