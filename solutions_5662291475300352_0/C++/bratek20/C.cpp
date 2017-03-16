#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   scanf("%d",&t);
   for(int i=1;i<=t;i++){
      int n,d1,d2,m1,m2,h1,h2;
      scanf("%d",&n);
      scanf("%d%d%d",&d1,&h1,&m1);
      if(n==2){
	 scanf("%d%d%d",&d2,&h2,&m2);
      }
      
      if(n==1 && h1==2){
	 m2=m1+1;
	 d2=d1;
      }
      
      if(n==1 && h1==1){
	 printf("Case #%d: 0\n",i);
	 continue;
      }
      
      if(d1>d2){
	 swap(d1,d2);
	 swap(m1,m2);
      }
      if(m1==m2){
	 printf("Case #%d: 0\n",i);
	 continue;
      }
      if(m1<m2){//A>B
	 double A=( (double)m1/360 )* (720-d1);
	 double B=( (double)m2/360 )* (360-d2);
	 if(A>B)
	    printf("Case #%d: 0\n",i);
	 else
	    printf("Case #%d: 1\n",i);
	 continue;
      }
      if(m1>m2){//A<B
	 double A=( (double)m1/360 )* (360-d1);
	 double B=( (double)m2/360 )* (720-d2);
	 if(A<B)
	    printf("Case #%d: 0\n",i);
	 else
	    printf("Case #%d: 1\n",i);
	 continue;
      }
      
   }
   return 0;
}