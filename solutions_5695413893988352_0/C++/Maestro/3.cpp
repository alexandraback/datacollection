#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define y0 qweasd
#define y1 qasdna
#define left leva
#define right prava
#define next sled
using namespace std;
const int N=3055;
const int inf=1e9;
string s,t;
int q;
int s1,s2;
char a[6],b[6];
int mabs;
bool f(int x,int y,int z){
    int abe=abs(x-y);
    //cout<<x<<' '<<y<<' '<<z<<endl;
    for(int i=0;i<z;++i){
        a[i]=x%10+'0';x/=10;
        b[i]=y%10+'0';y/=10;
    }
    reverse(a,a+z);
    reverse(b,b+z);
    for(int i=0;i<z;++i){
        if(s[i]!='?'&&s[i]!=a[i])return 0;
        if(t[i]!='?'&&t[i]!=b[i])return 0;
    }
    if(abe<mabs){
        mabs=abe;
        return 1;
    }
    return 0;
}
void g(int x,int y,int z){
   // cout<<x<<' '<<y<<' '<<z<<endl;
    for(int i=0;i<z;++i){
        a[i]=x%10+'0';x/=10;
        b[i]=y%10+'0';y/=10;
    }
    reverse(a,a+z);
    reverse(b,b+z);
}
main(){
   // cin.tie(0);
   // ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   int test;
   cin>>test;
   for(int z=1;z<=test;++z){
    mabs=1e5;
     cin>>s>>t;
     int q=s.size();
     int ok=0;
     if(q==1){
        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
        if(f(i,j,1)){
            s1=i;
            s2=j;
        }
     }
     if(q==2){
        for(int i=0;i<100;++i)
            for(int j=0;j<100;++j)
        if(f(i,j,2)){
            s1=i;
            s2=j;
        }
     }
     if(q==3){
        for(int i=0;i<1000;++i)
            for(int j=0;j<1000;++j)
        if(f(i,j,3)){
            s1=i;
            s2=j;
        }
     }




     g(s1,s2,q);
     cout<<"Case #"<<z<<": ";
     for(int i=0;i<q;++i)
        cout<<a[i];
     cout<<' ';
     for(int i=0;i<q;++i)
        cout<<b[i];
     cout<<' ';


     cout<<endl;
   }



}

