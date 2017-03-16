#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
typedef long long tint;
tint sol1[3000000];
tint sol2[3000000];
tint num[32];
int main(){
    ifstream in("gcj.in");
    ofstream out("gcj.out");
    int t; in>>t;
    forn(tc, t){
      forn(i,3000000){sol1[i]=0; sol2[i]=0;}
      out<<"Case #"<< tc+1<<':'<<endl;
      int n; in>>n;
      forn(i,n)in>>num[i];      
      forn(i,n+1){
        vector <int> v;
        v.clear();
        forn(j,n-i)v.pb(0);
        forn(j,i)v.pb(1);
        
        do{
        tint sum=0;
        tint val=0;
        forn(jj,n){
          int j=n-1-jj;
          if(v[j]==1)sum+=num[j];
          val*=2;
          val+=v[j];
          }
        if(sol1[sum]==0){sol1[sum]=val;/*out<<sum<<' '<<val<<endl;*/}
        else {sol2[sum]=val;}
        }while(next_permutation(v.begin(), v.end()));
        }
      forn(i,2000100){
        if(sol1[i]!=0 && sol2[i]!=0){
          tint v1=sol1[i];
          tint v2=sol2[i];
          //out<<v1<<' '<<v2<<endl;
          tint mask = v1^v2;
          //out<<mask<<endl;
          tint res1= mask&v1;
          tint res2= mask&v2;
          //out<<res1<<' '<<res2<<endl;
          tint pos=1;
          forn(j,n+1){if((res1&pos)>0)out<<num[j]<<' ';pos*=2;}
          out<<endl;
          pos=1;
          forn(j,n+1){if((res2&pos)>0)out<<num[j]<<' ';pos*=2;}
          out<<endl;
          i=3000000;
          }
        }  
      }
    }
