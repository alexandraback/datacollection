#include<bits/stdc++.h>
#define ll long long int
#define ite iterator
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define ioS ios::sync_with_stdio(false);

using namespace std ;
ll  n,i,j,k,flag,y,r,lo,hi,m,x,cnt,q,z,ans,sum,i1, ans1,ans2;
ll a[5000000],b[5000000],c[5000000];
pair<ll,ll> p[500008] ;

map<string,ll> m1,m2 ;

string s[1000],t[1000] ;



int main(){


freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
cin >> q ; z=1;
while(q--){
ans = 0 ;
 cin >> n ;
 cout << "Case #" << z << ": "  ;z++;
 for(i=0;i<n;i++){
    cin >> s[i] >> t[i] ;
   m1[s[i]]++; m2[t[i]]++ ;
 }
  for(i=0;i<n;i++){
  if(m1[s[i]]>1&&m2[t[i]]>1){ans++;m1[s[i]]--;m2[t[i]]--;}
 }
 cout << ans << endl ;
 m1.clear() ; m2.clear() ;
}

}



