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

ll n;
ll T;

ll divp[11] = {0};

string nts(ll x){
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
    return -1;
}

ll pow(ll a, ll p){
if(p == 0){return 1;}
ll b = pow(a,p/2);
if(p%2 == 0){return b*b;}
else{return b*b*a;}
}




int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ll  z,a,b,c,x,y;
	ll c1,c2,c3,c4,c5;
    ll ans;
    ll k,s;
	string output = "";

	cin >> T;

	for(c3 = 0; c3 < T; c3++){
        cin >> k >> c >> s;
        if(c*s >= k){
            ll nu = 0;
            std::vector<ll> ANS;

            while(nu < k){
            ll last = 0;
            ll dum = 1;
            for(c1 = 0; c1 < c; c1++){
                last = k * last + nu * dum;
                nu++;
                if(nu >= k){dum = 0;}
            }
            ANS.push_back(last);
            }

            output += "Case #" + nts(c3+1) + ": ";
            for(c1 = 0; c1 < ANS.size(); c1++){
                output += nts(ANS[c1]+1) + " ";
            }
            output += "\n";

        }
        else{output += "Case #" + nts(c3+1) + ": IMPOSSIBLE\n";}
	}
    cout << output;
	return 0;
}
