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
int main()
{
      LL test,A,B,K;
      cin >> test;
      rep(testit,test){
      	cin >> A >> B >> K;
      	LL ans=0;
      	rep(i,A) rep(j,B) if((i&j)<K) ans++;
      	printf("Case #%d: %lld\n",testit+1,ans);
      }
      return 0;
}

