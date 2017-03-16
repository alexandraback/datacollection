// Vishal Gupta IIIT-H
// novice_3
#include <bits/stdc++.h>
using namespace std;

#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define INF		INT_MAX
#define FOR(i,a,b) 	for(int  i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define FORAB(i,a,b)      for(int i=(int)a; i<=b; i++)
#define PB push_back
#define MP make_pair
#define fill(a,b) memset(a,b,sizeof(a))
#define mod (int)(1e9 + 7)
#define F first
#define S second
typedef long long int LL;
typedef vector <int> VI;
typedef pair < int ,int > PII;
LL dp[32][2][2][2];
vector <int> dA,dB,dC;
vector <int > find_bits(int D){
	vector <int> d(30);
	rep(i,30) d[i]=((D&(1<<i)) ? 1 : 0);
	return d;
}
LL solve(int t, int eqA, int eqB, int eqC)
{
    LL & res = dp[t][eqA][eqB][eqC];
    if (res == -1) {
        res = 0;
        if (t == 0) {
            res = 1;
        } else {
            res = 0;
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    int z = (x & y); 
                    if (    (!eqA || (x <= dA[t-1]) ) 
                         && (!eqB || (y <= dB[t-1]) )
                         && (!eqC || (z <= dC[t-1]) )
                       ) {
                        
                        res += solve(
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
    return res;
}
int main()
{
      int test,testit,A,B,C; 
      cin >> test;
      rep(testit,test){
      	cin >> A >> B >> C;
      	fill(dp,-1);
      	dA=find_bits(A-1);
      	dB=find_bits(B-1);
      	dC=find_bits(C-1);
   		LL ans=solve(30,1,1,1);   
      	printf("Case #%d: %lld\n",testit+1,ans);
      }
      return 0;
}

