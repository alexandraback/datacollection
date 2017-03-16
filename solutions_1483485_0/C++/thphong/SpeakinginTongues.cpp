/*
ID: duongthan4
LANG: C++
TASK: test
*/
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#define FOR(i,n) for (int i=0;i<n;i++)
#define FORF(i,a,n) for (int i=a;i<=n;i++)
#define FORR(i,n) for (int i=n-1;i>=0;i--)
#define RI(a) scanf("%d", &a);
#define RS(a) scanf("%s", &a);
#define RC(a) scanf("%c", &a);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define INFY 1000000000
#define MAXN 100000
using namespace std;
typedef long long LL;

char x[1000];
char m[255];

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char c;
    int n;
    
m['a']='y';
m['b']='h';
m['c']='e';
m['d']='s';
m['e']='o';
m['f']='c';
m['g']='v';
m['h']='x';
m['i']='d';
m['j']='u';
m['k']='i';
m['l']='g';
m['m']='l';
m['n']='b';
m['o']='k';
m['p']='r';
m['q']='z';
m['r']='t';
m['s']='n';
m['t']='w';
m['u']='j';
m['v']='p';
m['w']='f';
m['x']='m';
m['y']='a';
m['z']='q';
m[' ']=' ';
    
    int TestCase;
    RI(TestCase);
    scanf("%c", &c);
    FOR(i, TestCase){
        n = 0;   
        cout<<"Case #"<<i+1<<": ";
        while(scanf("%c", &c) && c!='\n'){
            printf("%c", m[c]);
        }
        printf("\n");
    }
    
    /*FOR(i, 3){
        n = strlen(x[i]);
        FOR(j, n){
            m[x[i][j]] = x[i+3][j];        
            k[x[i+3][j]] = x[i][j];
        }
    }
    for(c='a'; c<='z'; c++) {
        if(c=='q') cout << "m['" << c <<"']='" << "z" <<"';"<<endl;
        else if(c=='z') cout << "m['" << c <<"']='" << "q" <<"';"<<endl;
        else cout << "m['" << c <<"']='" << m[c] <<"';"<<endl;
    }*/
    return 0;
}
