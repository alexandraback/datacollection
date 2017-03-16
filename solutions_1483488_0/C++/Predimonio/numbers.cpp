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
#define N 105

int A , B;
set< pair<int,int> > S;

string toString(int x){
    string s = "";
    while(x > 0){
        s += char(x%10 + '0');
        x/=10;
    }
    reverse(all(s));
    return s;
}

int toint(string x){
    stringstream in(x);
    int p;
    in >> p;
    return p;
}
int ans = 0;
void f(int x){
    if(x < 10) return;
    string s = toString(x);
    for(int i = 1; i < s.length() ; i++){
        if( s[i] == '0' ) continue;
        string a = s.substr( 0 , i ) , b = s.substr( i , s.length() );
        a = b + a;
        if( a[0] == '0' ) continue;
        int p = toint(a);
        if( A <= min(p,x) && max(p,x) <= B && p != x ){
            ans++;
            S.insert( make_pair( min(p,x) , max(p,x) ) );
        }
    }
}

void doit(){
    S.clear();
    ans = 0;
    scanf("%d%d",&A,&B);
    for(int i = A ; i <= B ; i++) f(i);
    cout << S.size() << endl;
}

int main(){
    int tt;
    scanf("%d",&tt);
    for(int i = 1 ; i <= tt ; i++){
        printf("Case #%d: ",i);
        doit();
    }
}
