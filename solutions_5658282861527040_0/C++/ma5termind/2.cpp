#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ft first
#define sd second
#define VI vector<int>
#define VLL vector<long long int>
#define PII pair<int,int>
#define pb push_back
#define rsz(v,n) v.resize(n)
// input and output
#define scan(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define ll long long int
#define rep(i,x,y) for(i=x;i<y;i++)
#define print(x) printf("%d\n",x)
#define printll(x) printf("%lld\n",x)
#define all(v) v.begin(),v.end()
#define ms(v) memset(v,0,sizeof(v))
#define FOR(i,a,b)  for(i=a;i<b;i++)
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define PIE 3.14159265358979323846264338327950
#ifdef ONLINE_JUDGE
 inline void inp( int &n )
 {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
  }
#else
inline void inp(int &n){
 cin>>n;
}
#endif
int main()
{
	#ifndef ONLINE_JUDGE
	f_in("in.cpp");
	f_out("out");
	#endif

    int t;
    cin>>t;
    for(int T=1;T<=t;T++){

     int A,B,K;

     int count=0;
     cin>>A>>B>>K;
     for(int i=0;i<A;i++){
      for(int j=0;j<B;j++){
       if((i&j)<K) count++;
      }
     }
     cout<<"case #"<<T<<": "<<count<<endl;
    }
	return 0;
}

