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

string s1;
string s2;

ll pek1[10][10][22];
ll pek2[10][10][22];
ll L,R;
bool dh,kh;

vector<ll> A;
    vector<ll> B;
    vector<ll> C;

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

ll div(ll a, ll b, ll i , ll p1, ll p2){

ll a1 = p1*10 + a;
ll a2 = p2*10 + b;

ll c1 = a;
ll c2 = b;

for(ll c = i+1; c < n; c++){
    a1 *= 10;
    a2 *= 10;
    ll c3,c4;
    if(s1[c] == '?'){c3 = 9;;}
    else{c3 = ctn(s1[c]);}

    if(s2[c] == '?'){c4 = 0;}
    else{c4 = ctn(s2[c]);}

    //pek1[c1][c2][c-1] = c3;
    //pek2[c1][c2][c-1] = c4;

    a1 += c3;
    a2 += c4;
}

L = a1;
R = a2;
return abs(a1-a2);
}

ll konv(ll a, ll b, ll i,ll p1,ll p2){

ll a1 = p1*10 + a;
ll a2 = p2*10 + b;

ll c1 = a;
ll c2 = b;

for(ll c = i+1; c < n; c++){
    a1 *= 10;
    a2 *= 10;
    ll c3,c4;
    if(s1[c] == '?'){c3 = 0;;}
    else{c3 = ctn(s1[c]);}

    if(s2[c] == '?'){c4 = 9;}
    else{c4 = ctn(s2[c]);}

    //pek1[c1][c2][c-1] = c3;
    //pek2[c1][c2][c-1] = c4;

    a1 += c3;
    a2 += c4;
}
L = a1;
R = a2;
return abs(a1-a2);
}


bool comp(ll i, ll j){

if(C[i] == C[j]){

    if(A[i] == A[j]){

        return B[i]<B[j];

    }
    return A[i]<A[j];

}
return C[i] < C[j];
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
            dh = 0;
            kh = 0;
        cin >> s1 >> s2;
        n = s1.length();

        A.clear();
        B.clear();
        C.clear();
        vector<ll> ind;



        for(c1 = 0; c1 < n+1; c1++){


            bool fail = 0;
            ll pre1 = 0;
            ll pre2 = 0;

            for(c2 = 0; c2 < c1; c2++){

                pre1 *= 10;
                pre2 *= 10;

                if(s1[c2] == '?' && s2[c2] != '?'){
                    pre1 += ctn(s2[c2]);
                    pre2 += ctn(s2[c2]);
                }
                if(s1[c2] != '?' && s2[c2] == '?'){
                    pre1 += ctn(s1[c2]);
                    pre2 += ctn(s1[c2]);
                }
                if(s1[c2] != '?' && s2[c2] != '?'){
                    if(s1[c2] == s2[c2]){
                    pre1 += ctn(s1[c2]);
                    pre2 += ctn(s1[c2]);}
                    else{

                        fail = 1;
                        break;
                }

                }



            }

            if(fail == 0){

                    if(c1 == n){
                        A.push_back(pre1);
                        B.push_back(pre2);
                        C.push_back(0);
                    }
                    else{

                        if(s1[c1] != s2[c1] || s1[c1] == '?'){

                            if(s1[c1] == s2[c1]){

                                ll q1 = konv(1,0,c1,pre1,pre2);
                                A.push_back(L);
                                B.push_back(R);
                                C.push_back(q1);
                                q1 = div(0,1,c1,pre1,pre2);
                                A.push_back(L);
                                B.push_back(R);
                                C.push_back(q1);
                            }

                            if(s1[c1] != '?' && s2[c1] != '?'){


                                if(ctn(s1[c1]) > ctn(s2[c1])){
                                ll q1 = konv(ctn(s1[c1]),ctn(s2[c1]),c1,pre1,pre2);
                                A.push_back(L);
                                B.push_back(R);
                                C.push_back(q1);
                                }
                                if(ctn(s1[c1]) < ctn(s2[c1])){
                                ll q1 = div(ctn(s1[c1]),ctn(s2[c1]),c1,pre1,pre2);
                                A.push_back(L);
                                B.push_back(R);
                                C.push_back(q1);
                                }

                            }

                            if(s1[c1] != '?' && s2[c1] == '?'){
                                    ll l1 = ctn(s1[c1]);
                                    if(l1 != 9){

                                        ll q1 = div(l1,l1+1,c1,pre1,pre2);
                                        A.push_back(L);
                                        B.push_back(R);
                                        C.push_back(q1);

                                    }
                                    if(l1 != 0){

                                        ll q1 = konv(l1,l1-1,c1,pre1,pre2);
                                        A.push_back(L);
                                        B.push_back(R);
                                        C.push_back(q1);

                                    }

                            }

                            if(s1[c1] == '?' && s2[c1] != '?'){
                                    ll l1 = ctn(s2[c1]);
                                    if(l1 != 9){

                                        ll q1 = konv(l1+1,l1,c1,pre1,pre2);
                                        A.push_back(L);
                                        B.push_back(R);
                                        C.push_back(q1);

                                    }
                                    if(l1 != 0){

                                        ll q1 = div(l1-1,l1,c1,pre1,pre2);
                                        A.push_back(L);
                                        B.push_back(R);
                                        C.push_back(q1);

                                    }

                            }


                        }


                    }


            }

        }

        for(c1 = 0;c1 <  A.size(); c1++){
            ind.push_back(c1);
        }
        sort(ind.begin() , ind.end() , comp);
        string an1 = nts(A[ind[0]]);
        string an2 = nts(B[ind[0]]);

        while(an1.length() < n){
            an1 = '0'+an1;
        }
        while(an2.length() < n){
            an2 = '0'+an2;
        }
/*
        for(c1 = 0; c1 < A.size(); c1++){

            cout << A[c1] << "    " << B[c1] << "    -   " << C[c1] << "\n";

        }
*/
//cout << an1 << " " << an2 << "\n";
output += "Case #" + nts(c3+1) + ": " + an1 + " " + an2 + "\n";
	}
    cout << output;
	return 0;
}
