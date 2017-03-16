#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;
long long dif(string a, string b){
   long long anum=0;
   long long bnum=0;
   int size = a.size();
   for( int i= 0 ; i < size; i++ ){
      anum*=10;
      bnum*=10;
      anum+=a[i]-'0';
      bnum+=b[i]-'0';
   }
   if( anum>bnum)
   return anum-bnum;
   else return bnum-anum;
}

int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
    string c,j;
    cin >> c >> j;
    int size = c.size();
    string c2=c;
    string j2=j;
    string c3=c;
    string j3=j;
    int lastC=-2;
    int flag=0;
    for( int i = 0 ; i < size; i++ ){
      if( c[i]=='?' && j[i]=='?'){
         if( flag == 0 ){
            c[i]=j[i]='0';
            if(lastC==i-1&&c2[i-1]!='0'){
               c2=c;j2=j;c2[i]='9';c2[i-1]--;
            }
            else{
               c2=c;j2=j;j2[i]='1';
            }
            c3=c;j3=j;c3[i]='1';
         }
         else{
            c2[i]='9',j2[i]='0';
            c3[i]='0',j3[i]='9';
         }
      }
      else if( c[i] =='?' ){
         lastC=i;
         if( flag == 0 ){
            c[i] = j[i];
            if(j[i]!='0'){c2=c;j2=j;c2[i]--;}
            else{c2[i]='9';}
            if(j[i]!='9'){c3=c;j3=j;c3[i]++;}
            else{c3[i]='0';}
         }
         else{
            c2[i]='9';
            c3[i]='0';
         }
      }
      else if( j[i]=='?'){
         if( flag == 0 ){
            j[i]=c[i];
            if( c[i]!='9' ){c2=c;j2=j;j2[i]++;}
            else{ j2[i]='0';}
            if( c[i]!='0' ){c3=c;j3=j;j3[i]--;}
            else{j3[i]='9';}
         }
         else{
            j2[i]='0';
            j3[i]='9';
         }
      }
      else if( flag == 0 ){
         if( c[i] > j[i] ){
            flag = 1;
            c3=c;j3=j;
         }
         else if( j[i] > c[i] ){
            flag = -1;
            c2=c; j2=j;
         }
         else{
            
         }
      }
    }
    if( flag==0 ){
      cout << "Case #" << loop+1 << ": " <<c <<" " << j << endl;
    }
    else{
      c=c2,j=j2;
      int d2 = dif(c2,j2);
      int d3 = dif(c3,j3);
      if( d3 < d2 ||(d3==d2 && c3<c2) || (d3==d2 && c3==c2 && j3 < j2 )){
         c=c3,j=j3;
      }
      cout << "Case #" << loop+1 << ": " <<c <<" " << j << endl;
    }
  }
  return 0;
}
