// Author : SAGORIKA DAS
// Google Code Jam
// C. Coin Jam

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<string>
#define ull unsigned long long
#define ll long long
#define F first
#define S second
#define MOD 1000000007
#define inf 1000000006
#define pb push_back
#define MAX 100002
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define CLEAR(a) memset(a,0,sizeof a)
#define pii pair< int , int >
#define piii pair< int , pii >
#define piiii pair< int, piii >
using namespace std;
int d[9];

ll convert(string s,int base){
ll res = 1, b = base;
for(int i=s.size()-2;i>=0;i--){
     if(s[i] == '1') res += b;
     b = b*(ll) (base);
}  
return res;                
}


string add(string s){
       for(int i=s.size()-2;i>=1;i--){
       if(s[i] =='1') s[i] = '0';
       else{
            s[i] = '1';
            break;
            }        
       }
       return s;
       }
       
       bool check(string s){
            REP(i,s.size()){
                           if(s[i] =='0') return false;
                           }
                           return true;
            }
            
int isPrime(ll number,int j) {
    ll i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0){d[j-2] = i; return 0;}
    }
    return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     int T;
     scanf("%d",&T); while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        string s = "1";
        REP(i,n-2) s+='0';
        s+='1';
        printf("Case #1:\n");
        
        while(1){
        
        if(m <=0) break;
        
        
      
        int f = 1;
        for(int j=2;j<=10;j++){
        ll final = convert(s,j);
        if(isPrime(final,j)) {f = 0; break;}
        }
        
        // if s is a jam coin then print 
        if(f == 1){
        cout<<s<<" ";
        REP(i,9) printf("%d ",d[i]);
        printf("\n");
        m--;
        }
       
        // if all bits are set then exit 
        if(check(s))break;
         // add 1 to s
        s = add(s);
        }
        
        }
     
	return 0;
}
