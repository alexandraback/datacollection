/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long int LL;
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define R(i,n,k) for(int i=n;i>=k;i--)
string to_str(LL x){ ostringstream o;o<<x;return o.str();}

const LL MAX=10000002LL;
vector<LL> fairSqrNums;

bool isPalindrome(LL n) {
    string s = to_str(n);
    string ss = s;
    reverse(ss.begin(), ss.end());
    return s==ss;
}

bool isFairSqr(LL k) {
    return isPalindrome(k) && isPalindrome(k*k);
}

void preComp() {
    fairSqrNums.clear();
    for(LL i=0; i<MAX; i++)
        if(isFairSqr(i))
            fairSqrNums.push_back(i*i);
}

LL getCount(LL n) {
    if(n==0)    return 0;
    int lft=0, rgt=fairSqrNums.size()-1, md;
    while(rgt-lft>1) {
        md = (lft+rgt)/2;
        if(fairSqrNums[md] > n) rgt = md-1;
        else                    lft = md;
    }
    while(rgt>=lft) {
        if(fairSqrNums[rgt] <= n)   return rgt;
        rgt--;
    }
    return md;
}

int main(){
    preComp();
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        LL a,b;
        cin>>a>>b;
        cout<<getCount(b)-getCount(a-1)<<endl;
    }
    return 0;
}
