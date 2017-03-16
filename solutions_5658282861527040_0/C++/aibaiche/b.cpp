#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#define debug
#define lp(i,n) for(int i=0;i<n;i++)
#define lpb(i,n) for(int i=1;i<=n;i++)
#define _max 12
using namespace std;
FILE *fin,*fout = NULL;
int getmax(int a,int b){
  return a>b? a : b;
}
int getmin(int a,int b){
  return a<b?a:b;
}

int t,a,b,k;
   
int main(){

    
    fout= fopen("out.txt","w");
    fin = fopen("b.in","r");
    //fin = fopen("B-large.in","r");

    fscanf(fin,"%d",&t);
    lpb(kk,t){
       fscanf(fin,"%d%d%d",&a,&b,&k);
       long long int x=0;
       for (int i = 0; i < a; ++i)
       {
         for (int j = 0; j <b; ++j)
         {
           if((i&j) < k) x++;
         }
       }
       fprintf(fout,"Case #%d: %lld\n",kk,x);
   
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}



