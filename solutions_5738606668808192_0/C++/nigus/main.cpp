#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;
typedef long long ll;
typedef long double ld;
ll big = 1000000007ll;

ll n,j;
ll T;

ll divp[11] = {0};

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }

ll ctn(char ch){
if(ch == '0'){return 0;}
if(ch == '1'){return 1;}
if(ch == '2'){return 2;}
if(ch == '3'){return 3;}
if(ch == '4'){return 4;}
if(ch == '5'){return 5;}
if(ch == '6'){return 6;}
if(ch == '7'){return 7;}
if(ch == '8'){return 8;}
if(ch == '9'){return 9;}
}


ll pdiv(ll i){
if(i < 4){return 0;}
for(ll c = 2; c < ll(sqrt(i)+1.0); c++){
    if(i % c == 0){return c;}
}
return 0;
}

ll pow(ll a, ll p){
if(p == 0){return 1;}
ll b = pow(a,p/2);
if(p%2 == 0){return b*b;}
else{return b*b*a;}
}

string bin(ll i , ll l){
ll i2 = i;
string s = "";
for(ll c = 0; c < l; c++){
    if(i2 % 2 == 0){s += '0';}
    else{s += '1';}
    i2 /= 2;
}
string s2 = "";
for(ll c = l-1; c >= 0; c--){
    s2 += s[c];
}
return s2;
}

bool test(ll i){
bool yes = 1;
string s = bin(i,n-2);

for(ll c = 2; c < 11; c++){
    ll a = pow(c,n-1) + 1;
    ll x = c;
    for(ll d = 0; d < n-2; d++){
        if(s[n-3-d] == '1'){a += x;}
        x *= c;
    }
    ll b = pdiv(a);
    divp[c] = b;
    if(b == 0){yes = 0;}
}
return yes;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ll  z,a,b,c,x,y;
	ll c1,c2,c3,c4,c5;
    ll ans;

	string output = "";

	cin >> T;
    output += "Case #1: \n";
	for(c3 = 0; c3 < T; c3++){
        cin >> n >> j;
        ll nu = 0;
        for(c1 = 0; c1 < j; c1++){

            while(test(nu) == 0){nu++;}
            output += "1" + bin(nu,n-2) + "1 ";
            for(c2 = 2; c2 < 11; c2++){
                output += nts(divp[c2]) + " ";
            }
            output += "\n";

            nu++;
        }

	}


    cout << output;


	return 0;
}
