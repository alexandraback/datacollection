/* Author : Pranav
BITS PILANI Hyderabad Campus */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fr(i,n) for(i=0; i<n; i++)
#define N 100005
#define mo 1000000007
#define f first
#define sc(x) scanf("%lld",&x);
#define pr(x) printf("%lld\n",x);
#define s second
typedef vector<int> vi;
typedef pair <int, int> paint;
typedef long long ll;
ll mod;
ll fastpow(ll a,ll n,ll temp){
    if(n==0)
         return(1);
    if(n==1)
        return((a*temp)%mod);
    if(n&1)
        temp=(temp*a)%mod;return(fastpow((a*a)%mod,n/2,temp));
}
ll gcd(ll a,ll b){if(a==0)return(b);else return(gcd(b%a,a));}
int isPowerOfTwo(ll n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}
int main()
{
    ll t;
    ll num,den,k,j,id=1;
    cin>>t;
    while(t--){
    string numerator, denominator;
     getline(cin, numerator, '/'); //read up to the '/' and store it in numerator. Discard the '/'
     getline(cin, denominator); //read up to the newline and store it in denominator. Discard the '\n'

     num=stoi(numerator);
     den=stoi(denominator);
if(isPowerOfTwo(den)==0){
	cout<<"Case #"<<id<<": impossible"<<endl;id++;continue;
}
     k=log(num)/log(2);
     j=log(den)/log(2);

     cout<<"Case #"<<id<<": "<<j-k<<endl;
id++;
    }



 return 0;
}

