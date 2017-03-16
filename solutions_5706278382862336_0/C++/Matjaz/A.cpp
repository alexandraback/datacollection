#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

long long p,q;

bool impossible;


int T;


void normalise(){
     long long P=p;
     long long Q=q;
     long long Qres=1;
     long long Pres=1;
     while (Q%2==0){
           Qres=Qres*2;
           Q=Q/2;
           }
     if (P%Q!=0) impossible=true;     
     Pres=P/Q;
     p=Pres;
     q=Qres;
     }

void solve(int casenumber){
     impossible=false;
     scanf("%I64d/%I64d",&p,&q);
     normalise();
     if (impossible) printf("Case #%d: impossible\n",casenumber);
     if (impossible) return;
     int res=1;
     long long p2=2;
     while (p*p2<q){
           p2=p2*2;
           res++;
           }
     printf("Case #%d: %d\n",casenumber,res);
     }

int main(){
    scanf("%d",&T);
    for (int t=0; t<T;t++){
        solve(t+1);        
        }
    return 0;
    }
