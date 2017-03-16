#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <utility>
#include <ctime>
#include <limits.h>
using namespace std;

#define BIT(x) __builtin_popcount(x)
#define GI(n) cin >> n;
#define FORn(i,s,f,p) for(int i = s;i<f;i+=p)
#define FOR(i,n) FORn(i,0,n,1)
#define MOD 1000000007
int t, tt;
char A[555],C[30] = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
    //freopen ("in.txt","r",stdin);    
    //freopen ("out.txt","w",stdout);
    /*scanf("%s",A);
    scanf("%s",B); 
    for(int i = 0 ; A[i]; i++)
     C[A[i]-'a'] = B[i];
   printf("%s",C);*/
     
    scanf("%d",&t);tt = 1 ;
     gets(A);
    while(t--){
     printf("Case #%d: ",tt++);   
     gets(A);
     
     for(int i = 0 ; A[i] ; i++)
      if(A[i] == ' ')
       printf(" ");
      else
       printf("%c",C[A[i]-'a']);
       
     printf("\n");
   }
  return 0;    
}
