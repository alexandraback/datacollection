#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

void solve(int por) {
    char C[10000];
    scanf(" %s",C);
    string s=C;
    vector<int> P; P.resize(300,0);
    For(i,s.length()) P[s[i]]++;
    vector<int> res; res.resize(10,0);
    int x=P['Z'];
    res[0]=x; P['Z']-=x; P['E']-=x; P['R']-=x; P['O']-=x;
    x=P['W'];
    res[2]=x; P['T']-=x; P['W']-=x; P['O']-=x;
    x=P['X'];
    res[6]=x; P['S']-=x; P['I']-=x; P['X']-=x;
    x=P['G'];
    res[8]=x; P['E']-=x; P['I']-=x; P['G']-=x; P['H']-=x; P['T']-=x;
    x=P['S'];
    res[7]=x; P['S']-=x; P['E']-=x; P['V']-=x; P['E']-=x; P['N']-=x;
    x=P['V'];
    res[5]=x; P['F']-=x; P['I']-=x; P['V']-=x; P['E']-=x;
    x=P['F'];
    res[4]=x; P['F']-=x; P['O']-=x; P['U']-=x; P['R']-=x;
    x=P['I'];
    res[9]=x; P['N']-=x; P['I']-=x; P['N']-=x; P['E']-=x;
    x=P['N'];
    res[1]=x; P['O']-=x; P['N']-=x; P['E']-=x;
    res[3]=P['T'];
    printf("Case #%d: ",por);
    For(i,res.size()) For(j,res[i]) printf("%d",i); printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    For(i,n) solve(i+1);
}
