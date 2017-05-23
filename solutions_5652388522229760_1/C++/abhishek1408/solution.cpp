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
int mask;
void check(int A)
{
    while(A>0)
    {
        mask = mask|(1<<(A%10));
        A = A/10;
    }
}

void eval()
{
    ll n, cur, i, maximai=0, maximaval=0;

    cin>>n;

    if(n == 0)
    {
        cout<<"INSOMNIA\n";
        return;
    }
    mask = 0;
    cur = n;
    for(i=1; i<10000000L; i++)
    {
        check(n);
        if(mask == 1023)
        {
            cout<<n<<"\n";
            return;;
        }
        n = n+cur;
    }


}
int main()
{       freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    	cin.sync_with_stdio(0);
        cout.sync_with_stdio(0);
        int t, j=1;
        cin>>t;
        while(t--)
        {
            cout<<"Case #"<<j++<<": ";
            eval();
        }
	return 0;
}
