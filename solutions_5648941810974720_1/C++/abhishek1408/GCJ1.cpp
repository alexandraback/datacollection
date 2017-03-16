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
char A[] = { 'Z', 'U', 'R', 'H', 'W', 'X', 'S', 'O', 'N', 'V'};
int N[] = { 0, 4, 3, 8, 2, 6, 7, 1, 9, 5};
string C[] = {

    "ZERO",
    "FOUR",
    "THREE",
    "EIGHT",
    "TWO",
    "SIX",
    "SEVEN",
    "ONE",
    "NINE",
    "FIVE"
};
void eval()
{
    string S;
    int n, i, k, j;
    int Hash[100], R[10000];
    set0(Hash);
    set0(R);
    k=0;
    cin>>S;
    n = S.length();
    for(i=0; i<n; i++)
    {
        Hash[S[i]-'A']++;
    }
    for(i=0; i<10; i++)
    {
        while(Hash[A[i]-'A'])
        {
            for(j=0; j<C[i].length(); j++)
            {
                Hash[C[i][j]-'A']--;
            }
            R[k++] = N[i];
        }
    }
    sort(R, R+k);
    for(i=0; i<k; i++)
    {
        cout<<R[i];
    }
    cout<<"\n";
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
