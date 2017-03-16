#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<cassert>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define hash hash_asdjkhasjkdh
#define se second
#define next next_aslkjdhasmnhd
#include<string>
#include <iomanip>
#include <queue>
#include<string>
using namespace std;


int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++){ 
     double c,f,x;
     cin >> c >> f >> x;
     double t1,t2,tt,s;
     s = 2.;
     t1 = x / s;
     t2 = x / (s + f) + c / s;
     tt = 0;
     while (t2 < t1) {
        tt += c / s;
        s += f;
        t1 = x / s;
        t2 = x / (s + f) + c / s;
     }
     cout.precision(7);
     cout.flags(ios::fixed);
     cout << "Case #" << t + 1 << ": " << tt + t1 << endl;
  }
  return 0;
}