#include<bits/stdc++.h>
#define ll long long int
#define ite iterator
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define ioS ios::sync_with_stdio(false);

using namespace std ;
ll  n,i,j,k,t,flag,y,r,lo,hi,m,x,cnt,q,z,ans,sum;
ll a[5000000],b[5000000],c[5000000];
pair<ll,ll> p[500008] ;

map<string,ll> m1 ;

string s1,s2 ;
int main(){
z=1 ;
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
string s[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"} ;
cin >> t  ;
while(t--){
cin >> s1 ;
 for(i=0;i<300;i++){
    a[i] =0 ; b[i] = 0 ;
 }
 for(i=0;i<s1.size();i++){
    a[s1[i]]++;
 }
 b[0]  = a['Z'] ;
 b[2] = a['W'] ;
 b[4] = a['U'] ;
 b[6] = a['X'] ;
 b[8] = a['G'] ;
 b[1] = a['O']-b[2]-b[4]-b[0] ;
 b[3] = a['R']-b[4]-b[0] ;
 b[5] = a['F']-b[4] ;
 b[7] = a['V'] -b[5] ;
 b[9] = a['I']-b[5]-b[6]-b[8] ;
cout << "Case #" << z << ": " ;
 for(i=0;i<10;i++){
    for(j=0;j<b[i];j++){
        cout <<i;
    }
 }
cout << endl ;z++;
}

}


