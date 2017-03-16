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
ll big = 1000000007ll;

ll n,p;
ll T;


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


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ll  z,a,b,c,x,y;
	ll c1,c2,c3,c4,c5;
    ll ans;

	string output = "";

	cin >> T;

	for(c3 = 0; c3 < T; c3++){
        string s;
        cin >> s;

        char last = 'B';
        string s2 = "";
        for(c1 = 0; c1 < s.length(); c1++){
            if(s[c1] != last){s2 += s[c1];}
            last = s[c1];
        }
        ans = 0;
        for(c1 = 0; c1 < s2.length()-1; c1++){
            ans++;
        }
        if(s2[s2.length()-1] == '-'){ans++;}
        output += "Case #" + nts(c3+1) + ": " + nts(ans) + "\n";
	}


    cout << output;


	return 0;
}
