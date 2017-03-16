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
string R1, R2;
ll minima, r1, r2;
ll stoll(string A)
{
    ll n, i, res=0;
    n = A.length();
    for(i=0; i<n; i++)
    {
        res = res*10 + (A[i]-'0');
    }
    return res;
}
void SET(string A, string B, int idx, int flag)
{
    ll n, n1, n2, i;
    // A is smaller
    n = A.length();

    if(flag == 0)
    {
        for(i=idx+1; i<n; i++)
        {
            if(A[i] == '?')
            {
                A[i] = '9';
            }
            if(B[i] == '?')
            {
                B[i] = '0';
            }
        }
        n1 = stoll(A);
        n2 = stoll(B);
       // trace2(n1, n2);
        if(abs(n1-n2) < minima)
        {
            minima = abs(n1-n2);
            R1 = A;
            R2 = B;
            r1 = n1;
            r2 = n2;
        }
        else if(abs(n1-n2) == minima)
        {
            if(n1 < r1)
            {
                minima = abs(n1-n2);
                R1 = A;
                R2 = B;
                r1 = n1;
                r2 = n2;
            }
            else
            {
                if(n1 == r1 && n2 < r2)
                {
                    minima = abs(n1-n2);
                    R1 = A;
                    R2 = B;
                    r1 = n1;
                    r2 = n2;
                }
            }
        }
    }
    else
    {
        for(i=idx+1; i<n; i++)
        {
            if(A[i] == '?')
            {
                A[i] = '0';
            }
            if(B[i] == '?')
            {
                B[i] = '9';
            }
        }
        n1 = stoll(A);
        n2 = stoll(B);

        if(abs(n1-n2) < minima)
        {
            minima = abs(n1-n2);
            R1 = A;
            R2 = B;
            r1 = n1;
            r2 = n2;
        }
        else if(abs(n1-n2) == minima)
        {
            if(n1 < r1)
            {
                minima = abs(n1-n2);
                R1 = A;
                R2 = B;
                r1 = n1;
                r2 = n2;
            }
            else
            {
                if(n1 == r1 && n2 < r2)
                {
                    minima = abs(n1-n2);
                    R1 = A;
                    R2 = B;
                    r1 = n1;
                    r2 = n2;
                }
            }
        }
    }
}
void eval()
{
    string S1, S2;
    int n, i, M=0;
    cin>>S1>>S2;
    minima = LLONG_MAX;
    n = S1.length();

    for(i=0; i<n; i++)
    {
        if(M == 0)
        {
            if(S1[i] == S2[i] && S1[i] == '?')
            {
                S1[i] = '0';
                S2[i] = '1';
                SET(S1, S2, i, 0);

                S1[i] = '1';
                S2[i] = '0';
                SET(S1, S2, i, 1);

                S1[i] = '0';
                S2[i] = '0';
            }
            else
            {
                if(S1[i] == '?')
                {
                    S1[i] = ((S2[i]-'0')+9)%10 + '0';
                    SET(S1, S2, i, 0);

                    S1[i] = ((S2[i]-'0')+1)%10 + '0';
                    SET(S1, S2, i, 1);

                    S1[i] = S2[i];
                }
                else if(S2[i] == '?')
                {
                    S2[i] = ((S1[i]-'0')+9)%10 + '0';
                    SET(S1, S2, i, 1);

                    S2[i] = ((S1[i]-'0')+1)%10 + '0';
                    SET(S1, S2, i, 0);

                    S2[i] = S1[i];
                }
                else if(S1[i] == S2[i])
                {

                }
                else
                {
                    if(S1[i] > S2[i])
                    {
                        SET(S1, S2, i, 1);
                    }
                    else
                    {
                        SET(S1, S2, i, 0);
                    }
                    break;
                }
            }
        }
    }
   // trace2(S1, S2);
    SET(S1, S2, i, 0);

    cout<<R1<<" "<<R2<<"\n";
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
