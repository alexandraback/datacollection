#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<deque>
#include<map>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pii (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)

char cha[128];

void process(){
    cha['a'] = 'y'; cha['g'] = 'v'; cha['m'] = 'l'; cha['s'] = 'n'; cha['y'] = 'a';
    cha['b'] = 'h'; cha['h'] = 'x'; cha['n'] = 'b'; cha['t'] = 'w'; cha['z'] = 'q';
    cha['c'] = 'e'; cha['i'] = 'd'; cha['o'] = 'k'; cha['u'] = 'j'; cha[' '] = ' ';
    cha['d'] = 's'; cha['j'] = 'u'; cha['p'] = 'r'; cha['v'] = 'p';
    cha['e'] = 'o'; cha['k'] = 'i'; cha['q'] = 'z'; cha['w'] = 'f';
    cha['f'] = 'c'; cha['l'] = 'g'; cha['r'] = 't'; cha['x'] = 'm';
}

void doit(){
    string s;
    getline( cin ,  s );
    for(int i = 0 ; i < s.length() ; i++) printf("%c",cha[s[i]]);
    printf("\n");
}

int main(){
    process();
    int t;
    scanf("%d",&t);
    string s;
    getline(cin,s);
    for(int i = 1 ; i <= t ; i++){
        printf("Case #%d: ",i);
        doit();
    }
}


