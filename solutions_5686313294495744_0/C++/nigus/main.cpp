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

vector<ll> A;
vector<ll> B;

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

ll hash1(string s1){
ll ans = 0;
for(ll c = 0; c < s1.length(); c++){
    ans *= 27;
    ans += ll(s1[c]-64);
    ans %= big;
}
return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ll  z,a,b,c,x,y;
	ll c1,c2,c3,c4,c5;
    ll ans;
    ll k;
	string output = "";

	cin >> T;

	for(c3 = 0; c3 < T; c3++){

            cin >> n;
            map<ll,ll> M1;
            map<ll,ll> M2;
            A.clear();
            B.clear();
            ll m1 = 0;
            ll m2 = 0;
            for(c1 = 0; c1 < n; c1++){
                string s1,s2;
                cin >> s1 >> s2;
                a = hash1(s1);
                if(M1.find(a) == M1.end()){
                    M1[a] = m1;
                    m1++;
                }
                b = M1[a];
                A.push_back(b);

                a = hash1(s2);
                if(M2.find(a) == M2.end()){
                    M2[a] = m2;
                    m2++;
                }
                b = M2[a];
                B.push_back(b);
            }

            ll t = pow(2,n);
ans = 0;
            for(c1 = 0; c1 < t; c1++){

                ll IA[100] = {0};
                ll IB[100] = {0};
                ll II[100] = {0};
                ll c4 = c1;
                for(c2 = 0; c2 < n; c2++){
                    if(c4 % 2 == 1){
                        IA[A[c2]] = 1;
                        IB[B[c2]] = 1;
                        II[c2] = 1;


                    }c4 /= 2;
                }

                bool fail = 0;


                ll siz = 0;

                for(c2 = 0; c2 < n; c2++){


                    if(II[c2] == 0){



                        if(IA[A[c2]] == 0 || IB[B[c2]] == 0){fail = 1;}
                        siz++;
                        /*
                        if(c1 == 3 && c3 == 0){

                            cout << c2 << "\n";
                            cout << IA[A[c2]] << "\n";
                            cout << IB[B[c2]] << "\n";
                             cout << fail << "\n";
                             cout << siz  << "\n";

                        }*/
                    }

                }


                if(fail == 0){ans = max(ans,siz);}




            }

            output += "Case #" + nts(c3+1) + ": " + nts(ans) + "\n";

	}
    cout << output;
	return 0;
}
