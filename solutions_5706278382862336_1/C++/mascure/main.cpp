#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
#define MAX_N 20005
#define MAX_Q 100005
#define MAX_M 200005
#define MAXK 100000
#define MAX_V 50005
#define MAX_E 100005
#define MAX_K 10005
#define MAX_X 15
#define MAX_Y 15
#define inf 1000005
using namespace::std;
typedef long long ll;
//辗转相处法求最大公约数
ll gcd(ll a,ll b){
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
string s;
ll a,b;
void solve(){
    int pos=s.find_first_of('/');
    string s1=s.substr(0,pos),s2=s.substr(pos+1,s.length()-pos-1);
    a=stoll(s1),b=stoll(s2);
    ll div=gcd(a, b);
    a/=div;
    b/=div;
    //若
    if (b!=(b&(-b))) {
        cout<<"impossible"<<endl;
        return;
    }
    ll tmp=1;
    while (tmp<=a) {
        tmp<<=1;
    }
    tmp>>=1;
    int ans=0;
    while (tmp<b) {
        tmp<<=1;
        ans++;
    }
    cout<<ans<<endl;
}
int main()
{
	freopen("/Users/mascure/Desktop/A-large.in", "r", stdin);
	freopen("/Users/mascure/Desktop/A-large.out", "w", stdout);
    int caseN;
    cin>>caseN;
    for (int i=1; i<=caseN; i++) {
        cin>>s;
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
