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

map<string,ll> m1 ;

string s,t ;

bool f1(){
flag=1;
   if(n==2){
        flag=1;
       for(i1=0;i1<2;i1++){
        if(s[i1]!='?'&&(s[i1]-48)!=a[i1]){
            flag=0;
        }
        if(t[i1]!='?'&&(t[i1]-48)!=b[i1]){
            flag=0;
        }
       }
    if(flag==0){return false ;}
   }
   else if(n==3){
 for(i1=0;i1<3;i1++){
        if(s[i1]!='?'&&(s[i1]-48)!=a[i1]){
            flag=0;
        }
        if(t[i1]!='?'&&(t[i1]-48)!=b[i1]){
            flag=0;
        }
       }
       if(flag==0){return false ;}
   }
return true ;
}

int main(){


freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
cin >> q ; z=1;
while(q--){
 cin >> s >> t;
n = s.size() ;
cout << "Case #" << z << ": " ;z++;
 if(n==1){
  if(s=="?"&&t=="?"){cout << "0 0\n" ;}
  else if(s=="?"){
    cout << t << " " << t <<endl ;
  }
  else if(t=="?"){
    cout << s << " " << s <<endl ;
  }
}
 else if(n==2){
        ans1=10000;ans2=1000;ans=10000;

for(i=0;i<=99;i++){
    for(j=0;j<=99;j++){
        a[1]=i%10 ;a[0]=i/10 ;b[1]=j%10 ;b[0]=j/10 ;
        x = i; y =j;
     if(f1()&&abs(x-y)<ans){
        ans = abs(x-y) ; ans1=x;ans2=y;
     }
    }
}
i = 1 ;
while(i>=0){
        a[i] = ans1%10 ; ans1/=10; b[i] = ans2%10 ; ans2/=10;
    i--;
}
  for(i=0;i<2;i++){
    cout << a[i] ;
  }
  cout << " " ;
  for(i=0;i<2;i++){
    cout << b[i] ;
  }
  cout << endl ;
}
else{
           ans1=10000;ans2=1000;ans=10000;

for(i=0;i<=999;i++){
    for(j=0;j<=999;j++){
        a[2]=i%10 ; a[1] = (i/10)%10 ; a[0]=i/100 ; b[2]=j%10 ; b[1] = (j/10)%10 ; b[0]=j/100 ;
        x = i; y =j;
     if(f1()&&abs(x-y)<ans){
        ans = abs(x-y) ; ans1=x;ans2=y;
     }
    }
}
i = 2 ;
while(i>=0){
        a[i] = ans1%10 ; ans1/=10; b[i] = ans2%10 ; ans2/=10;
    i--;
}
  for(i=0;i<3;i++){
    cout << a[i] ;
  }
  cout << " " ;
  for(i=0;i<3;i++){
    cout << b[i] ;
  }
  cout << endl ;
}

 }


}
