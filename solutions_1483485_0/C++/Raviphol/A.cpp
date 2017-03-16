/*
LANG: C++
TASK:
author: Raviphol Sukhajoti
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define LIMIT 0.0000001
#define inf 2000000001
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;

#define For(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define Sz(v) v.size()
#define It(v) typeof(v.begin())
#define Forit(it,v) for(It(v) it = v.begin(); it != v.end(); it++)
#define All(v) v.begin(), b.end()
#define getI(n) scanf("%d",&n)
#define getD(n) scanf("%lf",&n)
#define nl cout << endl
#define LL long long

map<char, char> m;

int main(){
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.out","w", stdout);
     
     m['a'] = 'y';
     m['b'] = 'h';
     m['c'] = 'e';
     m['d'] = 's';
     m['e'] = 'o';
     m['f'] = 'c';
     m['g'] = 'v';
     m['h'] = 'x';
     m['i'] = 'd';
     m['j'] = 'u';
     m['k'] = 'i';
     m['l'] = 'g';
     m['m'] = 'l';
     m['n'] = 'b';
     m['o'] = 'k';
     m['p'] = 'r';
     m['q'] = 'z';
     m['r'] = 't';
     m['s'] = 'n';
     m['t'] = 'w';
     m['u'] = 'j';
     m['v'] = 'p';
     m['w'] = 'f';
     m['x'] = 'm';
     m['y'] = 'a';
     m['z'] = 'q';
     m['\n'] = '\n';
     m[' '] = ' ';
          
     int n;
     char waste;
     cin >> n;
     scanf("%c", &waste);
     for(int t = 1; t <= n; t++){
          cout << "Case #" << t << ": ";
          char c;
          do{
               scanf("%c", &c);
               cout << m[c];
          }while(c != '\n');
     }



     //system("pause");
     return 0;
}
