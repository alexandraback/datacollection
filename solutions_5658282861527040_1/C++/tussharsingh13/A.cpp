// Referred to http://apps.topcoder.com/wiki/display/tc/SRM+595 
//LittleElephantAndXor 

#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)


static const int MAX = 30;
 
vector<int> dA, dB, dC;
 
vector<int> digitIt(int D) //extract digits from D
{
    vector<int> dD(MAX);
    for (int i = 0; i < MAX; i++) {
        dD[i] = ( (D & (1<<i)) != 0 );
    }
    return dD;
}
 
long long dp[MAX + 1][2][2][2];
 
long long rec(int t, int eqA, int eqB, int eqC)
{
    long long & res = dp[t][eqA][eqB][eqC];
    if (res == -1) {
        res = 0;
        if (t == 0) {
            res = 1;
        } else {
            res = 0;
            // pick the two bits x, y:
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    int z = x & y; //find z
                    if(t!=1)
                    {
                            // If valid
                            if (    (!eqA || (x <= dA[t-1]) ) 
                                 && (!eqB || (y <= dB[t-1]) )
                                 && (!eqC || (z <= dC[t-1]) )
                               ) {
                                // procceed:
                                res += rec(
                                            t-1,
                                            eqA && (x == dA[t-1] ),
                                            eqB && (y == dB[t-1] ),
                                            eqC && (z == dC[t-1] )
                                          );
                            }
                    }
                    else
                    {
                            // If valid
                            if (    (!eqA || (x < dA[t-1]) ) 
                                 && (!eqB || (y < dB[t-1]) )
                                 && (!eqC || (z < dC[t-1]) )
                               ) {
                                // procceed:
                                res += rec(
                                            t-1,
                                            eqA && (x == dA[t-1] ),
                                            eqB && (y == dB[t-1] ),
                                            eqC && (z == dC[t-1] )
                                          );
                            }
                    }    
                        
                }
            }
        }
    }
    return res;
}
 
long long getNumber(int A, int B, int C)
{
    dA = digitIt(A), dB = digitIt(B), dC = digitIt(C);
    memset(dp, -1, sizeof(dp)); //fill dp table with -1
    return rec(MAX, 1,1,1 );
}

int main()
{
        freopen ("input.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
                int a,b,c;
                cin>>a>>b>>c;
                long long ans=getNumber(a,b,c);
                cout<<"Case #"<<test<<": ";
                cout<<ans<<endl;
                
        }
        
        return 0;
}
