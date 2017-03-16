#include<bits/stdc++.h>
#include<string>
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
int dp[(1<<18)], n;
string S1[100], S2[100];
int f(int mask)
{

    if(mask == (1<<n)-1)
        return 0;
    if(dp[mask] != -1)
        return dp[mask];
    int i, res;
    map<string, int> F, S;
    F.clear();
    S.clear();

    for(i=0; i<n; i++)
    {
        if(mask&(1<<i))
        {
           // trace2(S1[i], S2[i]);
            F[S1[i]]++;
            S[S2[i]]++;
        }
    }
    res = 0;
    for(i=0; i<n; i++)
    {
        if(mask&(1<<i))
        {
            continue;
        }
            if(F[S1[i]] && S[S2[i]])
            {

                res = max(res, 1+f(mask^(1<<i)));
            }
            else
            {
                res = max(res, f(mask^(1<<i)));
            }

    }
    return dp[mask] = res;
}
void eval()
{
    int i;
    cin>>n;
    setN(dp);
    for(i=0; i<n; i++)
    {
        cin>>S1[i]>>S2[i];
    }

    cout<<f(0)<<"\n";
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
