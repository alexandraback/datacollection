#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <iostream>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


using namespace std;

struct frac{
       long long top;
       long long bottom;
       int gen;
};

bool comp(frac a,frac b){
     return (((long double)a.top/(long double)a.bottom)<=(long double)(b.top/(long double)b.bottom));
     
     }

long long gcd ( long long a, long long b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
long long gcdr(long long a,long long b){
     if (a%b==0)return a;
     else return gcd(b,a%b);
     
     }

ifstream fin("A-small-attempt0.in");
ofstream fout("A.out");
int main(){
    
frac one;
frac zero;
one.top = 1;
one.bottom = 1;
one.gen = 0;
zero.top = 0;
zero.bottom = 1;
zero.gen = 1000;
/*vector <frac> list[50];
list[0].push_back(zero);
list[0].push_back(one);
for (int k=0;k<41;k++){
    if (k>0)cout<<k<<"-"<<list[k-1].size()<<endl;
    for (int j=0;j<list[k].size();j++){
        for (int i=0; i<list[k].size();i++){
            
            //cout<<i<<endl;
            frac first = list[k][j];
            frac second = list[k][i];
            if (!comp(first,second))continue;
            if (first.top ==0 && second.top==0){
                          list[k+1].push_back(first);
                          continue;
                          }
            if (first.bottom ==1 && second.bottom==1){
                          list[k+1].push_back(first);
                          continue;
                          }
            bool isone=false;
            bool iszero=false;
            if (first.top == 1 && first.bottom==1 || second.top==1 && second.bottom==1)isone = true;
            if (second.top ==0 || first.top == 0)iszero = true;
            frac temp;
            temp.top = (long long)(first.top*second.bottom + second.top*first.bottom);
            temp.bottom = first.bottom * second.bottom * 2;
            long long val = gcdr(temp.top,temp.bottom);
            temp.top/=val;
            temp.bottom/=val;
            if (isone){
                      temp.gen = 1;
                      }
                      else {
                           temp.gen = min(first.gen,second.gen)+1;
                           }
    list[k+1].push_back(temp);
}
}
}*/
int t;
fin>>t;
long long pow2[50];
pow2[0]=1;
for (int i=1;i<50;i++){
    pow2[i]=pow2[i-1]*2;
}
for (int tests=0;tests<t;tests++){
long long p,q;
char c;
fin>>p>>c>>q;
long long v = gcdr(p,q);
p/=v;
q/=v;
cout<<q<<endl;

int ans = -1;

for (int i=0;i<=40;i++){
    if (q == pow2[i]){
          ans = i;
          break;
          }
          }
          if (ans!=-1){
          int count = 0;
          while (p<q){
                p*=2;
                count ++;
                long long v = gcdr(p,q);
p/=v;
q/=v;
                }
                ans = count;
                }
//int best = 100000000;
/*for (int i =0; i<list[40].size();i++){
    
    if (list[40][i].top==p && list[40][i].bottom==q){
                       if (list[40][i].gen<best)best = list[40][i].gen;
}
    
    
}*/





if (ans!=-1)fout<<"Case #"<<tests+1<<": "<<ans<<endl;
else fout<<"Case #"<<tests+1<<": Impossible"<<endl;

}

//system("pause");
return 0;
}
