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
int a[337],b[335];
string s;
main(){
   // cin.tie(0);
   // ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   int test;
   cin>>test;
   for(int z=1;z<=test;++z){
    cin>>s;
    for(int i=0;i<230;++i)
        a[i]=b[i]=0;
    for(int i=0;i<s.size();++i)
        ++a[s[i]];
   // for(int i='A';i<='Z';++i)cout<<a[i]<<endl;
     while(a['Z']>0){
        --a['Z'];
        --a['E'];
        --a['R'];
        --a['O'];
        ++b[0];
     }
     while(a['G']>0){
        --a['E'];
        --a['I'];
        --a['G'];
        --a['H'];
        --a['T'];
        ++b[8];
     }
     while(a['U']>0){
        --a['F'];
        --a['O'];
        --a['U'];
        --a['R'];
        ++b[4];
     }
     while(a['W']>0){
        --a['T'];
        --a['W'];
        --a['O'];
        ++b[2];
     }
     while(a['X']>0){
        --a['S'];
        --a['I'];
        --a['X'];
        ++b[6];
     }
     while(a['R']>0){
        --a['T'];
        --a['H'];
        --a['R'];
        --a['E'];
        --a['E'];
        ++b[3];
     }

     while(a['O']>0){
        --a['O'];
        --a['N'];
        --a['E'];
        ++b[1];
     }
     while(a['F']>0){
        --a['F'];
        --a['I'];
        --a['V'];
        --a['E'];
        ++b[5];
     }
     while(a['S']>0){
        --a['S'];
        --a['E'];
        --a['V'];
        --a['E'];
        --a['N'];
        ++b[7];
     }
     while(a['I']>0){
        --a['N'];
        --a['I'];
        --a['N'];
        --a['E'];
        ++b[9];
     }
     cout<<"Case #"<<z<<": ";
     for(int i=0;i<10;++i)
        for(int j=0;j<b[i];++j)
         cout<<i;
     cout<<endl;
   }



}

