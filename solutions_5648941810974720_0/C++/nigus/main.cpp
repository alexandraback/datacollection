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
        string s;
        cin >> s;
        ll SF[26] = {0};
        ll NF[10] = {0};
        for(c1 = 0; c1 < s.length(); c1++){
            SF[ll(s[c1])-65]++;
        }

        while(SF[ll('Z')-65] > 0){
                NF[0]++;
                SF[ll('Z')-65]--;
                SF[ll('E')-65]--;
                SF[ll('R')-65]--;
                SF[ll('O')-65]--;
        }

        while(SF[ll('W')-65] > 0){
                NF[2]++;
                SF[ll('T')-65]--;
                SF[ll('W')-65]--;
                SF[ll('O')-65]--;
                //SF[ll('O')-65]--;
        }

        while(SF[ll('U')-65] > 0){
                NF[4]++;
                SF[ll('F')-65]--;
                SF[ll('O')-65]--;
                SF[ll('U')-65]--;
                SF[ll('R')-65]--;
        }

        while(SF[ll('X')-65] > 0){
                NF[6]++;
                SF[ll('S')-65]--;
                SF[ll('I')-65]--;
                SF[ll('X')-65]--;
                //SF[ll('O')-65]--;
        }

        while(SF[ll('G')-65] > 0){
                NF[8]++;
                SF[ll('E')-65]--;
                SF[ll('I')-65]--;
                SF[ll('G')-65]--;
                SF[ll('H')-65]--;
                SF[ll('T')-65]--;
        }

        while(SF[ll('O')-65] > 0){
                NF[1]++;
                SF[ll('O')-65]--;
                SF[ll('N')-65]--;
                SF[ll('E')-65]--;
                //SF[ll('O')-65]--;
        }

        while(SF[ll('H')-65] > 0){
                NF[3]++;
                SF[ll('T')-65]--;
                SF[ll('H')-65]--;
                SF[ll('R')-65]--;
                SF[ll('E')-65]--;
                SF[ll('E')-65]--;
        }

        while(SF[ll('F')-65] > 0){
                NF[5]++;
                SF[ll('F')-65]--;
                SF[ll('I')-65]--;
                SF[ll('V')-65]--;
                SF[ll('E')-65]--;
                //SF[ll('E')-65]--;
        }

        while(SF[ll('V')-65] > 0){
                NF[7]++;
                SF[ll('S')-65]--;
                SF[ll('E')-65]--;
                SF[ll('V')-65]--;
                SF[ll('E')-65]--;
                SF[ll('N')-65]--;
        }

        while(SF[ll('I')-65] > 0){
                NF[9]++;
                SF[ll('N')-65]--;
                SF[ll('I')-65]--;
                SF[ll('N')-65]--;
                SF[ll('E')-65]--;
                //SF[ll('E')-65]--;
        }

        string an = "Case #";
        an += nts(c3+1);
        an += ": ";
        for(c1 = 0; c1 < 10; c1++){
                //cout << c1 << "   " << NF[c1] << "\n";
            while(NF[c1] > 0){an += nts(c1); NF[c1]--;}
        }
        an += "\n";
        output += an;
	}
    cout << output;
	return 0;
}
